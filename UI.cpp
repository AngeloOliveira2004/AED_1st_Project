//
// Created by angelo on 25-10-2023.
//
#include "stdafx.h"
#include "LoadFIles.h"
#include "Schedule.h"
#include "UI.h"

void UI::loading_stuff(UI &ui) {

    LoadFiles::Load_Student_Classes(students,AttendancePair);
    LoadFiles::Load_Uc(ucs);
    LoadFiles::Load_Classes_Per_Uc(classes);

    Class::sort(classes);
    Student::sort(students);

    std::unordered_map<Student, std::vector<UC>> StudentSchedules_;
    std::unordered_map<Class, std::vector<UC>> ClassSchedules_;

    for(auto class_ : classes)
    {
        ClassSchedules_.insert(Class::populateSchedule(class_ , ucs));
    }

    for(auto student : students)
    {
        StudentSchedules_.insert(Student::populateScheduleStudent(student , ucs));

    }

    mySchedule.setClassSchedules(ClassSchedules_);
    mySchedule.setStudentSchedules(StudentSchedules_);
}

bool UI::validate_input(char &op, const char lower_bound, const char upper_bound) {
    std::string tempValue;
    while(true){
        std::cin >> tempValue;
        std::cout << "\n";
        op = tempValue[0];
        if (std::cin.fail() || tempValue.length() != 1 || !isdigit(op)) {
            std::cout << "Introduce a valid option (" << lower_bound << "-" << upper_bound << "): ";
        }else{
            break;
        }
    }
    while (op < lower_bound || op > upper_bound) {
        std::cout << "Introduce a valid option (" << lower_bound << "-" << upper_bound << "): ";
        std::cin.clear();
        std::cin >> op;
    }
    return true;
}

UI::UI() {}

void UI::clear_screen() {
    int i = 0;
    while(i != 100) {
        cout << endl;
        i++;
    }
}

void UI::menu_start() {
    char op;
    cout << "#################################################" << endl
         << "@@@@@ @@@@@  @@ @@ @@@@@  @@@@  @   @ @@    @@@@@" << endl
         << "@@    @@     @@ @@ @@     @   @ @   @ @@    @@   " << endl
         << "@@@@@ @@     @@@@@ @@@@@  @   @ @   @ @@    @@@@@" << endl
         << "   @@ @@     @@ @@ @@     @   @ @   @ @@    @@   " << endl
         << "@@@@@ @@@@@  @@ @@ @@@@@  @@@@  @@@@@ @@@@@ @@@@@" << endl
         << "#################################################" << endl << '\n'
         << "Welcome to the schedule maker, what would you like to do?" << endl
         << "1. Proceed to the application" << endl
         << "2. Close the application" << endl
         << "Insert the number: " ;
    validate_input(op,'1','2');
    switch(op){
        case '1':
                menu_options();
            break;
        case '2':
            cout << "Thanks for using our schedule app!" << endl << "\n"
                 << "Made by: " << endl
                 << "Ângelo Oliveira || 202207798" << endl
                 << "José Costa      || 202207871" << endl
                 << "Bernardo Sousa  || 202206009" << endl;
            this_thread::sleep_for(chrono::seconds(2)); // Espera 2 segundos antes de fechar o terminal
            exit(0);

    }
}

void UI::menu_options() {
    char op;
    clear_screen();
    cout << "What option would you like to choose?" << endl << '\n'
         << "1. Consult schedule" << endl
         << "2. Consult students" << endl
         << "3. Consult the number of students registered in at least n UCs" << endl
         << "4. Consult occupation" << endl
         << "5. Consult the UCs with the greatest number of students" << endl
         << "6. Update registrations" << endl
         << "7. Return to main menu" << endl << endl
         << "Insert the number: ";
    validate_input(op,'1','7');
    switch(op){
        case '1':
            menu_schedule();
            break;
        case '2':
            menu_students();
            break;
        case '3':
            menu_studentsInNucs();
            break;
        case '4':
            menu_occupation();
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
            clear_screen();
            menu_options();
            break;
    }
}

void UI::menu_schedule(){
    char op;
    clear_screen();
    cout << "Which schedule would you like to consult?" <<'\n'
         << "1. Consult schedule of a Student" << endl
         << "2. Consult schedule of a Class" << endl << endl << endl << endl << endl << endl << endl << '\n'
         << "Insert the number: ";
    validate_input(op,'1','2');
        switch (op) {
            case '1': { //Não seria má ideia implementar um algoritmo de sort de acordo com o dia
                clear_screen();
                char op_sort;
                cout << "Would you like to search it by Name or by ID" << endl
                     << "1.Name" << endl
                     << "2.ID" << endl << endl << endl << endl << endl << endl << endl << '\n'
                     << "Insert the number: ";
                validate_input(op_sort,'1','2');
                    switch(op_sort){
                        case '1':{
                            cout << "What's the name of the student you would like to consult the schedule: ";
                            string student_name;
                            cin >> student_name;
                            cout << endl;
                            if(mySchedule.FindStudentinSchedule(student_name)){
                                Student studentForSchedule;
                                studentForSchedule.setName(student_name);

                                auto it = mySchedule.FetchStudent(studentForSchedule);

                                std::vector<UC> m = it->second;
                                std::sort(m.begin(),m.end(),Schedule::compare_day);
                                cout << "Name: " <<  it->first.getName() << " " << "|| UP: " <<  it->first.getId() <<"\n";
                                for(auto p : m)
                                {
                                    cout << p.getUcCode() << " " << p.getDate().Day << " " << p.getType() << " " << p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
                                }
                            } else {
                                cout << "Student not found in the schedule." << endl;
                            }
                         break;
                        }
                        case '2':{
                            cout << "What's the ID of the student you would like to consult the schedule: ";
                            int student_ID;
                            cin >> student_ID;
                            cout << endl;
                            Student tempStudent = mySchedule.FindStudentinSchedulebyID(student_ID);
                            if(tempStudent.getName() != ""){
                                std::vector<UC> m = mySchedule.getStudentSchedules()[tempStudent];
                                std::sort(m.begin(),m.end(),Schedule::compare_day);
                                cout << "Name: " <<  tempStudent.getName() << " " << "|| UP: " << tempStudent.getId() <<"\n";
                                for(auto p : m)
                                {
                                    cout << p.getUcCode() << " " << p.getDate().Day << " " << p.getType() << " " << p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
                                }
                            } else {
                                cout << "Student not found in the schedule." << endl;
                            }
                         break;
                        }
                    }
             break;
            }
            case '2': {
                string class_number;
                clear_screen();
                cout << "What's the number of the class you would like to consult the schedule: ";
                cin >> class_number;
                cout << endl;
                if(mySchedule.FindClassinSchedule(class_number)){
                    Class ClassToFind;
                    ClassToFind.setClassCode(class_number);

                    auto it = mySchedule.FetchClass(ClassToFind);

                    std::vector<UC> m  = it->second;
                    std::sort(m.begin(),m.end(),Schedule::compare_day);

                    cout << "Class: " <<  it->first.getClassCode() << endl;
                    for(auto p : m) {
                        cout << p.getDate().Day << " " << p.getType() << " " << p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
                    }
                    cout << "\n";

                } else {
                    cout << "Class not found in the schedule." << endl;
                }
                break;
            }
        }
}

void UI::menu_students(){
    char op;
    clear_screen();
    cout << "Which schedule would you like to consult?" <<'\n'
         << "1. Consult students within a given Class" << endl
         << "2. Consult students within a given UC" << endl
         << "3. Consult students within a given Year" << endl << endl << endl << endl << endl << endl << '\n'
         << "Insert the number: ";
    validate_input(op,'1','3');
    switch(op){
        case '1': {
            string class_number;
            set<pair<string,int>> StudentsTemp;
            clear_screen();
            cout << "What's the Class Code of class you would like to consult the students: ";
            cin >> class_number;
            cout << endl;
            if(mySchedule.FindClassinSchedule(class_number)){
                cout << "Students in class " << class_number << ":\n";
                for (const auto& studentInClass : AttendancePair.first[class_number]) {
                    Student studentprint;
                    studentprint.setName(studentInClass);
                    auto it = mySchedule.FetchStudent(studentprint);
                    cout <<"Name: " << it->first.getName() << " || UP: " << it->first.getId() << endl;
                }
            }else{
                cout << "The Class you entered is invalid." << endl;
            }
         break;
        }
        case '2':{
            string ucCode;
            bool ucFound = false;
            set<pair<string,int>> StudentsTemp;
            clear_screen();
            cout << "What's the UC you would like to consult the students: ";
            cin >> ucCode;
            cout << endl;
            cout << "Students in " << ucCode << ":\n";
            for (const auto& targetUC : ucs) {
                if (targetUC.getUcCode() == ucCode) {
                    ucFound = true;
                    break;
                }
            }
                for(Student &studentSet: students){
                    for(const auto& pair: studentSet.getClassesToUcs()){
                        if(pair.second == ucCode){
                            cout <<"Name: " << studentSet.getName() << " || UP: " << studentSet.getId() << endl;
                        }
                        break;
                    }
                }
            break;
        }
        case '3':{
            char year_number;
            clear_screen();
            cout << "What's the Year you would like to consult the students: ";
            cin >> year_number;
            cout << endl;
            while(year_number < '1' || year_number > '3'){
                cout << "Introduce a valid Year (1-3): ";
                cin >> op;
                cout << '\n';
            }
            cout << "Students in " << year_number << "º year" << ":\n";
            for(Student &studentSet: students){
                for(const auto& pair: studentSet.getClassesToUcs()){
                    if(pair.first[0] == year_number){
                        cout <<"Name: " << studentSet.getName() << " || UP: " << studentSet.getId() << endl;
                        break;
                    }
                }
            }
        }
    }
}


void UI::menu_studentsInNucs(){
    char op;
    clear_screen();
    cout << "Which is the minimum amount of UCs that a student should have?" <<'\n'
         << "Insert the number: ";
    validate_input(op, '1' ,'7');

    std::vector<Student> studentsInNucs;
    mySchedule.StudentsInAtLeastNUcs(op, studentsInNucs);

    for(Student student : studentsInNucs){
        cout <<"Name: " << student.getName() << " || UP: " << student.getId() << endl;
    }
}

void UI::menu_occupation(){
    char op;
    clear_screen();
    cout << "What occupation would you like to know?" <<'\n'
         << "1. Consult Class occupation" << endl
         << "2. Consult Year occupation" << endl
         << "3. Consult UC occupation" << endl << endl << endl << endl << endl << endl << '\n'
         << "Insert the number: ";
    validate_input(op, '1' ,'3');
    switch(op){
        case '1':{
            char op_sort;
            cout << "Which way would you like to sort it?" <<'\n'
                 << "1. Sort by UC" << endl
                 << "2. Sort by ascending order" << endl
                 << "3. Sort by descending order" << endl << endl << endl << endl << endl << endl << '\n'
                 << "Insert the number: ";
                 validate_input(op_sort, '1' ,'3');
                 switch(op_sort){
                     case '1':{
                         for(auto &pair : AttendancePair.second){
                             cout << "UC:" << pair.first.first << " || " << "Class:" << pair.first.second << " || " << "Occupation:" <<  " " << pair.second << endl;
                         }
                     }
                 }



        }
    }
}