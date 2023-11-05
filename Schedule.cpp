#include <iostream>
#include <utility>
#include "Schedule.h"

/**
 * @class Schedule
 * @brief A class that contains the schedules for a Class or Student and their methods
 */

/**
 * @brief Constructor implementation for the Schedule class.
 * @param studentSchedules_ The map of student schedules.
 * @param classSchedules_ The map of class schedules.
 * @details Time Complexity: O(1)
 */
Schedule::Schedule(std::unordered_map<Student, std::vector<UC>>  studentSchedules_,
                   std::unordered_map<Class, std::vector<UC>>  classSchedules_) :

        ClassSchedules(std::move(classSchedules_)) , StudentSchedules(std::move(studentSchedules_)) {}


/**
 * @brief Get the student schedules map.
 * @return The map of student schedules.
 * @details Time Complexity: O(1)
 */
std::unordered_map<Student, std::vector<UC>> Schedule::getStudentSchedules() {
    return StudentSchedules;
}

/**
 * @brief Get the class schedules map.
 * @return The map of student schedules.
 * @details Time Complexity: O(1)
 */
std::unordered_map<Class, std::vector<UC>> Schedule::getClassSchedules() {
    return ClassSchedules;
}

/**
 * @brief Get the occupation of each class of UCs.
 * @return A map , that maps a Class/UC, to a certain occupation.
 * @details Time Complexity: O(1).
 */
std::unordered_map<std::pair<std::string, std::string>, int, PairHash> Schedule::getUcOcupation() {
    return UcOcupation;
}

/**
 * @brief Get the class attendance.
 * @return The map that for each Class Code, has the name of every student attending it.
 * @details Time Complexity: O(1).
 */
std::unordered_map<std::string, unordered_set<std::string>> Schedule::getClassAttendance() {
    return ClassAttendance;
}

/**
 * @brief Get the balance.
 * @return The difference between the fullest class and emptiest class of a UC.
 * @details Time Complexity: O(1).
 */
int Schedule::getBalance() const {
    return Balance;
}

/**
 * @brief Sets the map of student schedules.
 * @param StudentSchedules_ The map of student schedules to set.
 * @details Time Complexity: O(1).
 */
void Schedule::setStudentSchedules(std::unordered_map<Student, std::vector<UC>>  StudentSchedules_) {
    StudentSchedules = std::move(StudentSchedules_);
}

/**
 * @brief Sets the map of class schedules.
 * @param ClassSchedules_ The map of class schedules to set.
 * @details Time Complexity: O(1).
 */
void Schedule::setClassSchedules(std::unordered_map<Class, std::vector<UC>>  ClassSchedules_) {
    ClassSchedules = std::move(ClassSchedules_);
}

/**
 * @brief Set the UC occupation.
 * @param UcOcupation_ The map of UC occupation to set.
 * @details Time Complexity: O(1).
 */
void Schedule::setUcOcupation(unordered_map<pair<basic_string<char>, basic_string<char>>, int, PairHash> UcOcupation_)
{
    UcOcupation = UcOcupation_;
}

/**
 * @brief Set the class attendance.
 * @param ClassAttendance_ The map of class attendance to set.
 * @details Time Complexity: O(1).
 */
void Schedule::setClassAttendance(std::unordered_map<std::string, unordered_set<std::string>> ClassAttendance_)
{
    ClassAttendance = std::move(ClassAttendance_);
}

/**
 * @brief Set the balance.
 * @param balance The balance value to set.
 * @details Time Complexity: O(1).
 */
void Schedule::setBalance(int balance)
{
    Balance = balance;
}


/**
 * @brief Sets the vector of UCs.
 * @param ucs_ The vector of UCs to set.
 * @details Time Complexity: O(1).
 */
void Schedule::setUCs(std::vector<UC> ucs_)
{
    Ucs = ucs_;
}


/**
 * @brief Calculates the balance between the smallest and the biggest class of a given UC.
 * @details This function calculates the balance based on class attendance, subtracting the value of the emptiest class to the fullest one in a given UC.
 * @details Time Complexity: 0(n), where n is the number of classes in ClassAttendance.
 */
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

/**
 * @brief Searches for a student in the schedule based on their name.
 * @param student_name The name of the student to find.
 * @return True if the student is found, false otherwise.
 * @details Time Complexity: O(1) to 0(n) in case of hash collision, where n is the number of students.
 */
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

/**
 * @brief Fetches the student corresponding to the given Student object, used normally with an default Student , just with the Name set.
 * @param StudentToFind The Student object to find in the schedule, with only the Name set, the rest is default.
 * @return An iterator pointing to the found student in the student schedules map, whose Name matches with the one in the parameter.
 */
std::unordered_map<Student, std::vector<UC>>::iterator Schedule::FetchStudent(Student StudentToFind)
{
    if(FindStudentinSchedule(StudentToFind.getName()))
    {
        return StudentSchedules.find(StudentToFind);
    }
}

/**
 * @brief Fetches the class corresponding to the given Class object,used normally with an default Class , just with the Class Code set.
 * @param ClassToFind The Class object to find in the schedule, with only the Class Code set, the rest is default
 * @return An iterator pointing to the found class in the class schedules map,which Class Code matches with the one in the parameter.
 */
std::unordered_map<Class, std::vector<UC>>::iterator Schedule::FetchClass(Class ClassToFind)
{
    if(FindClassinSchedule(ClassToFind.getClassCode()))
    {
        return ClassSchedules.find(ClassToFind);
    }
}

/**
 * @brief Fetches the student corresponding to the given Student object, used normally with an default Student , just with the ID set.
 * @param StudentToFind The Student object to find in the schedule, with only the ID set, the rest is default.
 * @return An iterator pointing to the found student in the student schedules map, whose ID matches with the one in the parameter.
 */
Student Schedule::FindStudentinSchedulebyID(int ID) {

    for (const auto& student : StudentSchedules) {
        if (student.first.getId() == ID) {
            return student.first;
        }
    }
    return Student();
}

/**
 * @brief Finds a class in the schedule by its code.
 * @param ClassCode The code of the class to find.
 * @return True if the class is found, false otherwise.
 * @details Time Complexity: O(1) to 0(n) in case of hash collision, where n is the number of classes.
 */
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

/**
 * @brief Finds a UC in the schedule and prompt the user to choose multiple instances of a class (T,TP,P) are found and is used to allocate/remove classes of a Given UC.
 * @param targetUC The UC to find in the schedule.
 * @details Time Complexity: O(n), where n is the number of UCs.
 */
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
    if(ucs.empty())
    {
        targetUC = UC();
        return;
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

/**
 * @brief Finds a UC in the schedule and prompt the user to choose multiple instances of a class (T,TP,P) are found and is used to allocate/remove students from a UC.
 * @param student The student for whom to find the UC.
 * @param targetUC The UC to find in the student's schedule.
 * @details Time Complexity: O(n), where n is the number of UCs in a StudentSchedule.
 */
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
    if(ucs.empty())
    {
        targetUC = UC();
        return;
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

/**
 * @brief Compares two UCs based on their day and duration.
 * @param uc1 The first UC to compare.
 * @param uc2 The second UC to compare.
 * @return True if uc1 is earlier than uc2, based on day and duration; false otherwise.
 */
bool Schedule::compare_day(const UC &uc1, const UC &uc2){
    std::map<std::string, int> dayMap = {{"Monday", 1}, {"Tuesday", 2}, {"Wednesday", 3}, {"Thursday", 4}, {"Friday", 5}};
    if(dayMap[uc1.getDate().Day] != dayMap[uc2.getDate().Day]){
        return dayMap[uc1.getDate().Day] < dayMap[uc2.getDate().Day];
    }else{
        return uc1.getDate().Duration.first < uc2.getDate().Duration.first;
    }
}


/**
 * @brief Finds students with at least a specified number of UCs of type "TP".
 * @param n The minimum number of UCs required, offset by 49, since it is a char.
 * @param students The vector containing all students.
 * @details Time Complexity: O(n*m)=O(n²), where n is the number of Pairs in Student Schedules and m is the number of ucs of each pair
 */
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
/**
 * @brief Switches the class of a student in the same UC.
 * @param student1 The student for whom to switch the class.
 * @param old_uc The UC object from which to switch the class.
 * @param new_uc The UC object to which the class is switched.
 * @details Time Complexity: O(n), where n is the number of UCs on a Schedule of a Student
 */
void Schedule::SwitchClass(Student &student1, UC& old_uc, UC &new_uc) {

    vector<UC> tempV;

    ClassAttendance[old_uc.getRespectiveClass()].erase(student1.getName());
    ClassAttendance[new_uc.getRespectiveClass()].insert(student1.getName());

    UcOcupation[{old_uc.getUcCode() , old_uc.getRespectiveClass()}] -= 1;
    UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
    int tempBalance = Balance;
    CalculateBalance();

    if(Balance < tempBalance && UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] <= MAX_CAP)
    {
        for(UC uc : StudentSchedules[student1])
        {
            if(!(new_uc.getType() == "T" || uc.getType() == "T"))
            {
                if(new_uc.getType() == uc.getType() || (new_uc.getType() == "TP" && uc.getType() == "PL") || (new_uc.getType() == "PL" && uc.getType() == "TP"))
                {
                    if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
                    {
                        std::cout << "Schedule not compatible with other classes";
                        return;
                    }
                }
            }
        }
        for(UC Uc : StudentSchedules[student1])
        {
            if(Uc == old_uc && old_uc.getDate().Day == Uc.getDate().Day && old_uc.getDate().Duration.first == Uc.getDate().Duration.first && old_uc.getDate().Duration.second == Uc.getDate().Duration.second)
            {
                tempV.push_back(new_uc);
            }
            else
            {
                tempV.push_back(Uc);
            }
        }
        StudentSchedules[student1] = tempV;
    }
    else {
        ClassAttendance[old_uc.getRespectiveClass()].insert(student1.getName());
        ClassAttendance[new_uc.getRespectiveClass()].erase(student1.getName());

        UcOcupation[{old_uc.getUcCode() , old_uc.getRespectiveClass()}] += 1;
        UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] -= 1;
        std::cout << "Balance Disrupted";
        return;
    }

}

/**
 * @brief Switches the UC of a student from an old UC to a new UC.
 * @param student1 The student for whom to switch the UC.
 * @param new_uc The new UC to which the UC is switched.
 * @param ex_uc The old UC from which to switch the UC.
 * @details Time Complexity: O(n), where n is the number of UCs in a Student's Schedule.
 */
void Schedule::SwitchUc(Student student1, UC new_uc, UC ex_uc)
{
    std::vector<UC> tempV;
    auto ucs_ = StudentSchedules[student1];
    if(FindStudentinSchedule(student1.getName()))
    {
        for(auto uc : StudentSchedules[student1])
        {
            if(!(new_uc.getType() == "T" || uc.getType() == "T") && uc.getRespectiveClass() != "EMPTY")
            {
                if(new_uc.getType() == uc.getType() || (new_uc.getType() == "TP" && uc.getType() == "PL") || (new_uc.getType() == "PL" && uc.getType() == "TP"))
                {
                    if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
                    {
                        std::cout << "Schedule not compatible with other classes";
                        return;
                    }
                }
            }
        }
        int tempBalance = Balance;
        ClassAttendance[ex_uc.getRespectiveClass()].erase(student1.getName());
        ClassAttendance[new_uc.getRespectiveClass()].insert(student1.getName());

        UcOcupation[{ex_uc.getUcCode() , ex_uc.getRespectiveClass()}] -= 1;
        UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
        CalculateBalance();

        if(Balance <= tempBalance && UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] <= MAX_CAP)
        {
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
        }else
        {
            ClassAttendance[ex_uc.getRespectiveClass()].insert(student1.getName());
            ClassAttendance[new_uc.getRespectiveClass()].erase(student1.getName());

            UcOcupation[{ex_uc.getUcCode() , ex_uc.getRespectiveClass()}] += 1;
            UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] -= 1;
            CalculateBalance();
            StudentSchedules[student1] = ucs_;
            std::cout << "Balance Disrupted";
            return ;
        }
    }
    StudentSchedules[student1] = tempV;

}

/**
 * @brief Adds a new UC to a student's schedule.
 * @param student1 The student to whom the UC is added.
 * @param new_uc The new UC to be added to the student's schedule.
 * @details Time Complexity: O(n), where n is the number of UCs in a Student's Schedule.
 */
void Schedule::AddUC(Student student1, UC new_uc) {
    if(FindStudentinSchedule(student1.getName()) && student1.getClassesToUcs().size() < 7)
    {
        for(UC uc : StudentSchedules[student1])
        {
            if(!(new_uc.getType() == "T" || uc.getType() == "T"))
            {
                if(new_uc.getType() == uc.getType() || (new_uc.getType() == "TP" && uc.getType() == "PL") || (new_uc.getType() == "PL" && uc.getType() == "TP"))
                {
                    if(Date::Overlaps(uc.getDate() , new_uc.getDate()))
                    {
                        std::cout << "Schedule not compatible with other classes";
                        return;
                    }
                }
            }
        }

        ClassAttendance[new_uc.getRespectiveClass()].insert(student1.getName());
        UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] += 1;
        CalculateBalance();
        if(UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] <= MAX_CAP)
        {
            StudentSchedules[student1].push_back(new_uc);
        }
        else
        {
            ClassAttendance[new_uc.getRespectiveClass()].erase(student1.getName());
            UcOcupation[{new_uc.getUcCode() , new_uc.getRespectiveClass()}] -= 1;
            CalculateBalance();
            std::cout << "Balance Disrupted";
            return;
        }
    }
}

/**
 * @brief Removes a UC from a Student's Schedule.
 * @param student1 The student from whom the UC is removed.
 * @param ex_uc The UC to be removed from the student's schedule.
 * @details Time Complexity: O(n), where n is the number of UCs in a Student's Schedule.
 */
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

    for(auto uc : StudentSchedules[student1])
    {
        if(uc.getRespectiveClass() == ex_uc.getRespectiveClass())
        {
            ClassAttendance[ex_uc.getRespectiveClass()].insert(student1.getName());
        }
    }

    UcOcupation[{ex_uc.getUcCode() , ex_uc.getRespectiveClass()}] -= 1;

    CalculateBalance();
}

/**
 * @brief Removes a class from a student's schedule, setting all remaining UCs class to "EMPTY".
 * @param student1 The student from whom the class is removed.
 * @param uc The UC corresponding to the class to be removed.
 * @details Time Complexity: O(n), where n is the number of UCs in a Student's Schedule.
 */
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

    for(auto uc : StudentSchedules[student1])
    {
        if(uc.getRespectiveClass() == uc.getRespectiveClass())
        {
            ClassAttendance[uc.getRespectiveClass()].insert(student1.getName());
        }
    }

    UcOcupation[{uc.getUcCode() , uc.getRespectiveClass()}] -= 1;
}

/**
 * @brief Adds a class to a Student's Schedule.
 * @param student1 The student to whom the class is added.
 * @param uc The UC corresponding to the class to be added.
 * @details Time Complexity: O(n), where n is the number of UCs in a Student's Schedule.
 */
void Schedule::AddClass(Student student1, UC &uc)
{
    vector<UC> tempV;
    auto it = StudentSchedules[student1];
    if (FindStudentinSchedule(student1.getName()))
    {

        ClassAttendance[uc.getRespectiveClass()].insert(student1.getName());
        UcOcupation[{uc.getUcCode() , uc.getRespectiveClass()}] += 1;
        CalculateBalance();
        if(UcOcupation[{uc.getUcCode() , uc.getRespectiveClass()}] <= MAX_CAP)
        {
            for(auto ucs : it)
            {
                if(ucs.getRespectiveClass() == "EMPTY")
                {
                    if(ucs.getUcCode() == uc.getUcCode())
                    {
                        tempV.push_back(uc);

                    }
                }
                else
                {
                    tempV.push_back(ucs);
                }
            }
        }
        else
        {
            ClassAttendance[uc.getRespectiveClass()].erase(student1.getName());
            UcOcupation[{uc.getUcCode() , uc.getRespectiveClass()}] -= 1;
            std::cout << "Balance Disrupted";
            return;
        }

    }
    StudentSchedules[student1] = tempV;

    for(auto uc : StudentSchedules[student1])
    {
        for(auto uc_ : StudentSchedules[student1])
        {
            if(!(uc_.getType() == "T" || uc.getType() == "T"))
            {
                if(uc_.getType() == uc.getType() || (uc_.getType() == "TP" && uc.getType() == "PL") || (uc_.getType() == "PL" && uc.getType() == "TP"))
                {
                    if(Date::Overlaps(uc.getDate() , uc_.getDate()))
                    {
                        std::cout << "Schedule not compatible with other classes";
                        return;
                    }
                }
            }
        }
    }
}

