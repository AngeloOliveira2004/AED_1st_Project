#include <iostream>
#include <utility>
#include "Schedule.h"

// Constructor implementation O(1)

Schedule::Schedule(std::unordered_map<Student, std::vector<UC>>  studentSchedules_,
                   std::unordered_map<Class, std::vector<UC>>  classSchedules_) :

        ClassSchedules(std::move(classSchedules_)) , StudentSchedules(std::move(studentSchedules_)) {}


// Get a reference to the vector of UC objects O(1)
std::unordered_map<Student, std::vector<UC>> Schedule::getStudentSchedules() {
    return StudentSchedules;
}

std::unordered_map<Class, std::vector<UC>> Schedule::getClassSchedules() {
    return ClassSchedules;
}

std::unordered_map<std::pair<std::string, std::string>, int, PairHash> Schedule::getUcOcupation() {
    return UcOcupation;
}

std::unordered_map<std::string, unordered_set<std::string>> Schedule::getClassAttendance() {
    return ClassAttendance;
}

int Schedule::getBalance() const {
    return Balance;
}

void Schedule::setStudentSchedules(std::unordered_map<Student, std::vector<UC>>  StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

void Schedule::setClassSchedules(std::unordered_map<Class, std::vector<UC>>  ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}

void Schedule::setUcOcupation(unordered_map<pair<basic_string<char>, basic_string<char>>, int, PairHash> UcOcupation_)
{
    UcOcupation = UcOcupation_;
}

void Schedule::setClassAttendance(std::unordered_map<std::string, unordered_set<std::string>> ClassAttendance_)
{
    ClassAttendance = std::move(ClassAttendance_);
}

void Schedule::setBalance(int balance)
{
    Balance = balance;
}

void Schedule::setUCs(std::vector<UC> ucs_)
{
    Ucs = ucs_;
}

void Schedule::CalculateBalance()
{
    int temp1 = INT16_MAX;
    int temp2 = INT16_MIN;
    for(auto class_ : ClassAttendance)
    {
        temp1 = std::min(temp1 , static_cast<int>(class_.second.size()));
        temp2 = std::max(temp2 , static_cast<int>(class_.second.size()));
    }
    Balance = temp2 - temp1;
}

bool Schedule::FindStudentinSchedule(std::string student_name) {

    Student StudentToFind;
    StudentToFind.setName(student_name);

    auto it = StudentSchedules.find(StudentToFind);

    if(it != StudentSchedules.end())
    {
        return true;
    }

    return false;
}

std::unordered_map<Student, std::vector<UC>>::iterator Schedule::FetchStudent(Student StudentToFind)
{
    if(FindStudentinSchedule(StudentToFind.getName()))
    {
        return StudentSchedules.find(StudentToFind);
    }
}

std::unordered_map<Class, std::vector<UC>>::iterator Schedule::FetchClass(Class ClassToFind)
{
    if(FindClassinSchedule(ClassToFind.getClassCode()))
    {
        return ClassSchedules.find(ClassToFind);
    }
}

Student Schedule::FindStudentinSchedulebyID(int ID) {

    for (const auto& student : StudentSchedules) {
        if (student.first.getId() == ID) {
            return student.first;
        }
    }
    return Student();
}

bool Schedule::FindClassinSchedule(std::string ClassCode)
{
    Class ClassToFind;
    ClassToFind.setClassCode(ClassCode);

    auto it = ClassSchedules.find(ClassToFind);

    if(it != ClassSchedules.end())
    {
        return true;
    }

    return false;
}

void Schedule::FindUC(UC &targetUC)
{
    std::vector<UC> ucs;
    for(UC uc : Ucs)
    {
        if(uc.getUcCode() == targetUC.getUcCode() && uc.getRespectiveClass() == targetUC.getRespectiveClass())
        {
            ucs.push_back(uc);
        }
    }
    if(ucs.size() > 1)
    {
        string choice;
        cout << "Which UC do you want to choose? \n";
        for(int i = 0 ; i < ucs.size() ; i++)
        {
            cout << i+1 << " " << ucs[i].getUcCode() << " "  << ucs[i].getRespectiveClass() << " " << ucs[i].getType()<< " " << ucs[i].getDate().Day << " " << ucs[i].getDate().Duration.first << " " << ucs[i].getDate().Duration.second << endl;
        }
        std::cout << "Insert your option: ";
        cin >> choice;
        targetUC = ucs[stoi(choice)-1];
    }
    else
    {
        targetUC = ucs[0];
    }
}

void Schedule::FindUCinStudent(Student student, UC &targetUC)
{
    std::vector<UC> ucs;
    for(UC uc : StudentSchedules[student])
    {
        if(uc.getUcCode() == targetUC.getUcCode() && uc.getRespectiveClass() == targetUC.getRespectiveClass())
        {
            ucs.push_back(uc);
        }
    }
    if(ucs.size() > 1)
    {
        string choice;
        cout << "Which UC do you want to choose? \n";
        for(int i = 0 ; i < ucs.size() ; i++)
        {
            cout << i+1 << " " << ucs[i].getUcCode() << " "  << ucs[i].getRespectiveClass() << " " << ucs[i].getType()<< " " << ucs[i].getDate().Day << " " << ucs[i].getDate().Duration.first << " " << ucs[i].getDate().Duration.second << endl;
        }
        std::cout << "Insert your option: ";
        cin >> choice;
        targetUC = ucs[stoi(choice)-1];
    }
    else
    {
        targetUC = ucs[0];
    }
}


bool Schedule::compare_day(const UC &uc1, const UC &uc2){
    std::map<std::string, int> dayMap = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
    if(dayMap[uc1.getDate().Day] != dayMap[uc2.getDate().Day]){
        return dayMap[uc1.getDate().Day] < dayMap[uc2.getDate().Day];
    }else{
        return uc1.getDate().Duration.first < uc2.getDate().Duration.first;
    }
}

void Schedule::StudentsInAtLeastNUcs(char n , std::vector<Student>& students)
{
    for(auto pair : StudentSchedules)
    {
        int temp = 0;
        for(auto uc_ : pair.second)
        {
            if(uc_.getType() == "TP")
            {
                temp++;
            }
        }
        if(temp >= n-49)
        {
            students.push_back(pair.first);
        }
    }
}

void Schedule::SwitchClass(Student &student1, UC& old_uc, UC &new_uc) { //AED na turma 5 pra turma 6

    vector<UC> tempV;

    for(UC Uc : StudentSchedules[student1])
    {
        if(Uc == old_uc && old_uc.getDate().Day == Uc.getDate().Day && old_uc.getDate().Duration.first == Uc.getDate().Duration.first && old_uc.getDate().Duration.second == Uc.getDate().Duration.second)
        {
            if(ClassAttendance[new_uc.getRespectiveClass()].size()+1 < Balance)
            {
                tempV.push_back(new_uc);
                ClassAttendance[old_uc.getRespectiveClass()].erase(student1.getName());
                ClassAttendance[new_uc.getRespectiveClass()].insert(student1.getName());

                UcOcupation[{old_uc.getUcCode() , old_uc.getRespectiveClass()}] -= 1;
                UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
            }
            else{
                std::cout << "Balance disrupted";
            }
        }
        else
        {
            tempV.push_back(Uc);
        }
    }
    StudentSchedules[student1] = tempV;
}

void Schedule::SwitchUc(Student student1, UC new_uc, UC ex_uc)
{
    std::vector<UC> tempV;
    if(FindStudentinSchedule(student1.getName()))
    {
        for(auto uc : StudentSchedules[student1])
        {
            if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
            {
                std::cerr << "Schedule not compatible with other classes";
                return;
            }
        }
        for(auto uc : StudentSchedules[student1])
        {
            if(uc == ex_uc && ex_uc.getDate().Day == uc.getDate().Day && ex_uc.getDate().Duration.first == uc.getDate().Duration.first && ex_uc.getDate().Duration.second == uc.getDate().Duration.second)
            {
                tempV.push_back(new_uc);
            }
            else
            {
                tempV.push_back(uc);
            }
        }
    }
    StudentSchedules[student1] = tempV;
    ClassAttendance[ex_uc.getRespectiveClass()].erase(student1.getName());
    ClassAttendance[new_uc.getRespectiveClass()].insert(student1.getName());

    UcOcupation[{ex_uc.getUcCode() , ex_uc.getRespectiveClass()}] -= 1;
    UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
}

void Schedule::AddUC(Student student1, UC new_uc) {
    if(FindStudentinSchedule(student1.getName()) && student1.getClassesToUcs().size() < 7)
    {
        for(UC uc : StudentSchedules[student1])
        {
            if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
            {
                std::cerr << "Schedule not compatible with other classes";
                return;
            }
        }
        if(ClassAttendance[new_uc.getRespectiveClass()].size() + 1 <= Balance)
        {
            StudentSchedules[student1].push_back(new_uc);
        }
        else
        {
            std::cout << "Balance Disrupted";
        }
    }
    ClassAttendance[new_uc.getRespectiveClass()].insert(student1.getName());

    UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;

    CalculateBalance();
}

void Schedule::RemoveUC(Student student1, UC ex_uc) {

    if(FindStudentinSchedule(student1.getName()))
    {
        vector<UC> ucVector;
        for(auto uc : StudentSchedules[student1])
        {
            if(uc.getUcCode() != ex_uc.getUcCode())
            {
                ucVector.push_back(uc);
            }
        }

        StudentSchedules[student1] = ucVector;
    }
    ClassAttendance[ex_uc.getRespectiveClass()].erase(student1.getName());

    UcOcupation[{ex_uc.getUcCode() , ex_uc.getRespectiveClass()}] -= 1;

    CalculateBalance();
}

void Schedule::RemoveClass(Student student1, UC &uc)
{
    std::vector<UC> tempV;
    if (FindStudentinSchedule(student1.getName()))
    {
        auto it = StudentSchedules.find(student1);

        for(auto ucs : it->second)
        {
            if(ucs == uc && ucs.getDate().Day == uc.getDate().Day && ucs.getDate().Duration.first == uc.getDate().Duration.first && ucs.getDate().Duration.second == uc.getDate().Duration.second)
            {
                ucs.setRespectiveClass("EMPTY");
                tempV.push_back(ucs);
            }
            else
            {
                tempV.push_back(ucs);
            }
        }
    }
    StudentSchedules[student1] = tempV;
    ClassAttendance[uc.getRespectiveClass()].erase(student1.getName());
    UcOcupation[{uc.getUcCode() , uc.getRespectiveClass()}] -= 1;

}

void Schedule::AddClass(Student student1, UC &uc)
{
    vector<UC> tempV;
    if (FindStudentinSchedule(student1.getName()))
    {
        auto it = StudentSchedules[student1];

        for(auto ucs : it)
        {
            if(ucs.getRespectiveClass() == "EMPTY")
            {
                if(ucs.getUcCode() == uc.getUcCode())
                {
                    tempV.push_back(uc);
                    ClassAttendance[uc.getRespectiveClass()].insert(student1.getName());
                    UcOcupation[{uc.getUcCode() , uc.getRespectiveClass()}] += 1;
                }
                else
                {
                    std::cout << "UCs codes do not match \n";
                }
            }
            else
            {
                tempV.push_back(ucs);
            }
        }
    }
    StudentSchedules[student1] = tempV;
}

