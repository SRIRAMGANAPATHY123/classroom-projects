#include "../include/HashTable.h"

HashTable::HashTable(int cap) : capacity(cap) {
    buckets = new Node*[capacity];
    for (int i = 0; i < capacity; ++i) buckets[i] = nullptr;
}

HashTable::~HashTable() {
    for (int i = 0; i < capacity; ++i) {
        Node* cur = buckets[i];
        while (cur) {
            Node* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
    }
    delete[] buckets;
}

bool HashTable::insert(const Student& s) {
    int h = hash(s.id);
    Node* cur = buckets[h];
    while (cur) {
        if (cur->key == s.id) return false; // already exists
        cur = cur->next;
    }
    Node* n = new Node(s.id, s);
    n->next = buckets[h];
    buckets[h] = n;
    return true;
}

Student* HashTable::search(int key) {
    int h = hash(key);
    Node* cur = buckets[h];
    while (cur) {
        if (cur->key == key) return &cur->value;
        cur = cur->next;
    }
    return nullptr;
}

bool HashTable::remove(int key) {
    int h = hash(key);
    Node* cur = buckets[h];
    Node* prev = nullptr;
    while (cur) {
        if (cur->key == key) {
            if (prev) prev->next = cur->next;
            else buckets[h] = cur->next;
            delete cur;
            return true;
        }
        prev = cur;
        cur = cur->next;
    }
    return false;
}

void HashTable::display() const {
    bool any = false;
    for (int i = 0; i < capacity; ++i) {
        Node* cur = buckets[i];
        while (cur) {
            any = true;
            std::cout << "ID: " << cur->key << ", Name: " << cur->value.name << ", Major: " << cur->value.major << "\n";
            cur = cur->next;
        }
    }
    if (!any) std::cout << "HashTable is empty.\n";
}
