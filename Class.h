#ifndef PROJETO_CLASS_H
#define PROJETO_CLASS_H

#include "stdafx.h"
/**
 * @headerfile Class
 * @brief A header file used to represent a class of an UC.
 */

class Class {
private:
    std::string ClassCode; /**< The code for the class. */
    std::vector<std::string> UCs; /**< Vector of UCs for the class. */

public:
    Class();
    Class(std::string  classCode, const std::unordered_set<std::string>& students, const std::vector<std::string>& ucs);

    [[nodiscard]] const std::string& getClassCode() const;
    [[nodiscard]] const std::vector<std::string>& getUCs() const;

    void setClassCode(const std::string& classCode);
    void setUCs(const std::vector<std::string>& ucs);

    static void sort(std::vector<Class>& classes);

    bool operator ==(const Class& other) const;
    void operator =(const Class& other) ;
    bool operator<(const Class& other) const;

    static std::pair<Class, std::vector<UC>> populateSchedule(Class& class_, const std::vector<UC>& allUCs);
};

namespace std {
    template <>
    struct hash<Class> {
        size_t operator()(const Class& classObj) const {
            return std::hash<std::string>{}(classObj.getClassCode());
        }
    };
}

#endif //PROJETO_CLASS_H