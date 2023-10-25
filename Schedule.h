//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_SCHECULE_H
#define PROJETO_SCHECULE_H

#include "stdafx.h"

class Schedule {
private:

    std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules;
    std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules;

    //cria-se um unico objecto de cada vetor quando for necessário

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule();
    Schedule(std::vector<std::pair<Student, std::vector<UC>>> studentSchedules_,
             std::vector<std::pair<Class, std::vector<UC>>> classSchedules_);

    // Get a reference to the vector of UC objects
    [[nodiscard]]  std::vector<std::pair<Student, std::vector<UC>>> getStudentSchedules() ;
    [[nodiscard]] std::vector<std::pair<Class , std::vector<UC>>> getClassSchedules() ;

    void setStudentSchedules(std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules_);
    void setClassSchedules(std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules_);

    void populateScheduleStudent(Student& student, const std::vector<UC>& allUCs);
    void populateSchedule(Class& class_, const std::vector<UC> allUCs);

    Student FindStudentInSchedules(const std::string& nameToFind);
    Class FindClassInSchedules(const std::string& classCode);
};


#endif //PROJETO_SCHECULE_H
