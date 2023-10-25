//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_SCHECULE_H
#define PROJETO_SCHECULE_H

#include "stdafx.h"

class Schedule {
private:

    std::pair<Student , std::vector<UC>> StudentSchedules;
    std::pair<Class , std::vector<UC>> ClassSchedules;

    //cria-se um unico objecto de cada vetor quando for necessário

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule(std::pair<Student , std::vector<UC>> studentSchedules_);
    Schedule(std::pair<Class , std::vector<UC>> classSchedules_);

    // Add a UC object to the vector
    void addUC(const UC& uc , bool student);
    void clear(bool student
    );
    // Get a reference to the vector of UC objects
    [[nodiscard]] std::pair<Student , std::vector<UC>> getStudentSchedules() const;
    [[nodiscard]] std::pair<Class , std::vector<UC>> getClassSchedules() const;
    // Retrieve a specific UC by index
    UC& getUC(int index);

    // Get the number of UCs in the schedule
    size_t size();

    void populateScheduleStudent(Student& student, const std::vector<UC>& allUCs);
    void populateSchedule(Class& class_, const std::vector<UC> allUCs);
};


#endif //PROJETO_SCHECULE_H
