#include "UC.h"

// Default constructor
UC::UC() : UcCode(""), Type(""), RespectiveClass(""), occupation(0), Date_() {}

// Parameterized constructor
UC::UC(const std::string& ucCode, const std::string& type, const std::string& respectiveClass, int occupation, const Date& date)
        : UcCode(ucCode), Type(type), RespectiveClass(respectiveClass), occupation(occupation), Date_(date) {}

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

int UC::getOccupation() const {
    return occupation;
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

void UC::setOccupation(int occupation) {
    occupation = occupation;
}

void UC::setDate(const Date& date) {
    Date_ = date;
}

bool UC::operator==(const UC other) const
{
    return (UcCode == other.UcCode) && (Type == other.Type);
}