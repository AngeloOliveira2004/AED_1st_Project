/**
 * @file UC.h
 * @brief Header file for the UC class, along with related utility functions and operators.
 */

#ifndef PROJETO_UC_H
#define PROJETO_UC_H

#include <string>
#include "Date.h"

/**
 * @class UC
 * @brief Represents a University Course (UC) with its code, type, respective class, and date information.
 */
class UC {
private:
    std::string UcCode; ///< The code of the UC.
    std::string Type; ///< The type of the UC.
    std::string RespectiveClass; ///< The respective class of the UC.
    Date Date_; ///< The date associated with the UC.

public:
    // Constructors

    /**
     * @brief Default constructor for the UC class.
     */
    UC();

    /**
     * @brief Parameterized constructor for the UC class.
     * @param ucCode The code of the UC.
     * @param type The type of the UC.
     * @param respectiveClass The respective class of the UC.
     * @param date The date associated with the UC.
     */
    UC(const std::string& ucCode, const std::string& type, const std::string& respectiveClass, int occupation, const Date& date);

    // Getters

    /**
     * @brief Get the code of the UC.
     * @return The code of the UC.
     */
    const std::string& getUcCode() const;

    /**
     * @brief Get the type of the UC.
     * @return The type of the UC.
     */
    const std::string& getType() const;

    /**
     * @brief Get the respective class of the UC.
     * @return The respective class of the UC.
     */
    const std::string& getRespectiveClass() const;

    /**
     * @brief Get the date associated with the UC.
     * @return The date associated with the UC.
     */
    const Date& getDate() const;

    // Setters

    /**
     * @brief Set the code of the UC.
     * @param ucCode The code of the UC.
     */
    void setUcCode(const std::string& ucCode);

    /**
     * @brief Set the type of the UC.
     * @param type The type of the UC.
     */
    void setType(const std::string& type);

    /**
     * @brief Set the respective class of the UC.
     * @param respectiveClass The respective class of the UC.
     */
    void setRespectiveClass(const std::string& respectiveClass);

    /**
     * @brief Set the date associated with the UC.
     * @param date The date associated with the UC.
     */
    void setDate(const Date& date);

    // Other Methods

    /**
     * @brief Check if the UC has a value (non-empty fields).
     * @return True if the UC has a value, otherwise false.
     */
    bool hasValue();

    /**
     * @brief Compare this UC with another UC (less than).
     * @param other The other UC to compare.
     * @return True if this UC is less than the other UC, otherwise false.
     */
    bool operator<(const UC other) const;

    /**
     * @brief Compare this UC with another UC for equality.
     * @param other The other UC to compare.
     * @return True if this UC is equal to the other UC, otherwise false.
     */
    bool operator ==(const UC other) const;

    /**
     * @brief Assignment operator for UC objects.
     * @param other The other UC to assign.
     * @return A reference to this UC after assignment.
     */
    bool operator =(const UC other);
};

#endif // PROJETO_UC_H
