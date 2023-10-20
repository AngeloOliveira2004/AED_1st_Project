#ifndef PROJETO_TREENODE_H
#define PROJETO_TREENODE_H

#include "stdafx.h"

class TreeNode {
private:
    Student* student;
    Class* class_;
    TreeNode* left;
    TreeNode* right;

public:
    TreeNode(const Student& student1);
    TreeNode(const Class& cls1);
    Student* getStudent();
    Class* getClass();
    TreeNode* InsertStudent(const Student& student1);
    TreeNode* InsertClass(const Class& cls1);
    TreeNode* SearchStudent(int Id);
    TreeNode* SearchClass(const std::string& classCode);
    ~TreeNode();
};

#endif // PROJETO_TREENODE_H