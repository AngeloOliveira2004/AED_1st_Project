//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_SCHECULE_H
#define PROJETO_SCHECULE_H

#include "stdafx.h"

class Schedule
{
private:

    std::unordered_map<Student, std::vector<UC>> StudentSchedules;
    std::unordered_map<Class, std::vector<UC>> ClassSchedules;
    std::vector<UC> Ucs;
    std::unordered_map<std::pair<std::string,std::string> , int, PairHash> ucOcupation;
    int Balance;
    int MAX_CAP = 30;

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule() = default;
    Schedule(std::unordered_map<Student, std::vector<UC>> studentClasses_,
             std::unordered_map<Class, std::vector<UC>> classSchedules_);

    // Get a reference to the vector of UC objects
    [[nodiscard]] std::unordered_map<Student, std::vector<UC>> getStudentSchedules();
    [[nodiscard]] std::unordered_map<Class, std::vector<UC>> getClassSchedules();
    [[nodiscard]] int getBalance();

    void setStudentSchedules(std::unordered_map<Student, std::vector<UC>> studentClasses_);
    void setClassSchedules(std::unordered_map<Class, std::vector<UC>> classSchedules_);
    void setBalance(int balance);

    void StudentsInAtLeastNUcs(char n , std::vector<Student> students);
    void CalculateBalance();
    bool FindStudentinSchedule(std::string student_name);
    bool FindClassinSchedule(std::string ClassCode);
    UC FindUC(const UC& targetUC);

    static void sort_by_week_day(std::pair<Student,std::vector<UC>> &a);
    static void sort_by_week_day(std::pair<Class, std::vector<UC>> &a);

    static bool compare_day(const UC &uc1, const UC &uc2);

    void SwitchClass(Student& student1 , Class& new_class, UC& uc);
    void SwitchUc(Student student1 , UC new_uc , UC ex_uc);
    void AddUC(Student student1 , UC new_uc);
    void RemoveUC(Student student1 , UC ex_uc);
    void RemoveClass(Student student1 , Class ex_class);
    void AddClass(Student student , Class new_class);

};


#endif //PROJETO_SCHECULE_H
