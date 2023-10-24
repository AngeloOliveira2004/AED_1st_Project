#include <iostream>
#include "Schedule.h"

// Constructor implementation
Schedule::Schedule(std::vector<UC> ucs) : studentsSchedules(ucs) {
}

// Add a UC object to the vector
void Schedule::addUC(const UC& uc) {
    studentsSchedules.push_back(uc);
}

// Get a reference to the vector of UC objects
vector<UC> Schedule::getUCs() const {
    return studentsSchedules;
}

// Retrieve a specific UC by index
UC& Schedule::getUC(int index) {
    return studentsSchedules.at(index);
}

// Get the number of UCs in the schedule
size_t Schedule::size() {
    return studentsSchedules.size();
}


void Schedule::populateScheduleStudent(Student& student, const std::vector<UC>& allUCs) {
    studentsSchedules.clear();

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
                    studentsSchedules.push_back(uc);
                }
            }
        }
    }
}



//O(N) complexity where n is the size of allUCs vector
void Schedule::populateSchedule(Class& class_, const std::vector<UC> allUCs) {
    studentsSchedules.clear();

    std::unordered_set<std::string> ucCodesSet(class_.getUCs().begin(), class_.getUCs().end());

    for (const UC& uc : allUCs) {
        if (uc.getUcCode() == class_.getClassCode() && ucCodesSet.count(uc.getRespectiveClass()) > 0) {
            studentsSchedules.push_back(uc);
        }
    }
}
