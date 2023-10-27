#ifndef PROJETO_UC_H
#define PROJETO_UC_H

#include <string>
#include "Date.h"

class UC {
private:
    std::string UcCode;
    std::string Type;
    std::string RespectiveClass;
    int occupation;
    Date Date_;

public:
    // Constructors
    UC();
    UC(const std::string& ucCode, const std::string& type, const std::string& respectiveClass, int occupation, const Date& date);

    // Getters
    const std::string& getUcCode() const;
    const std::string& getType() const;
    const std::string& getRespectiveClass() const;
    int getOccupation() const;
    const Date& getDate() const;

    // Setters
    void setUcCode(const std::string& ucCode);
    void setType(const std::string& type);
    void setRespectiveClass(const std::string& respectiveClass);
    void setOccupation(int occupation);
    void setDate(const Date& date);
};

#endif // PROJETO_UC_H
