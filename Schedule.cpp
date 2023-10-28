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
        int index = FindStudentIndex(student1 , " ");
        Class temp;
        int classIndex = FindClassIndex(temp , new_uc.getRespectiveClass());
        StudentSchedules[index].second.push_back(new_uc);
        for (auto& classSchedule : ClassSchedules) {
            for (auto& uc : classSchedule.second) {
                if (uc.getUcCode() == new_uc.getUcCode() && uc.getRespectiveClass() == new_uc.getRespectiveClass() && uc.getOccupation() < MAX_CAP) {
                    int newOccupation = uc.getOccupation() + 1;
                    uc.setOccupation(newOccupation);
                    break;
                }
            }
        }
        //fazer alterações nas classes e nas ucs. dá mais trabalho*/
    }
}

void Schedule::RemoveUC(Student student1, UC ex_uc) {
    int index = FindStudentIndex(student1, " ");
    if(index == -1) {cout << "Student not found";}
    for(auto it = StudentSchedules[index].second.begin(); it != StudentSchedules[index].second.end(); ++it){
        if(it->getUcCode() == ex_uc.getUcCode()){
            StudentSchedules[index].second.erase(it);
            for (auto& classSchedule : ClassSchedules) {
                for (auto& uc : classSchedule.second) {
                    if (uc.getUcCode() == ex_uc.getUcCode() && uc.getRespectiveClass() == ex_uc.getRespectiveClass()) {
                        int newOccupation = uc.getOccupation() - 1;
                        uc.setOccupation(newOccupation);
                        break;
                    }
                }
            }
        }
    }
}


void Schedule::RemoveClass(Student student1, Class ex_class) {
    int studentIndex = FindStudentIndex(student1, " ");
    int classIndex = FindClassIndex(ex_class, ex_class.getClassCode());
    if(studentIndex == -1 || classIndex == -1) {cout << "Enter a valid Student and Class";}
    for(auto it = ClassSchedules[classIndex].second.begin(); it != ClassSchedules[classIndex].second.end(); ++it){
        int new_occupation = it->getOccupation();
        for(auto it2 = student1.getClassesToUcs().begin(); it2 != student1.getClassesToUcs().end(); ++it2){
            if(it2->second == ex_class.getClassCode()){
                if(it2->first == it->getUcCode()){
                    StudentSchedules[studentIndex].second.erase(it);
                    for (auto& classSchedule : ClassSchedules) {
                        for (auto& uc : classSchedule.second) {
                            if (uc.getUcCode() == it->getUcCode() && uc.getRespectiveClass() == ex_class.getClassCode()) {
                                int newOccupation = uc.getOccupation() - 1;
                                uc.setOccupation(newOccupation);
                                break;
                            }
                        }
                    }
                }
            }
        }
    }
}

void Schedule::AddClass(Student student1, Class new_class) {
    bool classWithCapacity = false;
    int studentIndex = FindStudentIndex(student1, " ");
    int classIndex = FindClassIndex(new_class, new_class.getClassCode());
    const std::unordered_set<std::string>& newClassCapacity = new_class.getStudents();
    std::vector<UC> ucsToAdd;
    for (const std::string& ucCode : new_class.getUCs()) {
        bool alreadyTakingUc = false;
        for(auto it = ClassSchedules[classIndex].second.begin(); it != ClassSchedules[classIndex].second.end(); ++it){
            if(it->getUcCode() == ucCode){
                alreadyTakingUc = true;
                if(!alreadyTakingUc && newClassCapacity.size() < MAX_CAP){
                    ucsToAdd.push_back(*it);
                }
            }
        }
    }
        if(ucsToAdd.size() + student1.getClassesToUcs().size() < 7){
            for(UC newUc : ucsToAdd){
                StudentSchedules[studentIndex].second.push_back(newUc);
                int newOccupation = newUc.getOccupation() + 1;
                newUc.setOccupation(newOccupation);
            }
        }
    //Verificar se nao ha conflito no horario
}

//fazer number students registados n ucs
//calcular balance