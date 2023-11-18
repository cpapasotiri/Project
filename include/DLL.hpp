#pragma once

#include <iostream>
#include "vertex.hpp"

using namespace std;

template <typename T>
class DLL
{
    struct Node
    {
        Vertex<T> *Data;
        Node *Next;
        Node *Prev;
        Node(const Vertex<T> &data);
    };
    int Count;
    Node *Start;
    Node *End;

public:
    DLL();
    ~DLL();
    int size();
    bool isEmpty();
    bool search(Vertex<T> *data);
    typename DLL<T>::Node *getFirst();
    typename DLL<T>::Node *getLast();
    typename DLL<T>::Node *getPrevious(int nodeIndex);
    typename DLL<T>::Node *getNext(int nodeIndex);
    typename DLL<T>::Node *getNode(int nodeIndex);
    typename DLL<T>::Node *getNodeById(int id);
    void addFirst(const Vertex<T> &data);
    void addLast(const Vertex<T> &data);
    void addBefore(Node *nextNode, const Vertex<T> &data);
    void addAfter(Node *prevNode, const Vertex<T> &data);
    void remove(Node *nodeToRm);
    void remove_by_id(int id);
    void print();
};

#include "../templates/DLL.tpp"