#include "UC.h"

/**
 * @brief Default constructor for the UC class.
 * Initializes all fields to empty values.
 */
UC::UC() : UcCode(""), Type(""), RespectiveClass(""), Date_() {}

/**
 * @brief Parameterized constructor for the UC class.
 * @param ucCode The code of the UC.
 * @param type The type of the UC.
 * @param respectiveClass The respective class of the UC.
 * @param date The date associated with the UC.
 */
UC::UC(const std::string& ucCode, const std::string& type, const std::string& respectiveClass, int occupation, const Date& date)
        : UcCode(ucCode), Type(type), RespectiveClass(respectiveClass), Date_(date) {}

/**
 * @brief Get the code of the UC.
 * @return The code of the UC.
 */
const std::string& UC::getUcCode() const {
    return UcCode;
}

/**
 * @brief Get the type of the UC.
 * @return The type of the UC.
 */
const std::string& UC::getType() const {
    return Type;
}

/**
 * @brief Get the respective class of the UC.
 * @return The respective class of the UC.
 */
const std::string& UC::getRespectiveClass() const {
    return RespectiveClass;
}

/**
 * @brief Get the date associated with the UC.
 * @return The date associated with the UC.
 */
const Date& UC::getDate() const {
    return Date_;
}

/**
 * @brief Set the code of the UC.
 * @param ucCode The code of the UC.
 */
void UC::setUcCode(const std::string& ucCode) {
    UcCode = ucCode;
}

/**
 * @brief Set the type of the UC.
 * @param type The type of the UC.
 */
void UC::setType(const std::string& type) {
    Type = type;
}

/**
 * @brief Set the respective class of the UC.
 * @param respectiveClass The respective class of the UC.
 */
void UC::setRespectiveClass(const std::string& respectiveClass) {
    RespectiveClass = respectiveClass;
}

/**
 * @brief Set the date associated with the UC.
 * @param date The date associated with the UC.
 */
void UC::setDate(const Date& date) {
    Date_ = date;
}

/**
 * @brief Check if the UC has a value (non-empty code).
 * @return True if the UC has a value, otherwise false.
 */
bool UC::hasValue() {
    return UcCode != "";
}

/**
 * @brief Compare this UC with another UC (less than) based on their Date_ field.
 * @param other The other UC to compare.
 * @return True if this UC's Date_ is less than the other UC's Date_, otherwise false.
 * @note The time complexity for this comparison is O(1).
 */
bool UC::operator<(const UC other) const {
    return Date_.Day < other.getDate().Day; // Assuming the UC name is used for comparison
}

/**
 * @brief Compare this UC with another UC for equality.
 * @param other The other UC to compare.
 * @return True if this UC's code, type, and respective class are equal to the other UC's, otherwise false.
 * @note The time complexity for this comparison is O(1).
 */
bool UC::operator==(const UC other) const {
    return (UcCode == other.UcCode) && (Type == other.Type) && (RespectiveClass == other.RespectiveClass);
}

/**
 * @brief Assignment operator for UC objects.
 * @param other The other UC to assign.
 * @note The time complexity for this assignment is O(1).
 */
bool UC::operator=(const UC other) {
    UcCode = other.UcCode;
    Type = other.Type;
    RespectiveClass = other.RespectiveClass;
    Date_ = other.Date_;
}
