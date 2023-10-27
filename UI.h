//
// Created by angelo on 25-10-2023.
//
#ifndef PROJETO_UI_H
#define PROJETO_UI_H

#include "stdafx.h"
#include "Schedule.h"

class UI{
public:
    UI();
    void menu_start();
    static void clear_screen();
    void menu_options();
    void menu_schedule();
    void loading_stuff(UI& ui);
    void menu_students();
private:
    Schedule mySchedule;
    std::vector<Student> students;
    std::vector<Class> classes;
    std::vector<UC> ucs;
    std::vector<Schedule> schedules;

};

#endif //PROJETO_UI_H