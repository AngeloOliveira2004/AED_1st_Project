//
// Created by jose-costa on 10/11/23.
//

#ifndef PROJETO__STUDENT_H
#define PROJETO__STUDENT_H

#include "Schecule.h"

class Student {
private:

    int Id;
    std::string Name;
    std::vector<pair<std::string , std::string>> ClassesToUcs;
    char year;
    Schecule* schedule;

public:

    // Constructors
    Student();
    Student(int Id_, std::string   Name_ , std::list<UC>  Ucs_,std::list<Class> Classes_);

    // Getters
    int GetId() const;
    std::string GetName() const;
    std::list<UC>  GetUcs() const;
    std::list<Class> GetClasses() const;

    // Setters
    void SetId(int id);
    void SetName(const std::string& name);
    void SetUcs(const std::list<UC> & ucs);
    void Setclasses(std::list<Class>& classes_);

    // Custom comparison function to sort by name and id
    static bool CompareByID(const Student& a, const Student& b);
    static bool CompareByName(const Student& a, const Student& b);
    bool operator >(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator ==(const Student& other) const;
};

#endif //PROJETO__STUDENT_H
