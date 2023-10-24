#include "stdafx.h"
#include "LoadFIles.h"

int main() {
    std::vector<Student> students;
    std::vector<Class> classes;
    std::vector<UC> ucs;

    LoadFiles::Load_Student_Classes(students);
    LoadFiles::Load_Uc(ucs);
    LoadFiles::Load_Classes_Per_Uc(classes);
    Schedule schedule(ucs);
/*
    for (auto& student : students) {  // Changed auto to auto& to work on the same student object


        //schedule.populateSchedule(student.getClassesToUcs(), ucs);

        student.setStudentSchedule(&schedule);

        cout << student.getName() << " " << student.getId() << "\n";

        for (auto& p : student.getStudentSchedule()->getUCs()) {  // Changed auto to auto&
            cout << p.getUcCode() << " " << p.getType() << " " <<p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
        }
    }
*/

        for(Class class_ : classes)
        {
            schedule.populateSchedule(class_, ucs);

            class_.setClassSchedule(&schedule);

            cout << class_.getClassCode() << ": \n";

            for (auto& p : class_.getClassSchedule()->getUCs()) {  // Changed auto to auto&
                cout << p.getUcCode() << " " << p.getType() << " " <<p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
            }
            cout << "\n";
        }
    return 0;
}