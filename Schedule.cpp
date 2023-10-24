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


void Schedule::populateScheduleStudent(Student& student, const std::vector<UC> allUCs) {
    std::unordered_multimap<std::string, UC> ucMap; // Use multimap for multiple UCs with the same key

/*
    // Build the index
    for (const UC& uc : allUCs) {
        ucMap.insert({uc.getRespectiveClass(), uc});
    }

    // Find and append matching UCs
    for (const auto& pair : classUcPairs) {
        const std::string& className = pair.first;
        const std::string& ucName = pair.second;

        // Find UCs matching class name
        auto classRange = ucMap.equal_range(className);
        for (auto it = classRange.first; it != classRange.second; ++it) {

           std::cout << it->first;
            // Check if the UC name also matches
            if (it->second.getUcCode() == ucName) {
                studentsSchedules->push_back(it->second);
            }
        }
    }
    */
    studentsSchedules.clear();
    for(const UC& uc : allUCs )
    {
        for(const auto pair1 : classUcPairs)
        {
            if(uc.getUcCode() == pair1.first && uc.getRespectiveClass() == pair1.second)
            {
                studentsSchedules.push_back(uc);
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
