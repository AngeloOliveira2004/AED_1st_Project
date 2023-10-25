#include "stdafx.h"
#include "LoadFIles.h"
#include "Schedule.h"

int main() {
    std::vector<Student> students;
    std::vector<Class> classes;
    std::vector<UC> ucs;
    std::vector<Schedule> schedules;

    LoadFiles::Load_Student_Classes(students);
    LoadFiles::Load_Uc(ucs);
    LoadFiles::Load_Classes_Per_Uc(classes);

    Class::sort(classes);

    for(auto student : students)
    {
        schedules.push_back(Schedule(std::make_pair(student , ucs));
    }


    for(auto class_ : classes)
    {
        //schedule.populateSchedule(class_, ucs);

        //class_.setClassSchedule(schedule);

        cout << class_.getClassCode() << "\n";

        for (auto& p : class_.getUCs()) {
            cout << p;
        }
        cout << "\n";
    }

    for(auto student : students)
    {
        cout << student.getName()<< " " << student.getId() << "\n";
        for(auto uc_ : student.getClassesToUcs())
        {
            cout <<"(" <<uc_.first << "," << uc_.second << ")" << " ";
        }
        cout << "\n\n";
    }
/*
    for(const auto& class_ : classes)
    {

        cout << class_.getClassCode() << "\n";

        for (auto& p : class_.getClassSchedule().getUCs()) {
            cout << p.getUcCode() << " " << p.getType() << " " <<p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
        }
        cout << "\n";
    }
*/
    return 0;
}