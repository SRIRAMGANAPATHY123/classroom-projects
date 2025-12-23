#ifndef QUEUE_H
#define QUEUE_H

#include "Student.h"
#include <iostream>

// Simple queue implemented using singly linked nodes
class ClassQueue {
private:
    struct Node {
        Student data;
        Node* next;
        Node(const Student& s) : data(s), next(nullptr) {}
    };
    Node* front;
    Node* back;
public:
    ClassQueue();
    ~ClassQueue();

    void enqueue(const Student& s);
    bool dequeue(Student& out);
    bool isEmpty() const;
    void display() const;
};

#endif // QUEUE_H
