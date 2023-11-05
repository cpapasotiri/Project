#pragma once
#include "../include/vector.hpp"

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
    bool search(Vector<T> *data);
    typename DLL<T>::Node *getFirst();
    typename DLL<T>::Node *getLast();
    typename DLL<T>::Node *getPrevious(int nodeIndex);
    typename DLL<T>::Node *getNext(int nodeIndex);
    typename DLL<T>::Node *getNode(int nodeIndex);
    void addFirst(const Vector<T> &data);
    void addLast(const Vector<T> &data);
    void remove(Node *nodeToRm);
    void print();
};

#include "../templates/DLL.tpp"