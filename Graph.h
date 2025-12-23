#ifndef GRAPH_H
#define GRAPH_H

#include "Student.h"
#include <iostream>

// Graph implemented as list of vertices; each vertex has adjacency list implemented as linked nodes
class StudentGraph {
private:
    struct AdjNode { // node for adjacency list
        int studentId;
        AdjNode* next;
        AdjNode(int id) : studentId(id), next(nullptr) {}
    };

    struct Vertex {
        int id;
        AdjNode* head; // adjacency list head
        Vertex(int _id): id(_id), head(nullptr) {}
    };

    Vertex** vertices; // dynamic array of pointers to Vertex
    int capacity;      // size of vertices array
    int count;         // number of vertices

    Vertex* findVertex(int id) const;
    void addVertexInternal(int id);

public:
    StudentGraph(int initialCapacity = 16);
    ~StudentGraph();

    // Add vertex (student) if not exists
    void addVertex(int id);
    // Add undirected edge between two student IDs
    void addEdge(int a, int b);
    // Display all relationships
    void display() const;
};

#endif // GRAPH_H
