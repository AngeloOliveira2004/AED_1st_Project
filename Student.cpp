#include "Student.h"

// Default constructor
Student::Student() : Id(0), Name(""), Year(0), StudentSchedule(nullptr) {}

// Parameterized constructor
Student::Student(int id, const std::string& name, char year) : Id(id), Name(name), Year(year), StudentSchedule(nullptr) {}

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

void Student::setStudentSchedule(Schedule* schedule) {
    StudentSchedule = schedule;
}
