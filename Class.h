//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_CLASS_H
#define PROJETO_CLASS_H

#include "stdafx.h"

class Class {
private:
    std::string ClassCode;
    std::set<std::pair<std::string, int>> Students;
    std::vector<std::string> UCs;

public:
    // Constructors
    Class();
    Class(std::string  classCode, const std::set<std::pair<std::string, int>> students, const std::vector<std::string>& ucs);

    // Getters
    [[nodiscard]] const std::string& getClassCode() const;
    [[nodiscard]] const set<pair<string,int>>& getStudents() const;
    [[nodiscard]] const std::vector<std::string>& getUCs() const;

    // Setters
    void setClassCode(const std::string& classCode);
    void setStudents(const set<pair<string,int>>& students);
    void setUCs(const std::vector<std::string>& ucs);

    static void sort(std::vector<Class>& classes);
    bool operator ==(const Class& other) const;
    bool operator<(const Class& other) const;


    //O(N) complexity where n is the size of allUCs vector
    static std::pair<Class, std::vector<UC>> populateSchedule(Class& class_, const std::vector<UC>& allUCs);
};

#endif //PROJETO_CLASS_H
