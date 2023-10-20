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

Schedule* Student::getStudentSchedule() const {
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

void Student::setStudentSchedule(Schedule* schedule) {
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