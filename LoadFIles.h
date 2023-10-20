//
// Created by jose-costa on 10/20/23.
//

#ifndef PROJETO_LOADFILES_H
#define PROJETO_LOADFILES_H

#include "stdafx.h"

class LoadFIles {
public:
    static void Load_Student_Classes(std::list<Student>& students);
    static void Load_Classes_Per_Uc(std::list<Class>& classes);
    static void Load_Uc(std::list<UC>& ucs);

};


#endif //PROJETO_LOADFILES_H
