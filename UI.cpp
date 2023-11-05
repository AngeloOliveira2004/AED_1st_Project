#include "stdafx.h"
#include "LoadFiles.h"
#include "Schedule.h"
#include "UI.h"

/**
     * @brief Default constructor for the UI class.
     */
UI::UI() {}

/**
     * @brief Load necessary data and initialize schedules.
     */
void UI::loading_stuff(UI &ui) {
    // Load student classes and attendance information.
    LoadFiles::Load_Student_Classes(students, AttendancePair);

    // Load UCs.
    LoadFiles::Load_Uc(ucs);

    // Load classes per UC.
    LoadFiles::Load_Classes_Per_Uc(classes);

    // Sort the classes and students.
    Class::sort(classes);
    Student::sort(students);

    // Initialize maps to store schedules.
    std::unordered_map<Student, std::vector<UC>> StudentSchedules_;
    std::unordered_map<Class, std::vector<UC>> ClassSchedules_;

    // Populate schedules for each class.
    for (auto class_ : classes) {
        ClassSchedules_.insert(Class::populateSchedule(class_, ucs));
    }

    // Populate schedules for each student.
    for (auto student : students) {
        StudentSchedules_.insert(Student::populateScheduleStudent(student, ucs));
    }

    // Set the schedules and attendance information for the UI's schedule.

    mySchedule.setUCs(ucs);
    mySchedule.setClassSchedules(ClassSchedules_);
    mySchedule.setStudentSchedules(StudentSchedules_);
    mySchedule.setClassAttendance(AttendancePair.first);
    mySchedule.setUcOcupation(AttendancePair.second);
    mySchedule.CalculateBalance();
}

/**
     * @brief Validate and get user input within a specified range.
     * @param op Reference to the input character.
     * @param lower_bound The lower bound for valid options.
     * @param upper_bound The upper bound for valid options.
     * @return True if input is valid, otherwise false.
     */
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

/**
     * @brief Clear the screen by printing multiple newline characters.
     */
void UI::clear_screen() {
    int i = 0;
    while(i != 100) {
        cout << endl;
        i++;
    }
}

/**
     * @brief Display the initial menu when starting the application.
     */
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
            char choice;
            cout << "Would you like to save your changes?" << endl
                 << "1.Yes" << endl
                 << "2.No" << endl
                 << "Insert the number: " ;
            validate_input(choice,'1','2');
            if(choice == 1){
                save_global_alterations();
            }
            cout << "Thanks for using our schedule app!" << endl << "\n"
                 << "Made by: " << endl
                 << "Ângelo Oliveira || 202207798" << endl
                 << "José Costa      || 202207871" << endl
                 << "Bernardo Sousa  || 202206009" << endl;
            this_thread::sleep_for(chrono::seconds(2)); // Espera 2 segundos antes de fechar o terminal
            exit(0);

    }
}

/**
     * @brief Display the menu for various application options.
     */
void UI::menu_options() {
    char op;
    clear_screen();
    cout << "What option would you like to choose?" << endl << '\n'
         << "1. Consult schedule" << endl
         << "2. Consult students" << endl
         << "3. Consult the number of students registered in at least n UCs" << endl
         << "4. Consult occupation" << endl
         << "5. Add request" << endl
         << "6. Process requests" << endl
         << "7. Return to a change backup (Only if changes have been made)" << endl
         << "8. Return to main menu" << endl
         << "Insert the number: ";
    validate_input(op,'1','8');
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
            menu_requests();
            break;
        case  '6':
            requests_();
            break;
        case '7':
            restore_changes();
            break;
        case '8':
            clear_screen();
            menu_start();
            break;
    }
}

/**
     * @brief Display the schedule menu and handle schedule consultations.
     */
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
                 << "2.ID" << endl << '\n'
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
                        if(it == mySchedule.getStudentSchedules().end()){
                            std::cout << "Error: Student not found." << std::endl;
                            menu_options();
                        }

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
                if(it == mySchedule.getClassSchedules().end()){
                    std::cout << "Error: Class not found." << std::endl;
                    menu_options();
                }

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
    char trash;
    cout << endl << "Press any button and enter to return to the menu options: ";
    cin >> trash;
    menu_options();
}

/**
     * @brief Display the students menu and handle student-related queries.
     */
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
                auto students_ = mySchedule.getClassAttendance();
                AttendancePair.first[class_number] = students_[class_number];
                for (const auto& studentInClass : AttendancePair.first[class_number]) {
                    Student studentprint;
                    studentprint.setName(studentInClass);
                    auto it = mySchedule.FetchStudent(studentprint);
                    if(it == mySchedule.getStudentSchedules().end()){
                        std::cout << "Error: Student not found." << std::endl;
                        menu_options();
                    }
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

            std::unordered_map<Student, std::vector<UC>> tempMap = mySchedule.getStudentSchedules();
            for(auto pair : tempMap){
                for(const auto uc: pair.second){
                    if(uc.getUcCode() == ucCode){
                        cout <<"Name: " << pair.first.getName() << " || UP: " << pair.first.getId() << endl;
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

            set<string> student_set;
            for(auto pair : mySchedule.getClassAttendance()){
                if(pair.first[0] == year_number)
                {
                    for(auto stu : pair.second)
                    {
                        student_set.insert(stu);
                    }
                }
            }
            for(auto pair : mySchedule.getClassAttendance()){
                if(pair.first[0] != year_number)
                {
                    for(auto stu : pair.second)
                    {
                        student_set.erase(stu);
                    }
                }
            }
            for(auto &studentSet: student_set)
            {
                Student tempStu;
                tempStu.setName(studentSet);
                auto it = mySchedule.FetchStudent(tempStu);
                if(it == mySchedule.getStudentSchedules().end()){
                    std::cout << "Error: Student not found." << std::endl;
                    menu_options();
                }
                cout <<"Name: " << it->first.getName() << " || UP: " << it->first.getId() << endl;
            }
        }
    }
    char trash;
    cout << endl << "Press any button to return to the menu options: ";
    cin >> trash;
    menu_options();
}

/**
     * @brief Display the menu to query students with a minimum number of registered UCs.
     */
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
    char trash;
    cout << endl << "Press any button and enter to return to the menu options: ";
    cin >> trash;
    menu_options();
}

/**
     * @brief Display the occupation menu and handle occupation-related queries.
     */
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
            std::unordered_map<std::pair<std::string,std::string> , int , PairHash> Second = AttendancePair.second;
            std::vector<std::pair<std::pair<std::string, std::string>, int>> sortedVector;
            for (const auto& element : Second) {
                sortedVector.emplace_back(element);
            }

            if (op_sort == '1') {
                std::sort(sortedVector.begin(), sortedVector.end(), [](const std::pair<std::pair<std::string, std::string>, int>& a, const std::pair<std::pair<std::string, std::string>, int>& b) {
                    return a.first.first < b.first.first;});
            } else if (op_sort == '2') {
                std::sort(sortedVector.begin(), sortedVector.end(), [](const std::pair<std::pair<std::string, std::string>, int>& a, const std::pair<std::pair<std::string, std::string>, int>& b) {
                    return a.first.second < b.first.second;});
            } else if (op_sort == '3') {
                std::sort(sortedVector.begin(), sortedVector.end(), [](const std::pair<std::pair<std::string, std::string>, int>& a, const std::pair<std::pair<std::string, std::string>, int>& b) {
                    return a.first.second > b.first.second;});
            }
            for (auto& pair : sortedVector) {
                std::cout << "UC:" << pair.first.first << " || " << "Class:" << pair.first.second << " || " << "Occupation:" << " " << pair.second+1 << std::endl;
            }
            break;
        }
        case '2':{
            char op_sort;
            cout << "Which way would you like to sort it?" <<'\n'
                 << "1. Sort by ascending order" << endl
                 << "2. Sort by descending order" << endl << endl << endl << endl << endl << endl << endl << '\n'
                 << "Insert the number: ";
            validate_input(op_sort, '1' ,'2');
            std::vector<int> YearOccupation = {0,0,0}; // 1º- 2º- 3º;
            /////////////////////////////////////////////////////////////////////////
            for(Student student: students){
                std::vector<bool> YearValidator = {false,false,false}; // 1º- 1 , 2ª- 2 , 3º - 3;
                for(auto &studentClassestoUcs : student.getClassesToUcs()){
                    if(studentClassestoUcs.first[0] == '1'){
                        YearValidator[0] = true;
                    }else if(studentClassestoUcs.first[0] == '2'){
                        YearValidator[1] = true;
                    }else if(studentClassestoUcs.first[0] == '3'){
                        YearValidator[2] = true;
                    }
                }
                if(YearValidator[0] == true){
                    YearOccupation[0]++;
                }
                if(YearValidator[1] == true){
                    YearOccupation[1]++;
                }
                if(YearValidator[2] == true){
                    YearOccupation[2]++;
                }
            }
            if(op_sort == '1') {
                std::cout << "1st Year Occupation: " << YearOccupation[0] << std::endl;
                std::cout << "2nd Year Occupation: " << YearOccupation[1] << std::endl;
                std::cout << "3rd Year Occupation: " << YearOccupation[2] << std::endl;
            }
            else if (op_sort == '2'){
                std::cout << "3rd Year Occupation: " << YearOccupation[2] << std::endl;
                std::cout << "2nd Year Occupation: " << YearOccupation[1] << std::endl;
                std::cout << "1st Year Occupation: " << YearOccupation[0] << std::endl;
            }
            break;
        }
        case '3':{
            char op_sort;
            cout << "Which way would you like to sort it?" <<'\n'
                 << "1. Sort by ascending order" << endl
                 << "2. Sort by descending order" << endl
                 << "3. Sort by occupation" << endl << endl << endl << endl << endl << endl << '\n'
                 << "Insert the number: ";
            validate_input(op_sort, '1' ,'3');
            std::unordered_map<std::pair<std::string,std::string> , int , PairHash> Second = AttendancePair.second;
            std::vector<std::pair<std::pair<std::string, std::string>, int>> sortedVector;
            std::map<std::string,int> valueOcupationUC;
            int valueOcUcwielder = 0;
            int first_time = 1;
            string actualUC;
            for (const auto& element : Second) {
                sortedVector.emplace_back(element);
            }
            std::sort(sortedVector.begin(), sortedVector.end(), [](const std::pair<std::pair<std::string, std::string>, int>& a, const std::pair<std::pair<std::string, std::string>, int>& b) {
                return a.first.first < b.first.first;});
            for(auto &pair : sortedVector){
                if(first_time == 1){
                    actualUC = pair.first.first;
                    first_time = 0;
                }
                if(actualUC != pair.first.first){
                    valueOcupationUC.emplace(make_pair(actualUC,valueOcUcwielder));
                    actualUC = pair.first.first;
                    valueOcUcwielder = 0;
                    valueOcUcwielder += pair.second+1;
                }else{
                    valueOcUcwielder += pair.second+1;
                }
            }
            valueOcupationUC.emplace(make_pair(actualUC,valueOcUcwielder));

            if(op_sort == '1') {
                for (auto & it : valueOcupationUC) {
                    std::cout << "UC:" << it.first << "||" << "Occupation:" << " " << it.second << std::endl;
                }
            }
            else if (op_sort == '2'){
                for (auto it = valueOcupationUC.rbegin(); it != valueOcupationUC.rend(); ++it) {
                    std::cout << "UC:" << it->first << "||" << "Occupation:" << " " << it->second << std::endl;
                }
            }
            else if (op_sort == '3'){
                std::vector<std::pair<std::string, int>> sortedByOccupation(valueOcupationUC.begin(), valueOcupationUC.end());
                std::sort(sortedByOccupation.begin(), sortedByOccupation.end(), [](const std::pair<std::string, int>& a, const std::pair<std::string, int>& b) {
                    return a.second > b.second;
                });
                for (const auto& it : sortedByOccupation) {
                    std::cout << "UC:" << it.first << "||" << "Occupation:" << " " << it.second << std::endl;
                }
            }
            break;
        }
    }
    char trash;
    cout << endl << "Press any button and enter to return to the menu options: ";
    cin >> trash;
    menu_options();
}

/**
     * @brief Display the requests menu and handle user requests for making changes.
     */
void UI::menu_requests() {

    // Prompt user to keep or discard changes if any changes were made.
    if(ChangesMade){
        char op_save;
        cout << "Would you like to keep the last changes you made?" <<'\n'
             << "1. Yes" << endl
             << "2. No" << endl << endl << endl << endl << endl << endl << endl << '\n'
             << "Insert the number: ";
        validate_input(op_save,'1','2');
        if(op_save == '2'){
            restore.restore(mySchedule,students,classes,ucs,schedules,AttendancePair);
            restore_value.pop_back();
            ChangesMade = false;
        }
    }
    Restoring restore_backup(mySchedule,students,classes,ucs,schedules,AttendancePair);
    restore_value.push_back(restore_backup);
    restore = restore_backup;
    char op;
    clear_screen();
    cout << "What request would you like to choose?" << endl << '\n'
         << "1. Add UC to a student" << endl
         << "2. Remove UC from a student" << endl
         << "3. Switch UCs from a student" << endl
         << "4. Add Class to a certain UC of a student" << endl
         << "5. Remove Class to a certain UC of a student" << endl
         << "6. Switch Class to a certain UC of a student" << endl
         << "7. Return to menu" << endl << endl
         << "Insert the number: ";
    validate_input(op, '1' ,'7');
    switch(op){

        case '1':{
            // Handle the request to add a UC to a student.
            string student_name;
            string UC_code;
            string class_code;
            cout << "Introduce the name of the student: ";
            cin >> student_name;
            cout << endl;
            cout << "Introduce the code of the UC you want to add: ";
            cin >> UC_code;
            cout << endl;
            cout << "Introduce the code of the Class of the UC that you want to add: ";
            cin >> class_code;
            cout << endl;
            Student student_func;
            UC uc_func;
            uc_func.setRespectiveClass(class_code);
            uc_func.setUcCode(UC_code);
            student_func.setName(student_name);
            auto it_student = mySchedule.FetchStudent(student_func);
            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }
            student_func = it_student->first;
            mySchedule.FindUC(uc_func);

            if(!uc_func.hasValue())
            {
                std::cout << "UC not found" << std::flush;
                this_thread::sleep_for(chrono::seconds(1));
                menu_options();
            }

            std::vector<std::variant<Student, UC, char>> request;
            request.push_back(op);
            request.push_back(student_func);
            request.push_back(uc_func);
            requests.push_back(request);
            break;
        }
        case '2':{
            // Handle the request to remove a UC from a student.
            string student_name;
            string UC_code;
            string class_code;
            cout << "Introduce the name of the student: ";
            cin >> student_name;
            cout << endl;

            Student student_func;
            UC uc_func;
            student_func.setName(student_name);

            auto it_student = mySchedule.FetchStudent(student_func);
            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }

            cout << "These are the available UCs: \n";

            for(auto uc : it_student -> second)
            {
                cout << uc.getUcCode() << " " << uc.getRespectiveClass() << " " <<uc.getType() << "\n";
            }

            cout << endl << endl << "Introduce the code of the UC you want to remove: ";
            cin >> UC_code;
            cout << endl;
            cout << "Introduce the code of the Class of the UC that you want to remove: ";
            cin >> class_code;
            cout << endl;

            student_func = it_student->first;
            uc_func.setUcCode(UC_code);
            uc_func.setRespectiveClass(class_code);

            if(!uc_func.hasValue())
            {
                std::cout << "UC not found" << std::flush;
                this_thread::sleep_for(chrono::seconds(1));
                menu_options();
            }

            std::vector<std::variant<Student, UC, char>> request;
            request.push_back(op);
            request.push_back(student_func);
            request.push_back(uc_func);
            requests.push_back(request);

            break;
        }
        case '3':{
            // Handle the request to switch UCs for a student.
            string student_name;
            string UC_code;
            string UC_code_new;
            string class_code;
            string class_code_new;
            cout << "Introduce the name of the student: ";
            cin >> student_name;
            cout << endl;

            cout << endl << "Introduce the code of the UC you want to switch in: ";
            cin >> UC_code_new;
            cout << endl;
            cout << "Introduce the code of the class you want to switch in: ";
            cin >> class_code_new;
            cout << endl;

            UC uc_func_new;
            uc_func_new.setUcCode(UC_code_new);
            uc_func_new.setRespectiveClass(class_code_new);

            mySchedule.FindUC(uc_func_new);

            Student student_func;
            student_func.setName(student_name);
            auto it_student = mySchedule.FetchStudent(student_func);
            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }
            cout << endl << "These are the available UCs: \n" ;

            for(auto uc : it_student -> second)
            {
                cout << uc.getUcCode() << " " << uc.getRespectiveClass() << " " <<uc.getType() << "\n";
            }
            UC uc_func;

            cout << "Introduce the code of the UC you want to switch out: ";
            cin >> UC_code;
            cout << endl;
            cout << "Introduce the code of the class you want to switch out: ";
            cin >> class_code;
            cout << endl;

            uc_func.setRespectiveClass(class_code);
            uc_func.setUcCode(UC_code);

            mySchedule.FindUC(uc_func);
            student_func = it_student->first;

            if(!uc_func.hasValue() || !uc_func_new.hasValue())
            {
                std::cout << "UC not found" << std::flush;
                this_thread::sleep_for(chrono::seconds(1));
                menu_options();
            }

            std::vector<std::variant<Student, UC, char>> request;
            request.push_back(op);
            request.push_back(student_func);
            request.push_back(uc_func_new);
            request.push_back(uc_func);
            requests.push_back(request);
            break;
        }
        case '4':{
            // Handle the request to add a class to a certain UC of a student.
            Student student_func;
            string Student_name;
            string UC_code;
            string class_code;
            cout << "Introduce the name of the student: ";
            cin >> Student_name;
            cout << endl;

            student_func.setName(Student_name);
            auto it_student = mySchedule.FetchStudent(student_func);
            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }
            student_func = it_student->first;

            cout << endl << "These are the available UCs: \n" ;

            for(auto uc : it_student -> second)
            {
                cout << uc.getUcCode() << " " << uc.getRespectiveClass() << " " <<uc.getType() << "\n";
            }

            cout << "Introduce the code of the UC: ";
            cin >> UC_code;
            cout << endl;
            cout << "Introduce the code of the class you want to add: ";
            cin >> class_code;
            cout << endl;
            UC uc_func;
            uc_func.setRespectiveClass(class_code);
            uc_func.setUcCode(UC_code);
            mySchedule.FindUC(uc_func);

            if(!uc_func.hasValue())
            {
                std::cout << "UC not found" << std::flush;
                this_thread::sleep_for(chrono::seconds(1));
                menu_options();
            }

            std::vector<std::variant<Student, UC, char>> request;
            request.push_back(op);
            request.push_back(student_func);
            request.push_back(uc_func);
            requests.push_back(request);
            break;
        }
        case '5':{
            // Handle the request to remove a class from a certain UC of a student.
            string student_name;
            string UC_code;
            string class_code;
            cout << "Introduce the name of the student: ";
            cin >> student_name;
            cout << endl;

            Student student_func;
            student_func.setName(student_name);
            auto it_student = mySchedule.FetchStudent(student_func);
            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }
            cout << "These are the available UCs:\n" ;

            for(auto uc : it_student -> second)
            {
                cout << uc.getUcCode() << " " << uc.getRespectiveClass() << " " <<uc.getType() << "\n";
            }
            UC uc_func;

            cout << endl << endl << "Introduce the code of the UC: ";
            cin >> UC_code;
            cout << endl;
            cout << "Introduce the code of the Class of the UC that you want to remove: ";
            cin >> class_code;
            cout << endl;
            uc_func.setUcCode(UC_code);
            uc_func.setRespectiveClass(class_code);

            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }
            student_func = it_student->first;

            mySchedule.FindUCinStudent(student_func , uc_func);
            if(!uc_func.hasValue())
            {
                std::cout << "UC not found" << std::flush;
                this_thread::sleep_for(chrono::seconds(1));
                menu_options();
            }


            std::vector<std::variant<Student, UC, char>> request;
            request.push_back(op);
            request.push_back(student_func);
            request.push_back(uc_func);
            requests.push_back(request);
            break;
        }
        case '6': {
            // Handle the request to switch a class for a certain UC of a student.
            string Student_name;
            string UC_code;
            string class_code_old;
            string class_code_new;
            Student student_func;
            UC new_uc;
            UC old_uc;
            cout << "Introduce the name of the student: ";
            cin >> Student_name;
            cout << endl;
            student_func.setName(Student_name);
            auto it_student = mySchedule.FetchStudent(student_func);
            if(it_student == mySchedule.getStudentSchedules().end()){
                std::cout << "Error: Student not found." << std::endl;
                menu_options();
            }
            student_func = it_student->first;

            cout << "These are the available UCs: \n" ;

            for(auto uc : it_student -> second)
            {
                cout << uc.getUcCode() << " " << uc.getRespectiveClass() << " " <<uc.getType() << "\n";
            }

            cout << endl << endl << "Introduce the code of the UC: ";
            cin >> UC_code;
            cout << endl;

            cout << "Introduce the code of the Class you want to switch out: ";
            cin >> class_code_old;
            cout << endl;

            old_uc.setUcCode(UC_code);
            old_uc.setRespectiveClass(class_code_old);
            mySchedule.FindUCinStudent(student_func , old_uc);

            cout << "Introduce the code of the Class you want to switch in: ";
            cin >> class_code_new;
            cout << endl;

            new_uc.setUcCode(UC_code);
            new_uc.setRespectiveClass(class_code_new);
            mySchedule.FindUC(new_uc);

            if(!new_uc.hasValue() || !old_uc.hasValue())
            {
                std::cout << "UC not found" << std::flush;
                this_thread::sleep_for(chrono::seconds(1));
                menu_options();
            }

            std::vector<std::variant<Student, UC, char>> request;
            request.push_back(op);
            request.push_back(student_func);
            request.push_back(old_uc);
            request.push_back(new_uc);
            requests.push_back(request);
            break;
        }
        case '7':{
            // Return to the main menu.
            menu_options();
        }
    }
    char trash;
    cout << endl << "Press any button and enter to return to the menu options: ";
    cin >> trash;
    menu_options();
}

/**
     * @brief Save global alterations to a CSV file.
     * The CSV file includes student information along with UCs and classes they are assigned to.
     * The file format is "StudentCode, StudentName, UcCode, ClassCode".
     */
void UI::save_global_alterations(){
    fstream fout;

    fout.open("schedule/student_classes.csv", ios::out | ios::app);

    if (!fout.is_open()) {
        std::cout << "Error opening file for writing." << std::endl;
        return;
    }

    fout << "StudentCode,StudentName,UcCode,ClassCode" << std::endl;

    auto m =  mySchedule.getStudentSchedules();
    for (const auto& entry : m) {
        const Student& student = entry.first;

        for (const UC& uc : entry.second) {
            fout << student.getId() << "," << student.getName() << ","
                 << uc.getUcCode() << "," << uc.getRespectiveClass() << std::endl;
        }
    }

    fout.close();
}

/**
     * @brief Display a menu for managing pending requests.
     * The menu provides options to view the number of pending requests, process individual requests,
     * process all pending requests, clear requests, and return to the main menu.
     * Users can select from these options by inputting a number.
     */
void UI::requests_()
{
    if(requests.empty())
    {
        std::cout << "Requests are empty" << std::flush;
        this_thread::sleep_for(chrono::seconds(2));
        menu_options();
    }
    else
    {
        char op;
        std::cout << "1. Print how many requests are pending" << endl
                  << "2. Process first pending request" << endl
                  << "3. Process last request" << endl
                  << "4. Process all pending requests" << endl
                  << "5. Clear all pending requests" << endl
                  << "6. Clear the first request" << endl
                  << "7. Clear the last request" << endl
                  << "8. Return to main menu" << endl
                  << "Insert the number: ";
        validate_input(op, '1' ,'8');
        std::vector<std::variant<Student, UC, char>> temp;
        switch (op) {
            case '1':{
                std::cout << requests.size();
                break;
            }
            case '2':{
                temp.clear();
                temp = requests.front();
                requests.pop_front();
                process_requests(temp);
                break;
            }
            case '3':{
                temp.clear();
                temp = requests.back();
                requests.pop_back();
                process_requests(temp);
                break;
            }
            case '4':{
                while (!requests.empty())
                {
                    temp.clear();
                    temp = requests.front();
                    requests.pop_front();
                    process_requests(temp);
                }
                break;
            }
            case '5':{
                requests.clear();
                break;
            }
            case '6':{
                requests.pop_front();
                break;
            }
            case '7':{
                requests.pop_back();
                break;
            }
            case '8':{
                menu_options();
                break;
            }
        }
        char trash;
        cout << endl << "Press any button and enter to return to the menu options: ";
        cin >> trash;
        menu_options();
    }
}

/**
   * @brief Process a vector of requests.
   * This method processes a vector of requests, where each request is a combination of a student, UC, and an operation.
   * The method identifies the operation and performs the corresponding action, such as adding a UC to a student or removing a class from a UC.
   * After processing requests, it may set the ChangesMade flag to indicate that changes were made.
   * @param requests_ A vector of requests to be processed.
   */
void UI::process_requests(std::vector<std::variant<Student, UC, char>> requests_) {
    auto temp = requests_[0];
    char operator_;

    if(std::holds_alternative<char>(temp))
    {
        operator_ = std::get<char>(temp);;
    }
    switch (operator_)
    {
        case '1':{
            Student student_func;
            UC uc_func;

            for(auto& request: requests_)
            {
                if(std::holds_alternative<Student>(request))
                {
                    student_func = std::get<Student>(request);
                }
                else if(std::holds_alternative<UC>(request))
                {
                    uc_func = std::get<UC>(request);
                }
            }
            mySchedule.AddUC(student_func , uc_func);
            ChangesMade = true;
            break;
        }
        case '2':{
            Student student_func;
            UC uc_func;

            for(auto& request: requests_)
            {
                if(std::holds_alternative<Student>(request))
                {
                    student_func = std::get<Student>(request);
                }
                else if(std::holds_alternative<UC>(request))
                {
                    uc_func = std::get<UC>(request);
                }
            }

            mySchedule.RemoveUC(student_func,uc_func);
            ChangesMade = true;
            break;
        }
        case '3':{
            Student student_func;
            UC uc_func;
            UC uc_func_new;

            for(auto& request: requests_)
            {
                if(std::holds_alternative<Student>(request))
                {
                    student_func = std::get<Student>(request);
                }
                else if(std::holds_alternative<UC>(request))
                {
                    if(!uc_func.hasValue())
                    {
                        uc_func = std::get<UC>(request);
                    } else
                    {
                        uc_func_new = std::get<UC>(request);
                    }
                }
            }

            mySchedule.SwitchUc(student_func,uc_func_new,uc_func);
            ChangesMade = true;
            break;
        }
        case '4':{
            Student student_func;
            UC uc_func;

            for(auto& request: requests_)
            {
                if(std::holds_alternative<Student>(request))
                {
                    student_func = std::get<Student>(request);
                }
                else if(std::holds_alternative<UC>(request))
                {
                    uc_func = std::get<UC>(request);
                }
            }

            mySchedule.AddClass(student_func,uc_func);
            ChangesMade = true;
            break;
        }
        case '5':{
            Student student_func;
            UC uc_func;

            for(auto& request: requests_)
            {
                if(std::holds_alternative<Student>(request))
                {
                    student_func = std::get<Student>(request);
                }
                else if(std::holds_alternative<UC>(request))
                {
                    uc_func = std::get<UC>(request);
                }
            }

            mySchedule.RemoveClass(student_func,uc_func);
            ChangesMade = true;
            break;
        }
        case '6': {
            Student student_func;
            UC new_uc;
            UC old_uc;

            for(auto& request: requests_)
            {
                if(std::holds_alternative<Student>(request))
                {
                    student_func = std::get<Student>(request);
                }
                else if(std::holds_alternative<UC>(request))
                {
                    if(!old_uc.hasValue())
                    {
                        old_uc = std::get<UC>(request);
                    } else
                    {
                        new_uc = std::get<UC>(request);
                    }
                }
            }

            mySchedule.SwitchClass(student_func,old_uc,new_uc);
            ChangesMade = true;
            break;
        }
        case '7':{
            menu_options();
        }
    }
}

/**
     * @brief Restore changes from the list of stored backups.
     * The user selects a change to restore from the list of stored backups.
     */
void UI::restore_changes(){
    int op;
    int p = 0;
    for(int i = 0; i < restore_value.size(); i++){
        cout << "Change " << i << endl;
        p++;
    }
    cout << "Introduce the number: ";
    cin >> op;
    if(op < restore_value.size()) {
        restore_value[op].restore(mySchedule, students, classes, ucs, schedules, AttendancePair);
    } else {
        cout << "Invalid input. No change restored." << endl;
    }
}