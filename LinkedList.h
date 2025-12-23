#ifndef LINKEDLIST_H
#define LINKEDLIST_H

#include "Student.h"
#include <iostream>

// Singly linked list for Student records
class StudentList {
private:
    struct Node {
        Student data;
        Node* next;
        Node(const Student& s) : data(s), next(nullptr) {}
    };
    Node* head;

public:
    StudentList();
    ~StudentList();

    // Add student at the end
    void addStudent(const Student& s);
    // Remove student by id, returns true if removed
    bool removeStudent(int id);
    // Find pointer to student, nullptr if not found
    Student* findStudent(int id);
    // Display all students
    void display() const;
};

#endif // LINKEDLIST_H
