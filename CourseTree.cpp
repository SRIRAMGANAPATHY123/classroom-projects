#include "../include/CourseTree.h"

CourseTree::CourseTree() : root(nullptr) {}

CourseTree::~CourseTree() { destroy(root); }

void CourseTree::destroy(Node* cur) {
    if (!cur) return;
    destroy(cur->left);
    destroy(cur->right);
    delete cur;
}

void CourseTree::insertNode(Node*& cur, const Course& c) {
    if (!cur) {
        cur = new Node(c);
        return;
    }
    if (c.code < cur->data.code) insertNode(cur->left, c);
    else if (c.code > cur->data.code) insertNode(cur->right, c);
    else {
        // duplicate code: ignore or update
    }
}

void CourseTree::insert(const Course& c) { insertNode(root, c); }

void CourseTree::inorder(Node* cur) const {
    if (!cur) return;
    inorder(cur->left);
    std::cout << "Course Code: " << cur->data.code << ", Name: " << cur->data.name << "\n";
    inorder(cur->right);
}

void CourseTree::displayInOrder() const {
    if (!root) {
        std::cout << "No courses inserted.\n";
        return;
    }
    inorder(root);
}
