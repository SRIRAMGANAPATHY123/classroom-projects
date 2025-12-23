#include <iostream>
#include <limits>

#include "../include/Student.h"
#include "../include/LinkedList.h"
#include "../include/Queue.h"
#include "../include/Stack.h"
#include "../include/CourseTree.h"
#include "../include/Graph.h"
#include "../include/HashTable.h"

// Helper to read integer safely
int readInt() {
    int x;
    while (!(std::cin >> x)) {
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
        std::cout << "Invalid input, enter a number: ";
    }
    return x;
}

void pause() {
    std::cout << "Press Enter to continue...";
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    std::cin.get();
}

int main() {
    StudentList studentList;
    ClassQueue classQueue;
    AttendanceStack attendanceStack;
    CourseTree courseTree;
    StudentGraph graph;
    HashTable table(101);

    while (true) {
        std::cout << "\n=== Student Data Structures Management System ===\n";
        std::cout << "1) Add student\n2) Remove student\n3) Search student\n4) Display all students\n";
        std::cout << "5) Enqueue student into class queue\n6) Dequeue student from class queue\n7) Display class queue\n";
        std::cout << "8) Mark attendance\n9) Undo last attendance\n";
        std::cout << "10) Insert course\n11) Display courses (in-order)\n";
        std::cout << "12) Add friendship\n13) Display relationships\n";
        std::cout << "14) HashTable insert/search/delete/display\n15) Help\n16) Exit\n";
        std::cout << "Choose an option: ";
        int choice = readInt();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

        if (choice == 16) {
            std::cout << "Goodbye!\n";
            break;
        }

        if (choice == 15) {
            std::cout << "Help:\n";
            std::cout << " - Use options to manage data structures and students.\n";
            std::cout << " - When entering strings, press Enter after typing.\n";
            std::cout << " - HashTable sub-menu allows insert/search/delete/display.\n";
            std::cout << "\n";
            continue;
        }
        if (choice == 1) {
            std::cout << "Enter id: "; int id = readInt(); std::cin.ignore();
            std::cout << "Enter name: "; std::string name; std::getline(std::cin, name);
            std::cout << "Enter age: "; int age = readInt(); std::cin.ignore();
            std::cout << "Enter major: "; std::string major; std::getline(std::cin, major);
            Student s(id, name, age, major);
            studentList.addStudent(s);
            table.insert(s);
            std::cout << "Student added.\n";
        } else if (choice == 2) {
            std::cout << "Enter id to remove: "; int id = readInt(); std::cin.ignore();
            if (studentList.removeStudent(id)) {
                table.remove(id);
                std::cout << "Removed student " << id << " from list and hashtable.\n";
            } else std::cout << "Student not found.\n";
        } else if (choice == 3) {
            std::cout << "Enter id to search: "; int id = readInt(); std::cin.ignore();
            Student* s = studentList.findStudent(id);
            if (s) std::cout << "Found: " << s->id << ", " << s->name << "\n";
            else std::cout << "Not found in list. Checking hash table...\n";
            Student* h = table.search(id);
            if (h) std::cout << "HashTable Found: " << h->id << ", " << h->name << "\n";
        } else if (choice == 4) {
            studentList.display();
        } else if (choice == 5) {
            std::cout << "Enter student id to enqueue: "; int id = readInt(); std::cin.ignore();
            Student* s = studentList.findStudent(id);
            if (!s) s = table.search(id);
            if (!s) std::cout << "Student not found.\n";
            else {
                classQueue.enqueue(*s);
                std::cout << "Enqueued student " << s->name << "\n";
            }
        } else if (choice == 6) {
            Student s;
            if (classQueue.dequeue(s)) std::cout << "Dequeued: " << s.id << ", " << s.name << "\n";
            else std::cout << "Queue empty.\n";
        } else if (choice == 7) {
            classQueue.display();
        } else if (choice == 8) {
            std::cout << "Enter student id to mark present: "; int id = readInt(); std::cin.ignore();
            Student* s = studentList.findStudent(id);
            if (!s) s = table.search(id);
            if (!s) std::cout << "Student not found.\n";
            else {
                s->present = true;
                attendanceStack.push(AttendanceAction(id, true));
                std::cout << "Marked present for " << s->name << " and pushed action on stack.\n";
            }
        } else if (choice == 9) {
            AttendanceAction a;
            if (!attendanceStack.pop(a)) {
                std::cout << "Nothing to undo.\n";
            } else {
                Student* s = studentList.findStudent(a.studentId);
                if (!s) s = table.search(a.studentId);
                if (s) {
                    s->present = !a.markedPresent; // undo: flip
                    std::cout << "Undid attendance for student " << a.studentId << ". New status: " << (s->present?"Present":"Absent") << "\n";
                } else std::cout << "Student not found to undo action.\n";
            }
        } else if (choice == 10) {
            std::cout << "Enter course code: "; std::string code; std::getline(std::cin, code);
            std::cout << "Enter course name: "; std::string cname; std::getline(std::cin, cname);
            courseTree.insert(Course(code, cname));
            std::cout << "Inserted course.\n";
        } else if (choice == 11) {
            courseTree.displayInOrder();
        } else if (choice == 12) {
            std::cout << "Enter first student id: "; int a = readInt(); std::cin.ignore();
            std::cout << "Enter second student id: "; int b = readInt(); std::cin.ignore();
            // require students exist in either list or hashtable
            if (!studentList.findStudent(a) && !table.search(a)) std::cout << "Student " << a << " not found.\n";
            else if (!studentList.findStudent(b) && !table.search(b)) std::cout << "Student " << b << " not found.\n";
            else {
                graph.addEdge(a, b);
                std::cout << "Added friendship between " << a << " and " << b << "\n";
            }
        } else if (choice == 13) {
            graph.display();
        } else if (choice == 14) {
            std::cout << "a) Insert into hashtable\nb) Search\nc) Delete\nd) Display all\nChoose: ";
            char ch; std::cin >> ch; std::cin.ignore();
            if (ch == 'a') {
                std::cout << "Enter id: "; int id = readInt(); std::cin.ignore();
                std::cout << "Enter name: "; std::string name; std::getline(std::cin, name);
                std::cout << "Enter age: "; int age = readInt(); std::cin.ignore();
                std::cout << "Enter major: "; std::string major; std::getline(std::cin, major);
                Student s(id, name, age, major);
                if (table.insert(s)) std::cout << "Inserted into hashtable.\n";
                else std::cout << "Insert failed (duplicate?).\n";
            } else if (ch == 'b') {
                std::cout << "Enter id to search: "; int id = readInt(); std::cin.ignore();
                Student* s = table.search(id);
                if (s) std::cout << "Found: " << s->id << ", " << s->name << "\n";
                else std::cout << "Not found.\n";
            } else if (ch == 'c') {
                std::cout << "Enter id to delete: "; int id = readInt(); std::cin.ignore();
                if (table.remove(id)) std::cout << "Deleted from hashtable.\n";
                else std::cout << "Not found.\n";
            } else if (ch == 'd') {
                table.display();
            } else std::cout << "Invalid option.\n";
        } else {
            std::cout << "Invalid choice.\n";
        }
    }

    return 0;
}
