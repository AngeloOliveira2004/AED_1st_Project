#include "Student.h"

/**
 * @brief Default constructor for the Student class.
 */
Student::Student() : Id(0), Name("") {}

/**
 * @brief Parameterized constructor for the Student class.
 * @param id The student's ID.
 * @param name The student's name.
 * @param year The student's year.
 */
Student::Student(int id, const std::string& name, char year) : Id(id), Name(name) {}

/**
 * @brief Get the student's ID.
 * @return The student's ID.
 */
int Student::getId() const {
    return Id;
}

/**
 * @brief Get the student's name.
 * @return The student's name.
 */
const std::string& Student::getName() const {
    return Name;
}

/**
 * @brief Get the list of classes to UCs for the student.
 * @return The list of classes to UCs.
 */
std::vector<std::pair<std::string, std::string>> Student::getClassesToUcs() const {
    return ClassesToUcs;
}

/**
 * @brief Set the student's ID.
 * @param id The student's ID.
 */
void Student::setId(int id) {
    Id = id;
}

/**
 * @brief Set the student's name.
 * @param name The student's name.
 */
void Student::setName(const std::string& name) {
    Name = name;
}

/**
 * @brief Set the list of classes to UCs for the student.
 * @param ClassesToUcs_ The list of classes to UCs.
 */
void Student::setClassesToUcs(const std::vector<std::pair<std::string, std::string>> ClassesToUcs_) {
    ClassesToUcs = ClassesToUcs_;
}

/**
 * @brief Compare students by their ID (greater than).
 * @param other The other student to compare.
 * @return True if this student's ID is greater than the other student's ID, otherwise false.
 */
bool Student::operator>(const Student& other) const {
    return Id > other.Id;
}

/**
 * @brief Compare students by their ID (less than).
 * @param other The other student to compare.
 * @return True if this student's ID is less than the other student's ID, otherwise false.
 */
bool Student::operator<(const Student& other) const {
    return Id < other.Id;
}

/**
 * @brief Compare students by their name for equality.
 * @param other The other student to compare.
 * @return True if this student's name is equal to the other student's name, otherwise false.
 */
bool Student::operator==(const Student& other) const {
    return Name == other.Name;
}

/**
 * @brief Sort a vector of students based on their IDs.
 * @param students The vector of students to be sorted.
 * @note The time complexity depends on the sorting algorithm used, which is O(n log n) for typical sorting algorithms.
 */
void Student::sort(std::vector<Student>& students) {
    std::sort(students.begin(), students.end(), compareStudentsByID);
}

/**
 * @brief Compare students by their name for sorting purposes.
 * @param student1 The first student to compare.
 * @param student2 The second student to compare.
 * @return True if the first student's name is less than the second student's name, otherwise false.
 */
bool Student::compareStudentsByID(const Student &student1, const Student &student2) {
    return student1.getName() < student2.getName();
}

/**
 * @brief Populate the schedule for a student based on a list of UCs.
 * @param student The student for whom the schedule is to be populated.
 * @param allUCs The list of all UCs available.
 * @return A pair containing the student's schedule and the list of UCs they are enrolled in.
 * @note The time complexity of this function is O(N*M), where N is the size of the `allUCs` vector, and M is the size of the `ucMap`.
 */
std::pair<Student, std::vector<UC>> Student::populateScheduleStudent(Student &student, const std::vector<UC> &allUCs) {
    std::unordered_map<std::string, std::unordered_set<std::string>> ucMap;

    std::pair<Student, std::vector<UC>> Result;
    Result.first = student;

    for (const UC& uc : allUCs) {
        ucMap[uc.getUcCode()].insert(uc.getRespectiveClass());
    }

    for (const auto& pair1 : student.getClassesToUcs()) {
        const std::string& ucCode = pair1.second;
        const std::string& ucClass = pair1.first;

        if (ucMap.count(ucCode) > 0 && ucMap[ucCode].count(ucClass) > 0) {
            for (const UC& uc : allUCs) {
                if (uc.getUcCode() == ucCode && uc.getRespectiveClass() == ucClass) {
                    Result.second.push_back(uc);
                }
            }
        }
    }
    return Result;
}

