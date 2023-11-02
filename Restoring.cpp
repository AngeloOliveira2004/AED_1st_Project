//
// Created by angelo on 02-11-2023.
//

#include "Restoring.h"
#include "stdafx.h"
#include "Schedule.h"



Restoring::Restoring(Schedule& schedule, std::vector<Student>& students, std::vector<Class>& classes, std::vector<UC>& ucs, std::vector<Schedule>& schedules, std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>>& attendancePair)
: mySchedule_c(schedule), students_c(students), classes_c(classes), ucs_c(ucs), schedules_c(schedules), AttendancePair_c(attendancePair) {}

void Restoring::restore(Schedule &mySchedule, std::vector<Student> &students, std::vector<Class> &classes,std::vector<UC> &ucs, std::vector<Schedule> &schedules,std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>> &AttendancePair) {
    mySchedule = mySchedule_c;
    students = students_c;
    classes = classes_c;
    ucs = ucs_c;
    schedules = schedules_c;
    AttendancePair.first = AttendancePair_c.first;
    AttendancePair.second = AttendancePair_c.second;
}
