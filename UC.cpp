#include "UC.h"

// Default constructor
UC::UC() : UcCode(""), Type(""), RespectiveClass(""), Date_() {}

// Parameterized constructor
UC::UC(const std::string& ucCode, const std::string& type, const std::string& respectiveClass, int occupation, const Date& date)
        : UcCode(ucCode), Type(type), RespectiveClass(respectiveClass), Date_(date) {}

// Getters
const std::string& UC::getUcCode() const {
    return UcCode;
}

const std::string& UC::getType() const {
    return Type;
}

const std::string& UC::getRespectiveClass() const {
    return RespectiveClass;
}

const Date& UC::getDate() const {
    return Date_;
}

// Setters
void UC::setUcCode(const std::string& ucCode) {
    UcCode = ucCode;
}

void UC::setType(const std::string& type) {
    Type = type;
}

void UC::setRespectiveClass(const std::string& respectiveClass) {
    RespectiveClass = respectiveClass;
}

void UC::setDate(const Date& date) {
    Date_ = date;
}

bool UC::hasValue()
{
    return UcCode != "";
}

bool UC::operator<(const UC other) const
{
    return Date_.Day < other.getDate().Day; // Assuming the UC name is used for comparison
}

bool UC::operator==(const UC other) const
{
    return (UcCode == other.UcCode) && (Type == other.Type) && (RespectiveClass == other.RespectiveClass);
}

bool UC::operator=(const UC other)
{
    UcCode = other.UcCode;
    Type = other.Type;
    RespectiveClass = other.RespectiveClass;
    Date_ = other.Date_;
}