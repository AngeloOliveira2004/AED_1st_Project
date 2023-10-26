//
// Created by jose-costa on 10/26/23.
//

#include "Requests.h"

#include <utility>


Requests::Requests(std::vector<std::pair<Student, std::vector<UC>>> StudentSchedules_, std::vector<std::pair<Class, std::vector<UC>>> ClassSchedules_) :

        StudentSchedules(std::move(StudentSchedules_)) , ClassSchedules(std::move(ClassSchedules_)) {}

std::vector<std::pair<Student, std::vector<UC>>> Requests::getStudentSchedules() {
    return std::vector<std::pair<Student, std::vector<UC>>>();
}

std::vector<std::pair<Class, std::vector<UC>>> Requests::getClassSchedules() {
    return std::vector<std::pair<Class, std::vector<UC>>>();
}

void Requests::setStudentSchedules(std::vector<std::pair<Student, std::vector<UC>>> StudentSchedules_) {

}

void Requests::setClassSchedules(std::vector<std::pair<Class, std::vector<UC>>> ClassSchedules_) {

}

void Requests::SwitchClass(Student &student1, Class &new_class, Class &ex_class) {

}

void Requests::SwitchUc(Student student1, UC new_uc, UC ex_uc) {

}

void Requests::AddUC(Student student1, UC new_uc) {

}

void Requests::RemoveUC(Student student1, UC ex_uc) {

}

void Requests::RemoveClass(Student student1, Class ex_class) {

}

void Requests::AddClass(Student student, Class new_class) {

}



