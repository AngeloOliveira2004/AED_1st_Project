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

std::unordered_map<Class, std::vector<UC>>   Schedule::getClassSchedules() {
    return ClassSchedules;
}

int Schedule::getBalance()
{
    return Balance;
}

void Schedule::setStudentSchedules(std::unordered_map<Student, std::vector<UC>>  StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

void Schedule::setClassSchedules(std::unordered_map<Class, std::vector<UC>>  ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}

void Schedule::setBalance(int balance)
{
    Balance = balance;
}


void Schedule::CalculateBalance()
{
    for(auto class_ : ClassSchedules)
    {
        Balance = std::max(static_cast<int>(class_.first.getStudents().size()), Balance);
    }
}

void Schedule::StudentsInAtLeastNUcs(char n , std::vector<Student> students)
{
    for(auto pair : StudentSchedules)
    {
        if(pair.first.getClassesToUcs().size() >= n)
        {
            students.push_back(pair.first);
        }
    }
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

void Schedule::sort_by_week_day(std::pair<Student,std::vector<UC>> &a){
    std::sort(a.second.begin(), a.second.end(), compare_day);
}

void Schedule::sort_by_week_day(std::pair<Class,std::vector<UC>> &a){
    std::sort(a.second.begin(), a.second.end(), compare_day);
}


bool Schedule::compare_day(const UC &uc1, const UC &uc2){
    std::map<std::string, int> dayMap = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
    if(dayMap[uc1.getDate().Day] != dayMap[uc2.getDate().Day]){
        return dayMap[uc1.getDate().Day] < dayMap[uc2.getDate().Day];
    }else{
        return uc1.getDate().Duration.first < uc2.getDate().Duration.first;
    }
}

//TODO
void Schedule::SwitchClass(Student &student1, Class &new_class, UC &uc) {

}

jasldn ajsk<andf alskdf asldkf snldkf aldsjkf asljdf asldjfdnsj

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

    if(FindClassinSchedule(ex_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }
        std::unordered_set<string> students = tempCLass.getStudents();
        students.erase(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }
    if(FindClassinSchedule(new_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }
        std::unordered_set<string> students = tempCLass.getStudents();
        students.insert(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }
    ucOcupation[ex_uc.getUcCode()] -= 1;
    ucOcupation[new_uc.getUcCode()] += 1;
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
        StudentSchedules[student1].push_back(new_uc);
    }

    if(FindClassinSchedule(new_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == new_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }

        std::unordered_set<string> students = tempCLass.getStudents();
        if(students.size() <= MAX_CAP)
        {
            students.insert(student1.getName());
        }

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }

    ucOcupation[new_uc.getUcCode()] += 1;
}

void Schedule::RemoveUC(Student student1, UC ex_uc) {

    if(FindStudentinSchedule(student1.getName()))
    {
        auto& ucVector = StudentSchedules[student1];
        ucVector.erase(std::remove(ucVector.begin(), ucVector.end(), ex_uc), ucVector.end());
        StudentSchedules[student1] = ucVector;
    }

    if(FindClassinSchedule(ex_uc.getRespectiveClass()))
    {
        Class tempCLass;
        std::vector<UC> tempVector;
        for(auto pair : ClassSchedules)
        {
            if(pair.first.getClassCode() == ex_uc.getRespectiveClass())
            {
                tempCLass = pair.first;
                tempVector = pair.second;
                break;
            }
        }

        std::unordered_set<string> students = tempCLass.getStudents();
        students.erase(student1.getName());

        tempCLass.setStudents(students);
        ClassSchedules.erase(tempCLass);
        ClassSchedules[tempCLass] = tempVector;
    }

    ucOcupation[ex_uc.getUcCode()] -= 1;
}

/*
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
*/