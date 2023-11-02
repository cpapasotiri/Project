#pragma once
#include "vector.hpp"

template <typename T>
class DLL
{
    struct Node
    {
        Vector<T> *Data;
        Node *Next;
        Node *Prev;
        Node(const Vector<T> &data);
    };
    int Count;
    Node *Start;
    Node *End;

public:
    DLL();
    ~DLL();
    int size();
    bool isEmpty();
    Node *getFirst();
    Node *getLast();
    Node *getPrevious(int nodeIndex);
    Node *getNext(int nodeIndex);
    void addBefore(Node *nextNode, const Vector<T> &data);
    void addAfter(Node *prevNode, const Vector<T> &data);
    void addFirst(const Vector<T> &data);
    void addLast(const Vector<T> &data);
    void remove(Node *nodeToRm);
    void print();
};

#include "../src/DLL.tpp"