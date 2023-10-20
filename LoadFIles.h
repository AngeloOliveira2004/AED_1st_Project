//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_LOADFILES_H
#define PROJETO_LOADFILES_H

#include "stdafx.h"

class LoadFIles {
public:
    static void Load_Student_Classes(std::vector<Student>& students);
    static void Load_Classes_Per_Uc(std::vector<Class>& classes);
    static void Load_Uc(std::vector<UC>& ucs);

    static void NormaliseString(std::string& str);

};


#endif //PROJETO_LOADFILES_H
