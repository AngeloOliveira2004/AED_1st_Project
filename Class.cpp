#include "Class.h"

#include <utility>

// Default constructor
Class::Class() : ClassCode(""), Students(), UCs(){}

// Parameterized constructor
Class::Class(std::string  classCode, const std::unordered_set<std::string>& students, const std::vector<std::string>& ucs)
        : ClassCode(std::move(classCode)), Students(students), UCs(ucs){}

// Getters
const std::string& Class::getClassCode() const {
    return ClassCode;
}

const std::unordered_set<std::string>& Class::getStudents() const {
    return Students;
}

const std::vector<std::string>& Class::getUCs() const {
    return UCs;
}


// Setters
void Class::setClassCode(const std::string& classCode) {
    ClassCode = classCode;
}

void Class::setStudents(const std::unordered_set<std::string>& students) {
    Students = students;
}

void Class::setUCs(const std::vector<std::string>& ucs) {
    UCs = ucs;
}

bool Class::operator<(const Class &other) const
{
    return this->ClassCode < other.ClassCode;
}

bool Class::operator==(const Class &other) const
{
    return this->ClassCode == other.ClassCode;
}

//O(N) complexity where n is the size of allUCs vector
std::pair<Class, std::vector<UC>> Class::populateSchedule(Class &class_, const std::vector<UC>& allUCs)
{
    std::pair<Class, std::vector<UC>> Result;
    Result.first = class_;

    std::unordered_set<std::string> ucCodesSet(class_.getUCs().begin(), class_.getUCs().end());

    for (const UC& uc : allUCs) {
        if (uc.getRespectiveClass() == class_.getClassCode() && ucCodesSet.count(uc.getUcCode()) > 0) {
            Result.second.push_back(uc);
        }
    }
    return Result;
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