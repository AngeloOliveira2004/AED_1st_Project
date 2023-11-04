/**
 * @file  Student.h
 * @brief This file contains the declaration of the Student class, along with related utility functions and operators.
 */

#ifndef PROJETO__STUDENT_H
#define PROJETO__STUDENT_H

#include "stdafx.h"

/**
 * @class Student
 * @brief Represents a student with an ID, name, and a vector of classes to UCs.
 */
class Student {
private:
    int Id; ///< The student's ID.
    std::string Name; ///< The student's name.
    std::vector<std::pair<std::string, std::string>> ClassesToUcs; ///< vector of classes to UCs.

public:
    /**
     * @brief Default constructor for the Student class.
     */
    Student();

    /**
     * @brief Parameterized constructor for the Student class.
     * @param id The student's ID.
     * @param name The student's name.
     * @param year The student's year.
     */
    Student(int id, const std::string& name, char year);

    /**
     * @return The student's ID.
     */
    int getId() const;

    /**
     * @return The student's name.
     */
    const std::string& getName() const;

    /**
     * @return The vector of classes to UCs for the student.
     */
    std::vector<std::pair<std::string, std::string>> getClassesToUcs() const;

    // Setter functions
    /**
     * @brief Set the student's ID.
     * @param id The student's ID.
     */
    void setId(int id);

    /**
     * @brief Set the student's name.
     * @param name The student's name.
     */
    void setName(const std::string& name);

    /**
     * @brief Set the vector of classes to UCs for the student.
     * @param ClassesToUcs_ The vector of classes to UCs.
     */
    void setClassesToUcs(std::vector<std::pair<std::string, std::string>> ClassesToUcs_);

    // Quality of life functions
    /**
     * @brief Sort a vector of students.
     * @param students The vector of students to be sorted.
     */
    static void sort(std::vector<Student>& students);

    /**
     * @brief Compare students by their ID.
     * @param student1 The first student.
     * @param student2 The second student.
     * @return True if the first student's ID is less than the second student's ID, otherwise false.
     */
    static bool compareStudentsByID(const Student& student1, const Student& student2);

    // Operators overload
    bool operator >(const Student& other) const;
    bool operator<(const Student& other) const;
    bool operator ==(const Student& other) const;

    /**
     * @brief Populate the schedule for a student based on a vector of UCs.
     * @param student The student for whom the schedule is to be populated.
     * @param allUCs The vector of all UCs available.
     * @return A pair containing the student's schedule and the vector of UCs they are enrolled in.
     */
    static std::pair<Student, std::vector<UC>> populateScheduleStudent(Student& student, const std::vector<UC>& allUCs);
};

namespace std {
    /**
     * @brief Hash function specialization for Student objects.
     */
    template <>
    struct hash<Student> {
        /**
         * @param student The Student object to hash.
         * @return The hash value for the Student based on their name.
         */
        size_t operator()(const Student& student) const {
            size_t nameHash = std::hash<std::string>{}(student.getName());
            return nameHash; // Combine the hashes appropriately
        }
    };
}

#endif //PROJETO__STUDENT_H
