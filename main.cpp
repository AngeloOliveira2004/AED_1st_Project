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

    Class::sort(classes);

    for(Class class_ : classes)
    {
        schedule.populateSchedule(class_, ucs);

        class_.setClassSchedule(&schedule);

    }

    for (auto& student : students) {  // Changed auto to auto& to work on the same student object

        student.setStudentSchedule(nullptr);
        student.populateSchedule(classes);

        cout << student.getName() << " " << student.getId() << "\n";

        for (auto& p : student.getStudentSchedule()->getUCs()) {  // Changed auto to auto&
            cout << p.getUcCode() << " " << p.getType() << " " <<p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
        }
    }
    return 0;
}