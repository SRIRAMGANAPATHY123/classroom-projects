#include "../include/LinkedList.h"

StudentList::StudentList() : head(nullptr) {}

StudentList::~StudentList() {
    Node* cur = head;
    while (cur) {
        Node* tmp = cur;
        cur = cur->next;
        delete tmp;
    }
}

void StudentList::addStudent(const Student& s) {
    Node* node = new Node(s);
    if (!head) {
        head = node;
        return;
    }
    Node* cur = head;
    while (cur->next) cur = cur->next;
    cur->next = node;
}

bool StudentList::removeStudent(int id) {
    Node* cur = head;
    Node* prev = nullptr;
    while (cur) {
        if (cur->data.id == id) {
            if (prev) prev->next = cur->next;
            else head = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

Student* StudentList::findStudent(int id) {
    Node* cur = head;
    while (cur) {
        if (cur->data.id == id) return &cur->data;
        cur = cur->next;
    }
    return nullptr;
}

void StudentList::display() const {
    Node* cur = head;
    if (!cur) {
        std::cout << "No students in the list.\n";
        return;
    }
    std::cout << "Students:\n";
    while (cur) {
        std::cout << "ID: " << cur->data.id << ", Name: " << cur->data.name
                  << ", Age: " << cur->data.age << ", Major: " << cur->data.major
                  << ", Present: " << (cur->data.present ? "Yes" : "No") << "\n";
        cur = cur->next;
    }
}
