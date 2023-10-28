#include <iostream>
#include <utility>
#include "Schedule.h"

// Constructor implementation O(1)
Schedule::Schedule() : StudentSchedules({}) , ClassSchedules({}){}

Schedule::Schedule(std::vector<std::pair<Student, std::vector<UC>>> studentSchedules_,
                    std::vector<std::pair<Class, std::vector<UC>>> classSchedules_) :

        ClassSchedules(std::move(classSchedules_)) , StudentSchedules(std::move(studentSchedules_)) {}


// Get a reference to the vector of UC objects O(1)
std::vector<std::pair<Student, std::vector<UC>>> Schedule::getStudentSchedules() {
    return StudentSchedules;
}

std::vector<std::pair<Class , std::vector<UC>>>  Schedule::getClassSchedules() {
    return ClassSchedules;
}

int Schedule::getBalance()
{
    return Balance;
}

void Schedule::setStudentSchedules(std::vector<std::pair<Student, std::vector<UC>>> StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

void Schedule::setClassSchedules(std::vector<std::pair<Class, std::vector<UC>>> ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}

void Schedule::setBalance(int balance)
{
    Balance = balance;
}

void Schedule::FindStudentInSchedules(const std::string& nameToFind, std::pair<Student, std::vector<UC>>& StudentPair) {
    auto it = std::lower_bound(StudentSchedules.begin(), StudentSchedules.end(), nameToFind, [](const std::pair<Student, std::vector<UC>>& pair, const std::string& name) {
        return pair.first.getName() < name;
    });

    if (it != StudentSchedules.end() && it->first.getName() == nameToFind) {
        // Found the student by name
        StudentPair = *it;
    } else {
        // Student not found
        std::cerr << "Student not found" << std::endl;
    }
}

void Schedule::FindClassInSchedules(const std::string& classCode, std::pair<Class, std::vector<UC>>& ClassPair) {
    auto compareFunc = [](const std::pair<Class, std::vector<UC>>& pair, const std::string& code) {
        return pair.first.getClassCode() < code;
    };

    auto it = std::lower_bound(ClassSchedules.begin(), ClassSchedules.end(), classCode, compareFunc);

    if (it != ClassSchedules.end() && compareFunc(*it, classCode) == 0) {
        // Found the class
        ClassPair = *it;
    } else {
        // Class not found
        std::cerr << "Class not found" << std::endl;
    }
}
//O(n)
int Schedule::FindStudentIndex(const Student &student , const std::string& student_name)
{
    if(student_name != " ")
    {
        for(int i = 0; i < StudentSchedules.size() ; i++)
        {
            if(StudentSchedules[i].first == student)
            {
                return i;
            }
        }
    }
    else
    {
        for(int i = 0; i < StudentSchedules.size() ; i++)
        {
            if(StudentSchedules[i].first.getName() == student_name)
            {
                return i;
            }
        }
    }
    return -1;
}

int Schedule::FindClassIndex(const Class& class_ , const std::string& class_code) {
    if (class_code != " ") {
        for (int i = 0; i < ClassSchedules.size(); i++) {
            if (ClassSchedules[i].first == class_) {
                return i;
            }
        }
    } else {
        for (int i = 0; i < ClassSchedules.size(); i++) {
            if (ClassSchedules[i].first.getClassCode() == class_code) {
                return i;
            }
        }
        return -1;
    }
}

void Schedule::CalculateBalance()
{
    for(auto class_ : ClassSchedules)
    {
        Balance = std::max(static_cast<int>(class_.first.getStudents().size()), Balance);
    }
}

void Schedule::StudentsInAtLeastNUcs(std::vector<Student>& students, char n)
{
    for(auto student : StudentSchedules)
    {
        if(student.first.getClassesToUcs().size() >= n)
        {
            students.push_back(student.first);
        }
    }
}

void Schedule::SwitchClass(Student &student1, Class &new_class, Class &ex_class)
{
    auto it = std::lower_bound(student1.getClassesToUcs().begin(), student1.getClassesToUcs().end(),
           ex_class.getClassCode(),
           [](const std::pair<string, string> &pair, const std::string &name) {
               return pair.first < name;
           });

    if (it == student1.getClassesToUcs().end()) {
        std::cout << "Class not found";
        return;
    }
/*
    for(auto pair : student1.getClassesToUcs())
    {
        if(pair.first == ex_class.getClassCode())
        {
            pair.first = new_class.getClassCode()
        }
    }
*/
}


void Schedule::SwitchUc(Student student1, UC new_uc, UC ex_uc)
{
    for (auto pair: student1.getClassesToUcs()) {
        if (pair.second == ex_uc.getUcCode()) {
            pair.first = new_uc.getRespectiveClass();
            pair.second = new_uc.getUcCode();
        }
    }

    int index = FindStudentIndex(student1, " ");

    StudentSchedules[index].first = student1;

    for (auto it = StudentSchedules[index].second.begin(); it != StudentSchedules[index].second.end(); ++it) {
        if (*it == ex_uc) {
            // Found a matching UC, erase it and insert the new UC
            it = StudentSchedules[index].second.erase(it);
            StudentSchedules[index].second.insert(it, new_uc);
        }
    }
}

void Schedule::AddUC(Student student1, UC new_uc) {
    if(student1.getClassesToUcs().size() < 7)
    {
        student1.getClassesToUcs().push_back({new_uc.getRespectiveClass() , new_uc.getUcCode()});
        int index = FindStudentIndex(student1 , " ");
        StudentSchedules[index].first = student1;
        Class temp;
        int classIndex = FindClassIndex(temp , new_uc.getRespectiveClass());

        //fazer alterações nas classes e nas ucs. dá mais trabalho
    }
}

void Schedule::RemoveUC(Student student1, UC ex_uc) {
    // Mensagem de erro caso aluno n exista??
    for (auto it = student1.getClassesToUcs().begin(); it != student1.getClassesToUcs().end(); ++it) {
        if (it->first == ex_uc.getUcCode()) {
            student1.getClassesToUcs().erase(it);
            break;
        }
    }
    // Mensagem de erro caso o aluno n esteja nessa Uc ??
}


void Schedule::RemoveClass(Student student1, Class ex_class) {
    for (auto it = student1.getClassesToUcs().begin(); it != student1.getClassesToUcs().end(); ++it) {
        if (it->second == ex_class.getClassCode())  {
            student1.getClassesToUcs().erase(it);
        }
    }
}

void Schedule::AddClass(Student student1, Class new_class) {
    bool classWithCapacity = false;
    const std::unordered_set<std::string>& newClassCapacity = new_class.getStudents();
    std::vector<pair<std::string , std::string>> newClassToUc;
    for (const std::string& ucCode : new_class.getUCs()) {
        bool alreadyTakingUc = false;
        for (auto it = student1.getClassesToUcs().begin(); it != student1.getClassesToUcs().end(); ++it) {
            if (it->first == ucCode){
                alreadyTakingUc = true;
                break;    //ja esta na uc, dar skip
            }
            }
        if(!alreadyTakingUc && newClassCapacity.size() < MAX_CAP){
            newClassToUc.push_back(std::make_pair(ucCode, new_class.getClassCode()));
            //nao deixar q o aluno fique com mais de 7 ucs
        }
        if(newClassToUc.size() + student1.getClassesToUcs().size() < 7){  //Verificar se nao ha conflito no horario
            for(pair p : newClassToUc){
                student1.getClassesToUcs().push_back(p); //Deve haver forma mais efeciente de fzr isto mas n sei
        }
        }
    }
}

//fazer number students registados n ucs
//calcular balance