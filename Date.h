//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_DATE_H
#define PROJETO_DATE_H

using namespace std;
#include "string"

struct Date
{
public:
    std::pair<double , double> Duration; //1º hora começa 2º hora que começa + hora que acaba
    std::string Day;

    static bool Overlaps(const Date& date1, const Date& date2) {
        // Check if the days are the same
        if (date1.Day != date2.Day) {
            return false; // Days are different, no overlap
        }

        // Check if the end time of the first duration is earlier than the start time of the second duration
        if (date1.Duration.second <= date2.Duration.first) {
            return false; // No overlap
        }

        // Check if the start time of the first duration is later than the end time of the second duration
        if (date1.Duration.first >= date2.Duration.second) {
            return false; // No overlap
        }
        // If none of the above conditions are met, there is an overlap
        return true;
    }
};

#endif //PROJETO_DATE_H