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

    Schedule schedule;

    std::vector<std::pair<Student , std::vector<UC>>> StudentSchedules_;
    std::vector<std::pair<Class , std::vector<UC>>> ClassSchedules_;

    for(auto class_ : classes)
    {
       ClassSchedules_.push_back(Class::populateSchedule(class_ , ucs));
    }

    for(auto student : students)
    {
        StudentSchedules_.push_back((Student::populateScheduleStudent(student , ucs)));
    }

    schedule.setClassSchedules(ClassSchedules_);
    schedule.setStudentSchedules(StudentSchedules_);


    for(auto pair1 : schedule.getStudentSchedules() )
    {
        cout << pair1.first.getName()<< " " << pair1.first.getId() << "\n";
        for(auto p : pair1.second)
        {
            cout << p.getUcCode() << " " << p.getType() << " " <<p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
        }
        cout << "\n";
    }

    for(auto pair1 : schedule.getClassSchedules())
    {
        cout << pair1.first.getClassCode() << "\n";
        for(auto p : pair1.second)
        {
            cout << p.getUcCode() << " " << p.getType() << " " <<p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
        }
        cout << "\n";
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