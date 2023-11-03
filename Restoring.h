#ifndef RESTORING_H
#define RESTORING_H

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include "Schedule.h"

/**
 * @headerfile Restoring
 * @brief The header file for the Restoring function.
 */
class Student;
class Class;
class UC;

/**
     * @brief Template specialization for the std::hash template for the pair<string, string> type.
     */
namespace std {
    template <>
    struct hash<pair<string, string>> {
        size_t operator()(const pair<string, string>& p) const {
            return hash<string>()(p.first) ^ hash<string>()(p.second);
        }
    };
}

class Restoring {
public:
    Restoring() = default;
    Restoring(Schedule &schedule, vector<Student> &students, vector<Class> &classes, vector<UC> &ucs,vector<Schedule> &schedules,pair<std::unordered_map<std::string, unordered_set<std::string>>, std::unordered_map<std::pair<std::string, std::string>, int, PairHash>> &attendancePair);

    Schedule mySchedule_c;
    std::vector<Student> students_c;
    std::vector<Class> classes_c;
    std::vector<UC> ucs_c;
    std::vector<Schedule> schedules_c;
    std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>> AttendancePair_c;

    void restore(Schedule &mySchedule, vector<Student> &students, vector<Class> &classes, vector<UC> &ucs,vector<Schedule> &schedules,pair<std::unordered_map<std::string, unordered_set<std::string>>, std::unordered_map<std::pair<std::string, std::string>, int, PairHash>> &AttendancePair);
};

#endif /* RESTORING_H */
