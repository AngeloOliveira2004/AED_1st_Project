//
// Created by jose-costa on 10/11/23.
//

#ifndef PROJETO__STUDENT_H
#define PROJETO__STUDENT_H

#include "stdafx.h"

class Student {
private:

    int Id;
    std::string Name;
    std::vector<pair<std::string , std::string>> ClassesToUcs;
    char Year;

public:

    Student();
    Student(int id, const std::string& name, char year);

    int getId() const;
    const std::string& getName() const;
    char getYear() const;
    std::vector<pair<std::string , std::string>> getClassesToUcs();

    // Setter functions
    void setId(int id);
    void setName(const std::string& name);
    void setYear(char year);
    void setClassesToUcs(std::vector<pair<std::string , std::string>> ClassesToUcs_);

    //Quality of life functions
    static void sort(std::vector<Student>& students);
    static bool compareStudentsByID(const Student& student1, const Student& student2);

    //operators overload
    bool operator >(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator ==(const Student& other) const;

    //void populateSchedule(const vector<Class> classes);
};

#endif //PROJETO__STUDENT_H
