#include "stdafx.h"
#include "LoadFIles.h"

int main() {
    std::vector<Student> students;

    LoadFiles::Load_Student_Classes(students);

    for(auto student : students)
    {
        cout << student.getName() << " " << student.getId() << ":" << "\n";

        for(auto p : student.getClassesToUcs())
        {

            cout << p.first << " " << p.second << "\n" ;
        }

        cout << "\n";
    }
}
