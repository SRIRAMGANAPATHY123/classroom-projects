#include "../include/Queue.h"

ClassQueue::ClassQueue() : front(nullptr), back(nullptr) {}

ClassQueue::~ClassQueue() {
    while (front) {
        Node* tmp = front;
        front = front->next;
        delete tmp;
    }
}

void ClassQueue::enqueue(const Student& s) {
    Node* node = new Node(s);
    if (!back) {
        front = back = node;
        return;
    }
    back->next = node;
    back = node;
}

bool ClassQueue::dequeue(Student& out) {
    if (!front) return false;
    Node* tmp = front;
    out = front->data;
    front = front->next;
    if (!front) back = nullptr;
    delete tmp;
    return true;
}

bool ClassQueue::isEmpty() const {
    return front == nullptr;
}

void ClassQueue::display() const {
    if (!front) {
        std::cout << "Class queue is empty.\n";
        return;
    }
    Node* cur = front;
    std::cout << "Students waiting (front->back):\n";
    while (cur) {
        std::cout << "ID: " << cur->data.id << ", Name: " << cur->data.name << "\n";
        cur = cur->next;
    }
}
