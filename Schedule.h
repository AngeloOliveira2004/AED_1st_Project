//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_SCHECULE_H
#define PROJETO_SCHECULE_H

#include "stdafx.h"

class Schedule {
private:

    std::unordered_map<Student, std::vector<UC>> studentClasses_;
    std::unordered_map<Class, std::vector<UC>> classSchedules_;

    //cria-se um unico objecto de cada vetor quando for necessário

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule();
    Schedule(std::unordered_map<Student, std::vector<UC>> studentClasses_,
             std::unordered_map<Class, std::vector<UC>> classSchedules_);


    // Get a reference to the vector of UC objects
    [[nodiscard]] std::unordered_map<Student, std::vector<UC>> getStudentSchedules();
    [[nodiscard]] std::unordered_map<Class, std::vector<UC>> getClassSchedules();

    void setStudentSchedules(std::unordered_map<Student, std::vector<UC>> studentClasses_);
    void setClassSchedules(std::unordered_map<Class, std::vector<UC>> classSchedules_);

    void FindStudentInSchedules(const std::string &nameToFind, std::unordered_map<Student, std::vector<UC>> &StudentPair);
    void FindClassInSchedules(const std::string& classCode , std::unordered_map<Class, std::vector<UC>>& ClassPair);

    static void sort_by_week_day(std::pair<Student,std::vector<UC>> &a);
    static void sort_by_week_day(std::pair<Class, std::vector<UC>> &a);

    static bool compare_day(const UC &uc1, const UC &uc2);
};


#endif //PROJETO_SCHECULE_H
