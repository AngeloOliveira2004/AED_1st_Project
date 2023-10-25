#include "Class.h"

#include <utility>

// Default constructor
Class::Class() : ClassCode(""), Students(), UCs(){}

// Parameterized constructor
Class::Class(std::string  classCode, const std::vector<std::string>& students, const std::vector<std::string>& ucs)
        : ClassCode(std::move(classCode)), Students(students), UCs(ucs){}

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

void Class::sort(std::vector<Class> &classes)
{
    // Define a local function
    auto compareClassesByName = [](const Class& class1, const Class& class2) {
        return class1.getClassCode() < class2.getClassCode();
    };

    // Use the local function for sorting
    std::sort(classes.begin(), classes.end(), compareClassesByName);
}
