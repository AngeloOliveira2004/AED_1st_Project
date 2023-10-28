#include <iostream>
#include <utility>
#include "Schedule.h"

Schedule::Schedule::Schedule() : studentClasses_({}), classSchedules_({}) {};

Schedule::Schedule(std::unordered_map<Student, std::vector<UC>> studentClasses,
                   std::unordered_map<Class, std::vector<UC>> classSchedules)
        : studentClasses_(std::move(studentClasses)), classSchedules_(std::move(classSchedules)) {}

// Get a reference to the unordered map of Student and vector of UC objects O(1)
std::unordered_map<Student, std::vector<UC>> Schedule::getStudentSchedules() {
    return studentClasses_;
}

std::unordered_map<Class, std::vector<UC>> Schedule::getClassSchedules() {
    return classSchedules_;
}

void Schedule::setStudentSchedules(std::unordered_map<Student, std::vector<UC>> studentClasses) {
    studentClasses_ = std::move(studentClasses);
}

void Schedule::setClassSchedules(std::unordered_map<Class, std::vector<UC>> classSchedules) {
    classSchedules_ = std::move(classSchedules);
}



void Schedule::FindStudentInSchedules(const std::string &nameToFind, std::unordered_map<Student, std::vector<UC>> &StudentPair) {
    for (const auto &entry : studentClasses_) {
        if (entry.first.getName() == nameToFind) {
            // Found the student by name
            StudentPair = entry;
            return;
        }
    }
    // Student not found
    std::cerr << "Student not found" << std::endl;
}



void Schedule::FindClassInSchedules(const std::string &classCode, std::pair<Class, std::vector<UC>> &ClassPair) {
    auto it = classSchedules_.find(Class("classname", 0)); // Replace "classname" with the appropriate name of the class constructor.

    if (it != classSchedules_.end()) {
        // Found the class
        ClassPair = *it;
    } else {
        // Class not found
        std::cerr << "Class not found" << std::endl;
    }
}

void Schedule::sort_by_week_day(std::pair<Student, std::vector<UC>> &a) {
    std::sort(a.second.begin(), a.second.end(), compare_day);
}

void Schedule::sort_by_week_day(std::pair<Class, std::vector<UC>> &a) {
    std::sort(a.second.begin(), a.second.end(), compare_day);
}

bool Schedule::compare_day(const UC &uc1, const UC &uc2) {
    std::map<std::string, int> dayMap = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
    if (dayMap[uc1.getDate().Day] != dayMap[uc2.getDate().Day]) {
        return dayMap[uc1.getDate().Day] < dayMap[uc2.getDate().Day];
    } else {
        return uc1.getDate().Duration.first < uc2.getDate().Duration.first;
    }
}
