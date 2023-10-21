//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_SCHECULE_H
#define PROJETO_SCHECULE_H

#include "UC.h"
#include "algorithm"
#include "vector"
#include "unordered_map"

class Schedule {
private:

    std::vector<UC>* studentsSchedules;
    //cria-se um unico objecto de cada vetor quando for necessário

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule(std::vector<UC>* ucs);

    // Destructor to clean up the allocated memory
    ~Schedule();

    // Add a UC object to the vector
    void addUC(const UC& uc);

    // Get a reference to the vector of UC objects
    vector<UC> & getUCs() const;

    // Retrieve a specific UC by index
    UC& getUC(int index);

    // Get the number of UCs in the schedule
    size_t size();

    void populateSchedule(const std::vector<std::pair<std::string, std::string>>& classUcPairs, const std::vector<UC>& allUCs);
};


#endif //PROJETO_SCHECULE_H
