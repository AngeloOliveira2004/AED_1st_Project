#include <iostream>
#include <utility>
#include "Schedule.h"

// Constructor implementation O(1)
Schedule::Schedule() : StudentSchedules({}) , ClassSchedules({}){}

Schedule::Schedule(std::vector<std::pair<Student, std::vector<UC>>> studentSchedules_,
                    std::vector<std::pair<Class, std::vector<UC>>> classSchedules_) :

        ClassSchedules(std::move(classSchedules_)) , StudentSchedules(std::move(studentSchedules_)) {}


// Get a reference to the vector of UC objects O(1)
std::vector<std::pair<Student, std::vector<UC>>> Schedule::getStudentSchedules() {
    return StudentSchedules;
}

std::vector<std::pair<Class , std::vector<UC>>>  Schedule::getClassSchedules() {
    return ClassSchedules;
}

void Schedule::setStudentSchedules(std::vector<std::pair<Student, std::vector<UC>>> StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

void Schedule::setClassSchedules(std::vector<std::pair<Class, std::vector<UC>>> ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}


void Schedule::FindStudentInSchedules(const std::string& nameToFind, std::pair<Student, std::vector<UC>>& StudentPair) {
    auto it = std::lower_bound(StudentSchedules.begin(), StudentSchedules.end(), nameToFind, [](const std::pair<Student, std::vector<UC>>& pair, const std::string& name) {
        return pair.first.getName() < name;
    });

    if (it != StudentSchedules.end() && it->first.getName() == nameToFind) {
        // Found the student by name
        StudentPair = *it;
    } else {
        // Student not found
        std::cerr << "Student not found" << std::endl;
    }
}

void Schedule::FindClassInSchedules(const std::string& classCode, std::pair<Class, std::vector<UC>>& ClassPair) {
    auto compareFunc = [](const std::pair<Class, std::vector<UC>>& pair, const std::string& code) {
        return pair.first.getClassCode() < code;
    };

    auto it = std::lower_bound(ClassSchedules.begin(), ClassSchedules.end(), classCode, compareFunc);

    if (it != ClassSchedules.end() && compareFunc(*it, classCode) == 0) {
        // Found the class
        ClassPair = *it;
    } else {
        // Class not found
        std::cerr << "Class not found" << std::endl;
    }
}
//O(n)
int Schedule::FindStudentIndex(const Student &student)
{
    for(int i = 0; i < StudentSchedules.size() ; i++)
    {
        if(StudentSchedules[i].first == student)
        {
            return i;
        }
    }
    return -1;
}

void Schedule::SwitchClass(Student &student1, Class &new_class, Class &ex_class) {
    auto it = std::lower_bound(student1.getClassesToUcs().begin(), student1.getClassesToUcs().end(), ex_class.getClassCode(), [](const std::pair<string , string>& pair, const std::string& name) {
        return pair.first < name;
    });

    if(it == student1.getClassesToUcs().end())
    {
        std::cout << "Class not found";
        return;
    }
/*
    for(auto pair : student1.getClassesToUcs())
    {
        if(pair.first == ex_class.getClassCode())
        {
            pair.first = Clas
        }
    }
*/
}

void Schedule::SwitchUc(Student student1, UC new_uc, UC ex_uc) {
    for(auto pair : student1.getClassesToUcs())
    {
        if(pair.second == ex_uc.getUcCode())
        {
            pair.first = new_uc.getRespectiveClass();
            pair.second = new_uc.getUcCode();
        }
    }

    int index = FindStudentIndex(student1);

    StudentSchedules[index].first = student1;

    for (auto it = StudentSchedules[index].second.begin(); it != StudentSchedules[index].second.end(); ++it) {
        if (*it == ex_uc) {
            // Found a matching UC, erase it and insert the new UC
            it = StudentSchedules[index].second.erase(it);
            StudentSchedules[index].second.insert(it, new_uc);
        }
    }
}

void Schedule::AddUC(Student student1, UC new_uc) {

}

void Schedule::RemoveUC(Student student1, UC ex_uc) {

}

void Schedule::RemoveClass(Student student1, Class ex_class) {

}

void Schedule::AddClass(Student student, Class new_class) {

}


