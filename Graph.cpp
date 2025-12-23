#include "../include/Graph.h"

StudentGraph::StudentGraph(int initialCapacity) : capacity(initialCapacity), count(0) {
    vertices = new Vertex*[capacity];
    for (int i = 0; i < capacity; ++i) vertices[i] = nullptr;
}

StudentGraph::~StudentGraph() {
    for (int i = 0; i < capacity; ++i) {
        Vertex* v = vertices[i];
        if (!v) continue;
        // delete adjacency list
        AdjNode* cur = v->head;
        while (cur) {
            AdjNode* tmp = cur;
            cur = cur->next;
            delete tmp;
        }
        delete v;
    }
    delete[] vertices;
}

StudentGraph::Vertex* StudentGraph::findVertex(int id) const {
    for (int i = 0; i < capacity; ++i) {
        Vertex* v = vertices[i];
        if (v && v->id == id) return v;
    }
    return nullptr;
}

void StudentGraph::addVertexInternal(int id) {
    // find empty slot
    for (int i = 0; i < capacity; ++i) {
        if (!vertices[i]) {
            vertices[i] = new Vertex(id);
            count++;
            return;
        }
    }
    // need resize (simple doubling)
    int newCap = capacity * 2;
    Vertex** newArr = new Vertex*[newCap];
    for (int i = 0; i < newCap; ++i) newArr[i] = nullptr;
    // copy
    int idx = 0;
    for (int i = 0; i < capacity; ++i) {
        if (vertices[i]) newArr[idx++] = vertices[i];
    }
    // place new vertex
    newArr[idx++] = new Vertex(id);
    delete[] vertices;
    vertices = newArr;
    capacity = newCap;
    count++;
}

void StudentGraph::addVertex(int id) {
    if (findVertex(id)) return;
    addVertexInternal(id);
}

void StudentGraph::addEdge(int a, int b) {
    if (a == b) return;
    addVertex(a);
    addVertex(b);
    Vertex* va = findVertex(a);
    Vertex* vb = findVertex(b);
    // add b to a's list if not present
    AdjNode* cur = va->head;
    while (cur) {
        if (cur->studentId == b) break;
        cur = cur->next;
    }
    if (!cur) {
        AdjNode* n = new AdjNode(b);
        n->next = va->head;
        va->head = n;
    }
    // add a to b's list
    cur = vb->head;
    while (cur) {
        if (cur->studentId == a) break;
        cur = cur->next;
    }
    if (!cur) {
        AdjNode* n = new AdjNode(a);
        n->next = vb->head;
        vb->head = n;
    }
}

void StudentGraph::display() const {
    bool any = false;
    for (int i = 0; i < capacity; ++i) {
        Vertex* v = vertices[i];
        if (!v) continue;
        any = true;
        std::cout << "Student " << v->id << " -> ";
        AdjNode* cur = v->head;
        if (!cur) std::cout << "(no connections)";
        while (cur) {
            std::cout << cur->studentId;
            if (cur->next) std::cout << ", ";
            cur = cur->next;
        }
        std::cout << "\n";
    }
    if (!any) std::cout << "No student relationships yet.\n";
}
