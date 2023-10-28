//
// Created by angelo on 25-10-2023.
//
#include "stdafx.h"
#include "LoadFIles.h"
#include "Schedule.h"
#include "UI.h"

void UI::loading_stuff(UI &ui) {

    LoadFiles::Load_Student_Classes(students);
    LoadFiles::Load_Uc(ucs);
    LoadFiles::Load_Classes_Per_Uc(classes);

    Class::sort(classes);
    Student::sort(students);

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

    mySchedule.setClassSchedules(ClassSchedules_);
    mySchedule.setStudentSchedules(StudentSchedules_);
}

UI::UI() {
}
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
    cin >> op;
    cout << "\n";
    if(cin.fail()){
        throw invalid_argument("Invalid number, try to use a number between 1 and 2");
    }
    while(op < '1' || op > '2'){
        cout << "Introduce a valid option (1-2): ";
        cin >> op;
        cout << '\n';
    }
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
    cin >> op;
    cout << "\n";
    if(cin.fail()){
        throw invalid_argument("Invalid number, try to use a number between 1 and 7");
    }
    while(op < '1' || op > '7'){
        cout << "Introduce a valid option (1-7): ";
        cin >> op;
        cout << '\n';
    }
    switch(op){
        case '1':
            menu_schedule();
            break;
        case '2':
            menu_students();
            break;
        case '3':
            break;
        case '4':
            break;
        case '5':
            break;
        case '6':
            break;
        case '7':
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
    cin >> op;
    cout << "\n";
    if(cin.fail()){
        throw invalid_argument("Invalid number, try to use a number between 1 and 2");
    }
    while(op < '1' || op > '2'){
        cout << "Introduce a valid option (1-2): ";
        cin >> op;
        cout << '\n';
    }
        switch (op) {
            case '1': { //Não seria má ideia implementar um algoritmo de sort de acordo com o dia
                string student_name;
                clear_screen();
                    cout << "What's the name of the student you would like to consult the schedule about: ";
                    cin >> student_name;
                    cout << endl;
                    std::pair<Student, std::vector<UC>> tempClass;
                    mySchedule.FindStudentInSchedules(student_name, tempClass);
                    mySchedule.sort_by_week_day(tempClass);
                    cout << "Name: " <<  tempClass.first.getName() << " " << "|| UP: " << tempClass.first.getId() <<"\n";
                    for(auto p : tempClass.second) {
                        cout << p.getUcCode() << " " << p.getDate().Day << " " << p.getType() << " " << p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
                    }
                cout << "\n";
                break;
            }
            case '2': { //Não seria má ideia implementar um algoritmo de sort de acordo com o dia
                string class_number;
                clear_screen();
                cout << "What's the number of the class you would like to consult the schedule about: ";
                cin >> class_number;
                cout << endl;
                std::pair<Class, std::vector<UC>> tempClass;
                mySchedule.FindClassInSchedules(class_number, tempClass);
                mySchedule.sort_by_week_day(tempClass);
                cout << "Class: " <<  tempClass.first.getClassCode() << endl;
                for(auto p : tempClass.second) {
                    cout << p.getDate().Day << " " << p.getType() << " " << p.getRespectiveClass() << " " << p.getDate().Duration.first << " " << p.getDate().Duration.second << "\n" ;
                }
                cout << "\n";
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
    cin >> op;
    cout << "\n";
    if(cin.fail()){
        throw invalid_argument("Invalid number, try to use a number between 1 and 3");
    }
    while(op < '1' || op > '3'){
        cout << "Introduce a valid option (1-3): ";
        cin >> op;
        cout << '\n';
    }
    switch(op){
        case '1': {
            string class_number;
            bool classFound = false;
            Class it;
            set<pair<string,int>> StudentsTemp;
            clear_screen();
            cout << "What's the number of the class you would like to consult the students about: ";
            cin >> class_number;
            cout << endl;
            for (const Class& targetClass : classes) {
                if (targetClass.getClassCode() == class_number) {
                    it = targetClass;
                    classFound = true;
                    break;
                }
            }
            if(classFound){
                for(Student &studentSet: students){
                    for(const auto& pair: studentSet.getClassesToUcs()){
                        if(pair.first == class_number){
                            StudentsTemp.insert(make_pair(studentSet.getName(),studentSet.getId()));
                        }
                    }
                }
                it.setStudents(StudentsTemp);
                cout << "Students in class " << it.getClassCode() << ":\n";
                for (const auto& studentInClass : it.getStudents()) {
                    cout <<"Name: " << studentInClass.first << " || UP: " << studentInClass.second << endl;
                }
            }else{
                cout << "The Class you entered is invalid." << endl;
            }
         break;
        }
        case '2':{

        }

    }
}