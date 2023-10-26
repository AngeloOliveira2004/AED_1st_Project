//
// Created by angelo on 25-10-2023.
//
#include "UI.h"
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
            this_thread::sleep_for(chrono::seconds(2)); // Espera 1 segundo antes de fechar o terminal
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
            break;
        case '2':
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