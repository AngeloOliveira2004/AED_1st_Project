#include "TreeNode.h"

TreeNode::TreeNode(const Student& student1) {
    student = new Student(student1);
    class_ = nullptr;
    left = nullptr;
    right = nullptr;
}

TreeNode::TreeNode(const Class& cls1) {
    class_ = new Class(cls1);
    student = nullptr;
    left = nullptr;
    right = nullptr;
}

Student* TreeNode::getStudent() {
    return student;
}

Class* TreeNode::getClass() {
    return class_;
}

TreeNode* TreeNode::InsertStudent(const Student& student1) {
    if (!student) {
        return new TreeNode(student1);
    }

    if (student1.GetId() < student->GetId()) {
        if (left == nullptr) {
            left = new TreeNode(student1); // Create a new node here
        } else {
            left = left->InsertStudent(student1);
        }
    } else if (student1.GetId() > student->GetId()) {
        if (right == nullptr) {
            right = new TreeNode(student1); // Create a new node here
        } else {
            right = right->InsertStudent(student1);
        }
    }

    return this;
}

TreeNode* TreeNode::InsertClass(const Class& cls1) {
    if (!class_) {
        return new TreeNode(cls1);
    }

    if (cls1.GetClassCode() < class_->GetClassCode()) {
        if (left == nullptr) {
            left = left->InsertClass(cls1);
        } else {
            left = left->InsertClass(cls1);
        }
    } else if (cls1.GetClassCode() > class_->GetClassCode()) {
        if (right == nullptr) {
            right = right->InsertClass(cls1);
        } else {
            right = right->InsertClass(cls1);
        }
    }

    return this;
}

TreeNode* TreeNode::SearchStudent(int Id) {
    if (!student) {
        return nullptr;
    }

    if (Id == student->GetId()) {
        return this;
    } else if (Id < student->GetId() && left != nullptr) {
        return left->SearchStudent(Id);
    } else if (Id > student->GetId() && right != nullptr) {
        return right->SearchStudent(Id);
    } else {
        return nullptr;
    }
}

TreeNode* TreeNode::SearchClass(const std::string& classCode) {
    if (!class_) {
        return nullptr;
    }

    if (classCode == class_->GetClassCode()) {
        return this;
    } else if (classCode < class_->GetClassCode() && left != nullptr) {
        return left->SearchClass(classCode);
    } else if (classCode > class_->GetClassCode() && right != nullptr) {
        return right->SearchClass(classCode);
    } else {
        return nullptr;
    }
}

TreeNode::~TreeNode() {
    delete student;
    delete class_;
    delete left;
    delete right;
}