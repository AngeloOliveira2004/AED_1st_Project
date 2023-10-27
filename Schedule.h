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
    std::vector<Student> StudentsVector;
    std::vector<Class> ClassesVector;
    //cria-se um unico objecto de cada vetor quando for necessário

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule();
    Schedule(std::vector<std::pair<Student, std::vector<UC>>> studentSchedules_,
             std::vector<std::pair<Class, std::vector<UC>>> classSchedules_);

    // Get a reference to the vector of UC objects
    [[nodiscard]]  std::vector<std::pair<Student, std::vector<UC>>> getStudentSchedules() ;
    [[nodiscard]]  std::vector<std::pair<Class , std::vector<UC>>> getClassSchedules() ;

    void setStudentSchedules(std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules_);
    void setClassSchedules(std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules_);

    void FindStudentInSchedules(const std::string& nameToFind , std::pair<Student , std::vector<UC>>& StudentPair);
    void FindClassInSchedules(const std::string& classCode , std::pair<Class , std::vector<UC>>& ClassPair);
    int FindStudentIndex(const Student& student);
    //All possible requests
    void SwitchClass(Student& student1 , Class& new_class , Class& ex_class);
    void SwitchUc(Student student1 , UC new_uc , UC ex_uc);
    void AddUC(Student student1 , UC new_uc);
    void RemoveUC(Student student1 , UC ex_uc);
    void RemoveClass(Student student1 , Class ex_class);
    void AddClass(Student student , Class new_class);
};


#endif //PROJETO_SCHECULE_H
