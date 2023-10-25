#include <iostream>
#include "Schedule.h"

// Constructor implementation
Schedule::Schedule(std::pair<Class, std::vector<UC>> classSchedules_) :
    ClassSchedules(classSchedules_) {}


Schedule::Schedule(std::pair<Student, std::vector<UC>> studentSchedules_) :
    StudentSchedules(studentSchedules_) {}



// Add a UC object to the vector
void Schedule::addUC(const UC& uc , bool student) {
    if(student)
    {
        StudentSchedules.second.push_back(uc);
    }
    else
    {
        ClassSchedules.second.push_back(uc);
    }
}

void Schedule::clear(bool student)
{
    if(student)
    {
        StudentSchedules.second.clear();
    }
    else
    {
        ClassSchedules.second.clear();
    }
}
// Get a reference to the vector of UC objects
std::pair<Student, std::vector<UC>> Schedule::getStudentSchedules() const {
    return std::pair<Student, std::vector<UC>>();
}

std::pair<Class, std::vector<UC>> Schedule::getClassSchedules() const {
    return std::pair<Class, std::vector<UC>>();
}

//O(N) complexity where n is the size of allUCs vector
void Schedule::populateScheduleStudent(Student& student, const std::vector<UC>& allUCs) {
    StudentSchedules.second.clear();

    std::unordered_map<std::string, std::unordered_set<std::string>> ucMap;

    for (const UC& uc : allUCs) {
        ucMap[uc.getUcCode()].insert(uc.getRespectiveClass());
    }

    for (const auto& pair1 : student.getClassesToUcs()) {
        const std::string& ucCode = pair1.first;
        const std::string& ucClass = pair1.second;

        if (ucMap.count(ucCode) > 0 && ucMap[ucCode].count(ucClass) > 0) {
            for (const UC& uc : allUCs) {
                if (uc.getUcCode() == ucCode && uc.getRespectiveClass() == ucClass) {
                    StudentSchedules.second.push_back(uc);
                }
            }
        }
    }
}

//O(N) complexity where n is the size of allUCs vector
void Schedule::populateSchedule(Class& class_, const std::vector<UC> allUCs) {
    ClassSchedules.second.clear();

    std::unordered_set<std::string> ucCodesSet(class_.getUCs().begin(), class_.getUCs().end());

    for (const UC& uc : allUCs) {
        if (uc.getUcCode() == class_.getClassCode() && ucCodesSet.count(uc.getRespectiveClass()) > 0) {
            ClassSchedules.second.push_back(uc);
        }
    }
}




