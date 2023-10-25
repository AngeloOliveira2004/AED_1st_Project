//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_CLASS_H
#define PROJETO_CLASS_H

#include "stdafx.h"

class Class {
private:
    std::string ClassCode;
    std::vector<std::string> Students;
    std::vector<std::string> UCs;

public:
    // Constructors
    Class();
    Class(std::string  classCode, const std::vector<std::string>& students, const std::vector<std::string>& ucs);

    // Getters
    [[nodiscard]] const std::string& getClassCode() const;
    [[nodiscard]] const std::vector<std::string>& getStudents() const;
    [[nodiscard]] const std::vector<std::string>& getUCs() const;

    // Setters
    void setClassCode(const std::string& classCode);
    void setStudents(const std::vector<std::string>& students);
    void setUCs(const std::vector<std::string>& ucs);

    static void sort(std::vector<Class>& classes);
};

#endif //PROJETO_CLASS_H
