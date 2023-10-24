    #include "Student.h"

    // Default constructor
    Student::Student() : Id(0), Name(""), Year(0), StudentSchedule(nullptr) {}

    // Parameterized constructor
    Student::Student(int id, const std::string& name, char year) : Id(id), Name(name), Year(year), StudentSchedule(nullptr) {}

    // Getter functions
    int Student::getId() const {
        return Id;
    }

    const std::string& Student::getName() const {
        return Name;
    }

    char Student::getYear() const {
        return Year;
    }

    std::vector<pair<std::string , std::string>>  Student::getClassesToUcs() {
        return ClassesToUcs;
    }

    Schedule *Student::getStudentSchedule() const {
        return StudentSchedule;
    }

    // Setters
    void Student::setId(int id) {
        Id = id;
    }

    void Student::setName(const std::string& name) {
        Name = name;
    }

    void Student::setYear(char year) {
        Year = year;
    }

    void Student::setClassesToUcs(const std::vector<pair<std::string, std::string>> ClassesToUcs_)
    {
        ClassesToUcs = ClassesToUcs_;
    }

    void Student::setStudentSchedule(Schedule* schedule)
    {
        StudentSchedule = schedule;
    }

    // Comparison operators
    bool Student::operator>(const Student& other) const {
        return Id > other.Id;
    }

    bool Student::operator<(const Student& other) const {
        return Id < other.Id;
    }

    bool Student::operator==(const Student& other) const {
        return Id == other.Id;
    }

    void Student::sort(std::vector<Student>& students)
    {
        std::sort(students.begin(), students.end(), compareStudentsByID);
    }

    bool Student::compareStudentsByID(const Student &student1, const Student &student2)
    {
        return student1.getId() < student2.getId();
    }

    void Student::populateSchedule(const vector<Class> classes)
    {
        for (const auto& classToUC : ClassesToUcs) {
            const std::string& className = classToUC.first;
            const std::string& ucName = classToUC.second;

            // Binary search for the class name in the sorted vector
            auto it = std::lower_bound(classes.begin(), classes.end(), className,
                                       [](const Class& class_, const std::string& name) {
                                           return class_.getClassCode() < name;
                                       });

            if (it != classes.end() && it->getClassCode() == className) {
                // Class found, append UCs from the class's schedule
                const Schedule* classSchedule = it->getClassSchedule();
                for(const UC& uc : classSchedule->getUCs())
                {
                    if(ucName == uc.getRespectiveClass())
                    {
                        StudentSchedule->addUC(uc);
                    }
                }
            }
        }
    }