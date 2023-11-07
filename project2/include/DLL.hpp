#pragma once
#include "vector.hpp"

template <typename T>
class DLL
{
    struct Node
    {
        int id;
        Vector<T> *Data;
        Node *Next;
        Node *Prev;
        Node(const Vector<T> &data, int ID);
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
    void addFirst(const Vector<T> &data, int ID);
    void addLast(const Vector<T> &data, int ID);
    void addBefore(Node *nextNode, const Vector<T> &data, int ID);
    void addAfter(Node *prevNode, const Vector<T> &data, int ID);
    void remove(Node *nodeToRm);
    void remove_by_id(int id);
    void print();
};

#include "../templates/DLL.tpp"