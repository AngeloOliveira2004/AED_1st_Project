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

UC Schedule::FindUC(const UC &targetUC)
{
    for(UC uc : Ucs)
    {
        if(uc.getUcCode() == targetUC.getUcCode())
        {
            return uc;
        }
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

void Schedule::SwitchClass(Student &student1, Class &new_class, UC &uc) { //AED na turma 5 pra turma 6

    Class ex_Class;

    for(UC uc_ : Ucs)
    {
        if(uc_.getRespectiveClass() == new_class.getClassCode() && uc_.getUcCode() == uc.getUcCode())
        {
            ex_Class.setClassCode(uc.getRespectiveClass());
            uc = uc_;
        }
    }
    if(FindStudentinSchedule(student1.getName()))
    {
        for(auto uc : StudentSchedules[student1])
        {
            if(Date::Overlaps(uc.getDate() , uc.getDate()))
            {
                std::cerr << "Schedule not compatible with other classes";
                return;
            }
        }
        for(auto uc_ : StudentSchedules[student1])
        {
            if(uc.getUcCode() == uc_.getUcCode())
            {
                uc_ = uc;
                break;
            }
        }
    }
    ClassAttendance[ex_Class.getClassCode()].erase(student1.getName());
    ClassAttendance[new_class.getClassCode()].insert(student1.getName());

    UcOcupation[{uc.getUcCode() , ex_Class.getClassCode()}] -= 1;
    UcOcupation[{uc.getUcCode() , new_class.getClassCode()}] += 1;
}

void Schedule::SwitchUc(Student student1, UC new_uc, UC ex_uc)
{
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
            if(uc.getUcCode() == ex_uc.getUcCode())
            {
                uc = new_uc;
                break;
            }
        }
    }
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
    //ClassAttendance[ex_uc.getRespectiveClass()].erase(student1.getName());

    //UcOcupation[{ex_uc.getUcCode() , ex_uc.getUcCode()}] -= 1;

    CalculateBalance();
}

void Schedule::RemoveClass(Student student1, UC &uc)
{
    if (FindStudentinSchedule(student1.getName()))
    {
        auto it = StudentSchedules.find(student1);
        for(auto ucs : it->second)
        {
            std::vector<UC> tempV;
            if(uc.getRespectiveClass() != ucs.getRespectiveClass() && uc.getUcCode() != ucs.getUcCode())
            {
                tempV.push_back(ucs);
            }
            else
            {
                ClassAttendance[ucs.getRespectiveClass()].erase(student1.getName());
                UcOcupation[{ucs.getUcCode() , ucs.getRespectiveClass()}] -= 1;
            }
            StudentSchedules[student1] = tempV;
        }

        for(auto pair : it->first.getClassesToUcs())
        {
            if(pair.second == uc.getUcCode())
            {
                pair.first = "EMPTY";
            }
        }
    }
}

void Schedule::AddClass(Student student1, UC &uc)
{
    if (FindStudentinSchedule(student1.getName()))
    {
        auto it = StudentSchedules.find(student1);

        for(auto pair : it->first.getClassesToUcs())
        {
            if(pair.first == "EMPTY")
            {
                pair.first = uc.getRespectiveClass();
            }
        }

        StudentSchedules[student1].push_back(uc);
    }
}

void Schedule::RemoveWholeClass(Student student1, Class &class_) {
    if (FindStudentinSchedule(student1.getName())) {

        for(auto classes : StudentSchedules[student1])
        {
            std::vector<UC> tempV;
            if(classes.getRespectiveClass() != class_.getClassCode())
            {
                tempV.push_back(classes);
            }
            else
            {
                ClassAttendance[classes.getRespectiveClass()].erase(student1.getName());
                UcOcupation[{classes.getUcCode() , classes.getRespectiveClass()}] -= 1;
            }
            StudentSchedules[student1] = tempV;
        }
    } else {
        std::cerr << "Student not found in the schedule" << std::endl;
    }
}

void Schedule::AddWholeClass(Student student1 , Class &new_class){

    auto it = ClassSchedules.find(new_class);

    new_class = it->first;

    if (FindStudentinSchedule(student1.getName())) {

        for(auto uc : new_class.getUCs())
        {
            UC tempUc;
            tempUc.setUcCode(uc);

            tempUc = FindUC(tempUc);
            //IMmplementar funcao que vai buscar as ucs
            ClassAttendance[new_class.getClassCode()].insert(student1.getName());
            CalculateBalance();
            if(Balance <= 4)
            {
                UcOcupation[{tempUc.getUcCode() , new_class.getClassCode()}] += 1;
            }
            else
            {
                ClassAttendance[new_class.getClassCode()].erase(student1.getName());
                std::cerr << "Balance disrupted";
            }

            StudentSchedules[student1].push_back(tempUc);
        }
    } else {
        std::cerr << "Student not found in the schedule" << std::endl;
    }
}


