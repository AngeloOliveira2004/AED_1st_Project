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
    std::vector<pair<std::string , std::string>> getClassesToUcs() const;

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

    //O(N) complexity where n is the size of allUCs vector
    static std::pair<Student, std::vector<UC>> populateScheduleStudent(Student& student, const std::vector<UC>& allUCs);
};

namespace std {
    template <>
    struct hash<Student> {
        size_t operator()(const Student& student) const {
            size_t idHash = std::hash<int>{}(student.getId());
            size_t nameHash = std::hash<std::string>{}(student.getName());
            return idHash ^ nameHash; // Combine the hashes appropriately
        }
    };
}

#endif //PROJETO__STUDENT_H
