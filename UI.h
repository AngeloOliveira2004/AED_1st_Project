//
// Created by angelo on 25-10-2023.
//
#ifndef PROJETO_UI_H
#define PROJETO_UI_H

#include "stdafx.h"
#include "Schedule.h"
#include "Restoring.h"

class UI{
public:
    UI();
    void menu_start();
    static void clear_screen();
    void menu_options();
    void menu_schedule();
    void loading_stuff(UI& ui);
    void menu_students();
    void menu_studentsInNucs();
    void menu_occupation();
    void menu_requests();
    void process_requets(std::vector<std::variant<Student , UC , char>> requests_);
    void menu_requets();
    void save_global_alterations();
    void restore_changes();

    void write_down();
    bool validate_input(char &op, const char lower_bound, const char upper_bound);

private:
    Schedule mySchedule;
    std::vector<Student> students;
    std::vector<Class> classes;
    std::vector<UC> ucs;
    std::vector<Schedule> schedules;
    std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>> AttendancePair;
    bool ChangesMade = false;
    Restoring restore;
    std::vector<Restoring> restore_value;
    std::list<std::vector<std::variant<Student , UC , char>>> requests;

};

#endif //PROJETO_UI_H