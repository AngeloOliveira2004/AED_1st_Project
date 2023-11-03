#include "Restoring.h"
#include "stdafx.h"
#include "Schedule.h"
/**
 * @class Restoring
 * @brief A class for restoring data, it is used when we need to go back to a older version of the runtime schedule version we are working with.
 */

/**
     * @brief Restoring constructor, used to save all the private members used on the UI.
     * @param schedule Reference to the Schedule object that we wish to make a backup.
     * @param students Reference to the vector of Student objects that we wish to make a backup.
     * @param classes Reference to the vector of Class objects that we wish to make a backup.
     * @param ucs Reference to the vector of UC objects that we wish to make a backup.
     * @param schedules Reference to the vector of Schedule objects that we wish to make a backup.
     * @param attendancePair Reference to the attendance pair that we wish to make a backup.
     */
Restoring::Restoring(Schedule& schedule, std::vector<Student>& students, std::vector<Class>& classes, std::vector<UC>& ucs, std::vector<Schedule>& schedules, std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>>& attendancePair)
: mySchedule_c(schedule), students_c(students), classes_c(classes), ucs_c(ucs), schedules_c(schedules), AttendancePair_c(attendancePair) {}

/**
    * @brief Restores the data backup stored in a Restoring object to the main Schedule.
    * @param mySchedule The Schedule object to be restored.
    * @param students The vector of Student objects to be restored.
    * @param classes The vector of Class objects to be restored.
    * @param ucs The vector of UC objects to be restored.
    * @param schedules The vector of Schedule objects to be restored.
    * @param attendancePair The attendance pair to be restored.
    */
void Restoring::restore(Schedule &mySchedule, std::vector<Student> &students, std::vector<Class> &classes,std::vector<UC> &ucs, std::vector<Schedule> &schedules,std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>> &AttendancePair) {
    mySchedule = mySchedule_c;
    students = students_c;
    classes = classes_c;
    ucs = ucs_c;
    schedules = schedules_c;
    AttendancePair.first = AttendancePair_c.first;
    AttendancePair.second = AttendancePair_c.second;
}
