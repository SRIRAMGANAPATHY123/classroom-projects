#ifndef HASHTABLE_H
#define HASHTABLE_H

#include "Student.h"
#include <iostream>

// Simple hash table with separate chaining (buckets store linked nodes)
class HashTable {
private:
    struct Node {
        int key; // student id
        Student value;
        Node* next;
        Node(int k, const Student& v) : key(k), value(v), next(nullptr) {}
    };
    Node** buckets;
    int capacity;

    int hash(int key) const { return key % capacity; }
public:
    HashTable(int cap = 101); // prime-ish default
    ~HashTable();

    bool insert(const Student& s);
    Student* search(int key);
    bool remove(int key);
    void display() const;
};

#endif // HASHTABLE_H
