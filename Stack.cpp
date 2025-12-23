#include "../include/Stack.h"

AttendanceStack::AttendanceStack() : top(nullptr) {}

AttendanceStack::~AttendanceStack() {
    while (top) {
        Node* tmp = top;
        top = top->next;
        delete tmp;
    }
}

void AttendanceStack::push(const AttendanceAction& a) {
    Node* node = new Node(a);
    node->next = top;
    top = node;
}

bool AttendanceStack::pop(AttendanceAction& out) {
    if (!top) return false;
    out = top->action;
    Node* tmp = top;
    top = top->next;
    delete tmp;
    return true;
}

bool AttendanceStack::isEmpty() const {
    return top == nullptr;
}
