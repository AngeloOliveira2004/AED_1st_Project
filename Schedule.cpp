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


void Schedule::FindStudentInSchedules(const std::string& nameToFind, std::pair<Student, std::vector<UC>>& StudentPair) {
    auto it = std::lower_bound(StudentSchedules.begin(), StudentSchedules.end(), nameToFind, [](const std::pair<Student, std::vector<UC>>& pair, const std::string& name) {
        return pair.first.getName() < name;
    });

    if (it != StudentSchedules.end() && it->first.getName() == nameToFind) {
        // Found the student by name
        StudentPair = *it;
    } else {
        // Student not found
        std::cerr << "Student not found" << std::endl;
    }
}

void Schedule::FindClassInSchedules(const std::string& classCode, std::pair<Class, std::vector<UC>>& ClassPair) {
    auto compareFunc = [](const std::pair<Class, std::vector<UC>>& pair, const std::string& code) {
        return pair.first.getClassCode() < code;
    };

    auto it = std::lower_bound(ClassSchedules.begin(), ClassSchedules.end(), classCode, compareFunc);

    if (it != ClassSchedules.end() && compareFunc(*it, classCode) == 0) {
        // Found the class
        ClassPair = *it;
    } else {
        // Class not found
        std::cerr << "Class not found" << std::endl;
    }
}
void Schedule::getAttendence(const std::vector<Student>& Students, std::unordered_map<std::string, std::unordered_set<std::string>>& ClassAttendence, std::unordered_map<std::string, int>& UcAttendence) {
    for (Student student : Students) {
        for (const auto& pair : student.getClassesToUcs()) {
            // Update ClassAttendence
            if (ClassAttendence.find(pair.first) != ClassAttendence.end()) {
                if (ClassAttendence[pair.first].find(student.getName()) == ClassAttendence[pair.first].end()) {
                    ClassAttendence[pair.first].insert(student.getName());
                }
            } else {
                ClassAttendence[pair.first] = {student.getName()};
            }
            // Update UcAttendence
            if (UcAttendence.find(pair.second) != UcAttendence.end()) {
                UcAttendence[pair.second] += 1;
            } else {
                UcAttendence[pair.second] = 1;
            }
        }
    }
}


void Schedule::SwitchClassesStudent(Student student1, UC uc1, Student student2, UC uc2) {

    std::pair<Student, std::vector<UC>> studentPair1;
    std::pair<Student, std::vector<UC>> studentPair2;

    FindStudentInSchedules(student1.getName() , studentPair1);
    FindStudentInSchedules(student2.getName() , studentPair2);

    auto it1 = std::find(studentPair1.second.begin(), studentPair1.second.end(), uc1);
    auto it2 = std::find(studentPair2.second.begin(), studentPair2.second.end(), uc2);

    if(it1 == studentPair2.second.end())
    {
        std::cout << "First UC not found , try another one";
    }
    if(it2 == studentPair2.second.end())
    {
        std::cout << "Second UC not found , try another one";
    }
}
