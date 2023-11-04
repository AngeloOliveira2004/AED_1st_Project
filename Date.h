/**
 * @file Date.h
 * @brief A header file used to represent a struct of date, along with related utility functions.
 */

#ifndef PROJETO_DATE_H
#define PROJETO_DATE_H

using namespace std;
#include "string"

/**
 * @brief The struct representing a specific date of a lesson.
 */
struct Date
{
public:
    std::pair<double, double> Duration; /**< The duration represented as a pair of doubles, the first being the starting hour of the lesson and the second being the end hour. */
    std::string Day; /**< The day of a given lesson. */

    /**
     * @brief Checks if the Date of two lessons overlap.
     * @param date1 The Date of the first lesson.
     * @param date2 The Date of the second lesson.
     * @return True if the two lessons overlap, otherwise false.
     */
    static bool Overlaps(const Date& date1, const Date& date2) {



        if (date1.Day != date2.Day) {
            return false;
        }

        if (date1.Duration.second <= date2.Duration.first) {
            return false;
        }

        if (date1.Duration.first >= date2.Duration.second) {
            return false;
        }
        return true;
    }
};

#endif //PROJETO_DATE_H