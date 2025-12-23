# Student Data Structures Management System

A simple C++ console application demonstrating manual implementations of common data structures used to manage student information.

## Data Structures Implemented
- Linked List: `StudentList` — add, remove, search, display students
- Queue: `ClassQueue` — enqueue/dequeue students waiting to enter class
- Stack: `AttendanceStack` — push attendance actions and undo the last action
- Binary Search Tree: `CourseTree` — insert and display courses (in-order)
- Graph: `StudentGraph` — represent friendships between students
- Hash Table: `HashTable` — map student ID to Student for fast lookup

All core data structures are implemented manually without using STL containers.

## Project Structure
- `include/` - header files for each data structure and `Student.h`
- `src/` - implementation files and `main.cpp`

## How to compile
Using g++ (MinGW on Windows):

```
cd StudentDataStructures/src
g++ -std=c++17 -I../include *.cpp -o StudentApp
./StudentApp
```

Using CMake (cross-platform):
```
mkdir build && cd build
cmake ..
cmake --build .
./StudentApp
```

Or with Visual Studio (Developer Command Prompt):
```
cl /EHsc /I.. *.cpp
StudentApp.exe
```

## Sample Input / Output
Example session (user inputs in brackets):

1) Add student
 - Enter id: [101]
 - Enter name: [Alice]
 - Enter age: [20]
 - Enter major: [CS]

2) Enqueue student into class queue (choose option 5 and input id [101])
3) Mark attendance for student (option 8 and id [101])
4) Insert course (option 10) — code [CS101], name [Intro to CS]
5) Add friendship (option 12) — student ids [101] and [102]
6) Use HashTable sub-menu (option 14) to insert/search/delete/display

The menu is interactive and prints confirmations after each operation.

## Notes
- Code is intentionally kept beginner-friendly and well-commented.
- The hash table uses separate chaining with a fixed initial capacity (default 101).

Enjoy experimenting with manual implementations of classic data structures!
