#include "Student.h"

// Default constructor
Student::Student() : Id(0), Name("") {}

// Parameterized constructor
Student::Student(int id, const std::string& name, char year) : Id(id), Name(name) {}

// Getter functions
int Student::getId() const {
    return Id;
}

const std::string& Student::getName() const {
    return Name;
}

std::vector<pair<std::string , std::string>>  Student::getClassesToUcs() const {
    return ClassesToUcs;
}

// Setters
void Student::setId(int id) {
    Id = id;
}

void Student::setName(const std::string& name) {
    Name = name;
}

void Student::setClassesToUcs(const std::vector<pair<std::string, std::string>> ClassesToUcs_)
{
    ClassesToUcs = ClassesToUcs_;
}

// Comparison operators
bool Student::operator>(const Student& other) const {
    return Id > other.Id;
}

bool Student::operator<(const Student& other) const {
    return Id < other.Id;
}

bool Student::operator==(const Student& other) const {
    return Name == other.Name;
}

void Student::sort(std::vector<Student>& students)
{
    std::sort(students.begin(), students.end(), compareStudentsByID);
}

bool Student::compareStudentsByID(const Student &student1, const Student &student2)
{
    return student1.getName() < student2.getName();
}

std::pair<Student, std::vector<UC>> Student::populateScheduleStudent(Student &student, const std::vector<UC> &allUCs)
{
    std::unordered_map<std::string, std::unordered_set<std::string>> ucMap;

    std::pair<Student, std::vector<UC>> Result;
    Result.first = student;

    for (const UC& uc : allUCs) {
        ucMap[uc.getUcCode()].insert(uc.getRespectiveClass());
    }

    for (const auto& pair1 : student.getClassesToUcs()) {
        const std::string& ucCode = pair1.second;
        const std::string& ucClass = pair1.first;

        if (ucMap.count(ucCode) > 0 && ucMap[ucCode].count(ucClass) > 0) {
            for (const UC& uc : allUCs) {
                if (uc.getUcCode() == ucCode && uc.getRespectiveClass() == ucClass) {
                    Result.second.push_back(uc);
                }
            }
        }
    }
    return Result;
}