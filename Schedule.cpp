#include <iostream>
#include <utility>
#include "Schedule.h"

// Constructor implementation O(1)

Schedule::Schedule(std::unordered_map<Student, std::vector<UC>>  studentSchedules_,
                   std::unordered_map<Class, std::vector<UC>>  classSchedules_) :

        ClassSchedules(std::move(classSchedules_)) , StudentSchedules(std::move(studentSchedules_)) {}


// Get a reference to the vector of UC objects O(1)
std::unordered_map<Student, std::vector<UC>> Schedule::getStudentSchedules() {
    return StudentSchedules;
}

std::unordered_map<Class, std::vector<UC>> Schedule::getClassSchedules() {
    return ClassSchedules;
}

std::unordered_map<std::pair<std::string, std::string>, int, PairHash> Schedule::getUcOcupation() {
    return UcOcupation;
}

std::unordered_map<std::string, unordered_set<std::string>> Schedule::getClassAttendance() {
    return ClassAttendance;
}

int Schedule::getBalance() const {
    return Balance;
}

void Schedule::setStudentSchedules(std::unordered_map<Student, std::vector<UC>>  StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

void Schedule::setClassSchedules(std::unordered_map<Class, std::vector<UC>>  ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}

void Schedule::setUcOcupation(initializer_list<unordered_map<pair<std::basic_string<char>, std::basic_string<char>>, int, PairHash>::value_type> UcOcupation_)
{
    UcOcupation = UcOcupation_;
}

void Schedule::setClassAttendance(std::unordered_map<std::string, unordered_set<std::string>> ClassAttendance_)
{
    ClassAttendance = std::move(ClassAttendance_);
}

void Schedule::setBalance(int balance)
{
    Balance = balance;
}


void Schedule::CalculateBalance()
{
    for(auto class_ : ClassSchedules)
    {
        Balance = std::max(static_cast<int>(class_.first.getStudents().size()), Balance);
    }
}

bool Schedule::FindStudentinSchedule(std::string student_name) {

    Student StudentToFind;
    StudentToFind.setName(student_name);

    auto it = StudentSchedules.find(StudentToFind);

    if(it != StudentSchedules.end())
    {
        return true;
    }

    return false;
}

std::unordered_map<Student, std::vector<UC>>::iterator Schedule::FetchStudent(Student StudentToFind)
{
    if(FindStudentinSchedule(StudentToFind.getName()))
    {
        return StudentSchedules.find(StudentToFind);
    }
}

std::unordered_map<Class, std::vector<UC>>::iterator Schedule::FetchClass(Class ClassToFind)
{
    if(FindClassinSchedule(ClassToFind.getClassCode()))
    {
        return ClassSchedules.find(ClassToFind);
    }
}

Student Schedule::FindStudentinSchedulebyID(int ID) {

    for (const auto& student : StudentSchedules) {
        if (student.first.getId() == ID) {
            return student.first;
        }
    }
    return Student();
}

bool Schedule::FindClassinSchedule(std::string ClassCode)
{
    Class ClassToFind;
    ClassToFind.setClassCode(ClassCode);

    auto it = ClassSchedules.find(ClassToFind);

    if(it != ClassSchedules.end())
    {
        return true;
    }

    return false;
}

UC Schedule::FindUC(const UC &targetUC)
{
    int left = 0;
    int right = Ucs.size() - 1;
    UC result;

    while (left <= right) {
        int mid = left + (right - left) / 2;
        const UC& currentUC = Ucs[mid];

        if (currentUC.getUcCode() == targetUC.getUcCode()) {
            result = currentUC;
            return result; // Found the target UC
        }
        if (currentUC.getUcCode() < targetUC.getUcCode()) {
            left = mid + 1; // Target UC is in the right half
        } else {
            right = mid - 1; // Target UC is in the left half
        }
    }

    return result;// Target UC not found
}

bool Schedule::compare_day(const UC &uc1, const UC &uc2){
    std::map<std::string, int> dayMap = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
    if(dayMap[uc1.getDate().Day] != dayMap[uc2.getDate().Day]){
        return dayMap[uc1.getDate().Day] < dayMap[uc2.getDate().Day];
    }else{
        return uc1.getDate().Duration.first < uc2.getDate().Duration.first;
    }
}


void Schedule::StudentsInAtLeastNUcs(char n , std::vector<Student> students)
{
    for(auto pair : StudentSchedules)
    {
        if(pair.first.getClassesToUcs().size() >= n)
        {
            students.push_back(pair.first);
        }
    }
}

void Schedule::SwitchClass(Student &student1, Class &new_class, UC &uc) { //AED na turma 5 pra turma 6

    Class ex_Class;

    for(UC uc_ : Ucs)
    {
        if(uc_.getRespectiveClass() == new_class.getClassCode() && uc_.getUcCode() == uc.getUcCode())
        {
            ex_Class.setClassCode(uc.getRespectiveClass());
            uc = uc_;
        }
    }
    if(FindStudentinSchedule(student1.getName()))
    {
        for(auto uc : StudentSchedules[student1])
        {
            if(Date::Overlaps(uc.getDate() , uc.getDate()))
            {
                std::cerr << "Schedule not compatible with other classes";
                return;
            }
        }
        for(auto uc_ : StudentSchedules[student1])
        {
            if(uc.getUcCode() == uc_.getUcCode())
            {
                uc_ = uc;
                break;
            }
        }
    }

    if(FindClassinSchedule(uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }
        std::unordered_set<string> students = tempCLass.getStudents();
        students.insert(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }
    if(FindClassinSchedule(ex_Class.getClassCode()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_Class.getClassCode())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }
        std::unordered_set<string> students = tempCLass.getStudents();
        students.erase(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }
    UcOcupation[{uc.getUcCode() , ex_Class.getClassCode()}] -= 1;
    UcOcupation[{uc.getUcCode() , new_class.getClassCode()}] += 1;
}

void Schedule::SwitchUc(Student student1, UC new_uc, UC ex_uc)
{

    if(FindStudentinSchedule(student1.getName()))
    {
        for(auto uc : StudentSchedules[student1])
        {
            if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
            {
                std::cerr << "Schedule not compatible with other classes";
                return;
            }
        }
        for(auto uc : StudentSchedules[student1])
        {
            if(uc.getUcCode() == ex_uc.getUcCode())
            {
                uc = new_uc;
                break;
            }
        }
    }

    if(FindClassinSchedule(ex_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }
        std::unordered_set<string> students = tempCLass.getStudents();
        students.erase(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }
    if(FindClassinSchedule(new_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }
        std::unordered_set<string> students = tempCLass.getStudents();
        students.insert(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }
    UcOcupation[{ex_uc.getUcCode() , ex_uc.getRespectiveClass()}] -= 1;
    UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
}

void Schedule::AddUC(Student student1, UC new_uc) {
    if(FindStudentinSchedule(student1.getName()) && student1.getClassesToUcs().size() < 7)
    {
        for(UC uc : StudentSchedules[student1])
        {
            if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
            {
                std::cerr << "Schedule not compatible with other classes";
                return;
            }
        }
        StudentSchedules[student1].push_back(new_uc);
    }

    if(FindClassinSchedule(new_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == new_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }

        std::unordered_set<string> students = tempCLass.getStudents();
        if(students.size() <= MAX_CAP)
        {
            students.insert(student1.getName());
        }

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }

    UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
}

void Schedule::RemoveUC(Student student1, UC ex_uc) {

    if(FindStudentinSchedule(student1.getName()))
    {
        auto& ucVector = StudentSchedules[student1];
        ucVector.erase(std::remove(ucVector.begin(), ucVector.end(), ex_uc), ucVector.end());
        StudentSchedules[student1] = ucVector;
    }

    if(FindClassinSchedule(ex_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }

        std::unordered_set<string> students = tempCLass.getStudents();
        students.erase(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }

    UcOcupation[{ex_uc.getUcCode() , ex_uc.getUcCode()}] -= 1;
}

void Schedule::RemoveClass(Student student1, UC &uc){
    if (FindStudentinSchedule(student1.getName())) {
        auto& studentSchedule = StudentSchedules[student1];
        for (auto it = studentSchedule.begin(); it != studentSchedule.end(); ++it) {
            if (*it == uc) {
                it->setRespectiveClass("EMPTY");
                it->setOccupation(uc.getOccupation() - 1);
                break;
            }
        }
    } else {
        std::cerr << "Student not found in the schedule" << std::endl;
    }
}


void Schedule::AddClass(Student student1, UC &uc, Class &new_class){
    if (FindStudentinSchedule(student1.getName())) {
        auto& studentSchedule = StudentSchedules[student1];
        bool classFound = false;
        for (auto& classSchedule : ClassSchedules) {
            if (classSchedule.first.getClassCode() == new_class.getClassCode()) {
                classFound = true;
                for (const auto& ucInClass : classSchedule.second) {
                    if (ucInClass == uc) {
                        if(ucInClass.getRespectiveClass() == "EMPTY"){
                            uc.setRespectiveClass(new_class.getClassCode());
                            uc.setOccupation(uc.getOccupation() + 1);
                            break;
                        }else{
                            std::cerr << "Student already has a class for this UC" << std::endl;
                        }
                    }
                }
            }
        }
        if (!classFound) {
            std::cerr << "Class not found in the schedule" << std::endl;
        }

    } else {
        std::cerr << "Student not found in the schedule" << std::endl;
    }
}


