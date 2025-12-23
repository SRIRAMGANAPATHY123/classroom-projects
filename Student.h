#ifndef STUDENT_H
#define STUDENT_H

#include <string>

// Simple Student record used across the system
struct Student {
    int id;              // unique student id
    std::string name;
    int age;
    std::string major;
    bool present;        // attendance status

    Student() : id(0), name(""), age(0), major(""), present(false) {}
    Student(int _id, const std::string& _name, int _age, const std::string& _major)
        : id(_id), name(_name), age(_age), major(_major), present(false) {}
};

#endif // STUDENT_H
