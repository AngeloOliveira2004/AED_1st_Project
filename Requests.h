//
// Created by jose-costa on 10/26/23.
//

#ifndef PROJETO_REQUESTS_H
#define PROJETO_REQUESTS_H

#include "stdafx.h"

class Requests {
private:
    std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules ;
    std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules;
public:

    Requests(std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules_ , std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules_);

    std::vector<std::pair<Student , std::vector<UC>>> getStudentSchedules();
    std::vector<std::pair<Class , std::vector<UC>>> getClassSchedules();

    void setStudentSchedules(std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules_);
    void setClassSchedules(std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules_);

    void SwitchClass(Student& student1 , Class& new_class , Class& ex_class);
    void SwitchUc(Student student1 , UC new_uc , UC ex_uc);
    void AddUC(Student student1 , UC new_uc);
    void RemoveUC(Student student1 , UC ex_uc);
    void RemoveClass(Student student1 , Class ex_class);
    void AddClass(Student student , Class new_class);
};


#endif //PROJETO_REQUESTS_H
