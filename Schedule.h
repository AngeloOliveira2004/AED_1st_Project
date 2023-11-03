#ifndef PROJETO_SCHECULE_H
#define PROJETO_SCHECULE_H

#include "stdafx.h"

/**
 * @headerfile Schedule
 * @brief The header of the schedule of UCs for students and classes.
 */
class Schedule
{
private:

    /**
     * @brief A map representing the schedules of students, where the key is a Student object and the value is a vector of UC objects.
     */
    std::unordered_map<Student, std::vector<UC>> StudentSchedules;

    /**
     * @brief A map representing the schedules of classes, where the key is a Class object and the value is a vector of UC objects.
     */
    std::unordered_map<Class, std::vector<UC>> ClassSchedules;

    /**
     * @brief A map representing the occupation of UCs, where the key is a pair of strings representing the UC code and the respective class, and the value is the occupation count.
     */
    std::unordered_map<std::pair<std::string, std::string>, int, PairHash> UcOcupation;

    /**
     * @brief A map representing the class attendance, where the key is a string representing the class code, and the value is an unordered set of strings representing the students attending the class.
     */
    std::unordered_map<std::string, std::unordered_set<std::string>> ClassAttendance;

    /**
     * @brief A vector representing the UCs.
     */
    std::vector<UC> Ucs;

    /**
     * @brief An integer representing the balance.
     */
    int Balance;

    /**
     * @brief A constant integer representing the maximum capacity.
     */
    const int MAX_CAP = 30;  ///< Maximum capacity constant.

public:
    // Constructor that takes a vector of UC objects as a pointer
    Schedule() = default;
    Schedule(std::unordered_map<Student, std::vector<UC>> studentClasses_,
             std::unordered_map<Class, std::vector<UC>> classSchedules_);

    // Get a reference to the vector of UC objects
    [[nodiscard]] std::unordered_map<Student, std::vector<UC>> getStudentSchedules();
    [[nodiscard]] std::unordered_map<Class, std::vector<UC>> getClassSchedules();
    [[nodiscard]] std::unordered_map<std::pair<std::string,std::string> , int, PairHash> getUcOcupation();
    [[nodiscard]] std::unordered_map<std::string , unordered_set<std::string>> getClassAttendance();
    [[nodiscard]] int getBalance() const;

    void setStudentSchedules(std::unordered_map<Student, std::vector<UC>> studentClasses_);
    void setClassSchedules(std::unordered_map<Class, std::vector<UC>> classSchedules_);
    void setUcOcupation(
            unordered_map<pair<basic_string<char>, basic_string<char>>, int, PairHash> UcOcupation_);
    void setClassAttendance(std::unordered_map<std::string , unordered_set<std::string>> ClassAttendance_);
    void setBalance(int balance);
    void setUCs(std::vector<UC> ucs_);

    void StudentsInAtLeastNUcs(char n , std::vector<Student>& students);
    void CalculateBalance();
    bool FindStudentinSchedule(std::string student_name);
    bool FindClassinSchedule(std::string ClassCode);
    std::unordered_map<Student, std::vector<UC>>::iterator FetchStudent(Student StudentToFind);
    std::unordered_map<Class, std::vector<UC>>::iterator FetchClass(Class ClassToFind);
    Student FindStudentinSchedulebyID(int ID);
    void FindUC(UC &targetUC);
    void FindUCinStudent(Student student , UC &targetUC);

    static bool compare_day(const UC &uc1, const UC &uc2);

    void SwitchClass(Student &student1, UC& old_uc, UC &new_uc);
    void SwitchUc(Student student1 , UC new_uc , UC ex_uc);
    void AddUC(Student student1 , UC new_uc);
    void RemoveUC(Student student1 , UC ex_uc);
    void RemoveClass(Student student1 , UC &uc);
    void AddClass(Student student1 , UC &uc);


};

#endif //PROJETO_SCHECULE_H