#ifndef COURSETREE_H
#define COURSETREE_H

#include <string>
#include <iostream>

struct Course {
    std::string code;
    std::string name;
    Course() : code(""), name("") {}
    Course(const std::string& c, const std::string& n) : code(c), name(n) {}
};

class CourseTree {
private:
    struct Node {
        Course data;
        Node* left;
        Node* right;
        Node(const Course& c) : data(c), left(nullptr), right(nullptr) {}
    };
    Node* root;

    void insertNode(Node*& cur, const Course& c);
    void inorder(Node* cur) const;
    void destroy(Node* cur);
public:
    CourseTree();
    ~CourseTree();

    void insert(const Course& c);
    void displayInOrder() const;
};

#endif // COURSETREE_H
