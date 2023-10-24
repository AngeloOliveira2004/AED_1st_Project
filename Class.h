//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_CLASS_H
#define PROJETO_CLASS_H

class Schedule;
#include "stdafx.h"

class Class {
private:
    std::string ClassCode;
    std::vector<std::string> Students;
    std::vector<std::string> UCs;
    Schedule* Class_Schedule;

public:
    // Constructors
    Class();
    Class(const std::string& classCode, const std::vector<std::string>& students, const std::vector<std::string>& ucs, Schedule* classSchedule);

    // Getters
    const std::string& getClassCode() const;
    const std::vector<std::string>& getStudents() const;
    const std::vector<std::string>& getUCs() const;
    Schedule* getClassSchedule() const;

    // Setters
    void setClassCode(const std::string& classCode);
    void setStudents(const std::vector<std::string>& students);
    void setUCs(const std::vector<std::string>& ucs);
    void setClassSchedule(Schedule* classSchedule);

    static void sort(std::vector<Class>& classes);
};

#endif //PROJETO_CLASS_H
