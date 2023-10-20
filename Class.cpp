#include "Class.h"

// Default constructor
Class::Class() : ClassCode(""), Students(), UCs(), Class_Schedule(nullptr) {}

// Parameterized constructor
Class::Class(const std::string& classCode, const std::vector<std::string>& students, const std::vector<std::string>& ucs, Schedule* classSchedule)
        : ClassCode(classCode), Students(students), UCs(ucs), Class_Schedule(classSchedule) {}

// Getters
const std::string& Class::getClassCode() const {
    return ClassCode;
}

const std::vector<std::string>& Class::getStudents() const {
    return Students;
}

const std::vector<std::string>& Class::getUCs() const {
    return UCs;
}

Schedule* Class::getClassSchedule() const {
    return Class_Schedule;
}

// Setters
void Class::setClassCode(const std::string& classCode) {
    ClassCode = classCode;
}

void Class::setStudents(const std::vector<std::string>& students) {
    Students = students;
}

void Class::setUCs(const std::vector<std::string>& ucs) {
    UCs = ucs;
}

void Class::setClassSchedule(Schedule* classSchedule) {
    Class_Schedule = classSchedule;
}
