#include <iostream>
#include <utility>
#include "Schedule.h"

// Constructor implementation O(1)
Schedule::Schedule() : StudentSchedules({}) , ClassSchedules({}){}

Schedule::Schedule(std::vector<std::pair<Student, std::vector<UC>>> studentSchedules_,
                    std::vector<std::pair<Class, std::vector<UC>>> classSchedules_) :

        ClassSchedules(std::move(classSchedules_)) , StudentSchedules(std::move(studentSchedules_)) {}


// Get a reference to the vector of UC objects O(1)
std::vector<std::pair<Student, std::vector<UC>>> Schedule::getStudentSchedules() {
    return StudentSchedules;
}

std::vector<std::pair<Class , std::vector<UC>>>  Schedule::getClassSchedules() {
    return ClassSchedules;
}

void Schedule::setStudentSchedules(std::vector<std::pair<Student, std::vector<UC>>> StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

void Schedule::setClassSchedules(std::vector<std::pair<Class, std::vector<UC>>> ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}


Student Schedule::FindStudentInSchedules(const std::string& nameToFind) {
    auto it = std::lower_bound(StudentSchedules.begin(), StudentSchedules.end(), nameToFind, [](const std::pair<Student, std::vector<UC>>& pair, const std::string& name) {
        return pair.first.getName() < name;
    });

    if (it != StudentSchedules.end() && it->first.getName() == nameToFind) {
        // Found the student by name
        return it->first;
    } else {
        // Student not found
        // You can return an empty Student object or handle the case as needed
        return Student();
    }
}



Class Schedule::FindClassInSchedules(const std::string& classCode)
{
    auto compareFunc = [](const std::pair<Class, std::vector<UC>>& pair, const std::string& code) {
        return pair.first.getClassCode() < code;
    };

    auto it = std::lower_bound(ClassSchedules.begin(), ClassSchedules.end(), classCode, compareFunc);

    if (it != ClassSchedules.end() && compareFunc(*it, classCode) == 0) {
        // Found the class
        return it->first;
    } else {
        // Class not found
        // You can return an empty Class object or handle the case as needed
        return Class();
    }
}



