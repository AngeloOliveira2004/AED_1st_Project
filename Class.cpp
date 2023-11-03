#include "Class.h"

#include <utility>

/**
 * @class Class
 * @brief A class of a given UC.
 */

/**
    * @brief Default constructor for Class.
    */
Class::Class() : ClassCode(""), UCs(){}

/**
    * @brief Parameterized constructor for Class.
    * @param classCode The respective code of the class.
    * @param students Set of student names in the class.
    * @param ucs Vector of UC codes of this class.
    */
Class::Class(std::string  classCode, const std::unordered_set<std::string>& students, const std::vector<std::string>& ucs)
        : ClassCode(std::move(classCode)), UCs(ucs){}

/**
    * @brief Getter for the ClassCode.
    * @return The class code.
    */
const std::string& Class::getClassCode() const {
    return ClassCode;
}

/**
    * @brief Getter for the vector of UCs.
    * @return The vector of UC codes.
    */
const std::vector<std::string>& Class::getUCs() const {
    return UCs;
}

/**
    * @brief Setter for the ClassCode.
    * @param classCode The class code to set.
    */
void Class::setClassCode(const std::string& classCode) {
    ClassCode = classCode;
}

/**
    * @brief Setter for the vector of UCs.
    * @param ucs The vector of UCs to set.
    */
void Class::setUCs(const std::vector<std::string>& ucs) {
    UCs = ucs;
}
/**
    * @brief Overloaded less than operator for comparing two Class objects.
    * @param other The other Class object used on the comparison.
    * @return True if the ClassCode of the original ("this") object is less than the other's ClassCode.
    */
bool Class::operator<(const Class &other) const
{
    return this->ClassCode < other.ClassCode;
}

/**
     * @brief Overloaded equality operator for comparing two Class objects.
     * @param other The other Class object used on the comparison.
     * @return True if the ClassCode of the original ("this") object is equal to the other's ClassCode.
     */
bool Class::operator==(const Class &other) const
{
    return this->ClassCode == other.ClassCode;
}

/**
     * @brief Populates the schedule for a class based on all UCs.
     * @brief Has O(n) complexity where n is the size of allUCs vector
     * @param class_ The Class object for which to populate the schedule.
     * @param allUCs The vector of all UCs in the course.
     * @return A pair containing the class and the vector of UCs for that class.
     */
std::pair<Class, std::vector<UC>> Class::populateSchedule(Class &class_, const std::vector<UC>& allUCs)
{
    std::pair<Class, std::vector<UC>> Result;
    Result.first = class_;

    std::unordered_set<std::string> ucCodesSet(class_.getUCs().begin(), class_.getUCs().end());

    for (const UC& uc : allUCs) {
        if (uc.getRespectiveClass() == class_.getClassCode() && ucCodesSet.count(uc.getUcCode()) > 0) {
            Result.second.push_back(uc);
        }
    }
    return Result;
}

/**
     * @brief Sorts a vector of Class objects by ClassCode.
     * @param classes The vector of Class objects to be sorted.
     */
void Class::sort(std::vector<Class> &classes)
{
    auto compareClassesByName = [](const Class& class1, const Class& class2) {
        return class1.getClassCode() < class2.getClassCode();
    };

    std::sort(classes.begin(), classes.end(), compareClassesByName);
}

/**
     * @brief Overloaded assignment operator for assigning one Class ClassCode and Respective UCs from another.
     * @param other The Class object used on the assigning.
     */
void Class::operator=(const Class &other)  {
    ClassCode = other.ClassCode;
    UCs = other.UCs;
}
