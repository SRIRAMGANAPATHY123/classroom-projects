#ifndef STACK_H
#define STACK_H

#include <iostream>

// Attendance action stored in stack to support undo
struct AttendanceAction {
    int studentId;
    bool markedPresent; // true if attendance was marked
    AttendanceAction(int id = 0, bool p = false) : studentId(id), markedPresent(p) {}
};

class AttendanceStack {
private:
    struct Node {
        AttendanceAction action;
        Node* next;
        Node(const AttendanceAction& a) : action(a), next(nullptr) {}
    };
    Node* top;
public:
    AttendanceStack();
    ~AttendanceStack();

    void push(const AttendanceAction& a);
    bool pop(AttendanceAction& out);
    bool isEmpty() const;
};

#endif // STACK_H
