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

void Schedule::populateSchedule(const std::vector<std::pair<std::string, std::string>>& classUcPairs, const std::vector<UC> allUCs) {
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
            std::string trmp1 = pair1.first;
            std::string trmp2 = pair1.second;
            std::string trmp3 = uc.getUcCode();
            std::string trmp4 = uc.getRespectiveClass();

            if(uc.getUcCode() == pair1.first && uc.getRespectiveClass() == pair1.second)
            {
                studentsSchedules.push_back(uc);
            }
        }
    }
}



