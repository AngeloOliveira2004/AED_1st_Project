#include "Schedule.h"

// Constructor implementation
Schedule::Schedule(std::vector<UC>* ucs) : studentsSchedules(ucs) {
}

// Destructor implementation
Schedule::~Schedule() {
    // Clean up the allocated memory when the Schedule object is destroyed
    delete studentsSchedules;
}

// Add a UC object to the vector
void Schedule::addUC(const UC& uc) {
    studentsSchedules->push_back(uc);
}

// Get a reference to the vector of UC objects
std::vector<UC>& Schedule::getUCs() {
    return *studentsSchedules;
}

// Retrieve a specific UC by index
UC& Schedule::getUC(int index) {
    return studentsSchedules->at(index);
}

// Get the number of UCs in the schedule
size_t Schedule::size() {
    return studentsSchedules->size();
}

void Schedule::populateSchedule(const std::vector<std::pair<std::string, std::string>>& classUcPairs, const std::vector<UC>& allUCs) {

    auto compareByName = [](const UC& uc, const std::string& code) {
        return uc.getUcCode() < code;
    };

    for (const auto& pair : classUcPairs) {
        const std::string& className = pair.first;
        const std::string& ucCode = pair.second;

        // Find all matching UCs
        auto range = std::equal_range(allUCs.begin(), allUCs.end(), compareByName);

        for (auto it = range.first; it != range.second; ++it) {
            // Add each matching UC to the schedule
            studentsSchedules->push_back(*it);
        }
    }
}

