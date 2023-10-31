
#ifndef PROJETO_LOADFILES_H
#define PROJETO_LOADFILES_H

#include "stdafx.h"

class LoadFiles {
public:
    static void Load_Student_Classes(std::vector<Student>& students , std::pair<std::unordered_map<std::string, unordered_set<std::string>> , std::unordered_map<std::pair<std::string,std::string> , int , PairHash>>& AttendencePair);

    static void Load_Classes_Per_Uc(std::vector<Class>& classes);
    static void Load_Uc(std::vector<UC>& ucs);

    static void NormaliseString(std::string& str);

};
#endif //PROJETO_LOADFILES_H