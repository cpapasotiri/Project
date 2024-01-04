#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Queue
{
    struct Node
    {
        T* data;
        Node* next;
        Node(T* data) : data(data), next(nullptr) {};  
    };
    size_t size;
    Node *front;
    Node *rear;

public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& other);
    bool is_empty() const;
    bool contains(T &element);
    void enqueue(T* data);
    void dequeue();
    T* front_value() const;
    T* peek(size_t position) const;
    size_t get_size() const;
    typename Queue<T>::Node *get_front() const;
    typename Queue<T>::Node *get_rear() const;
    void print();
    void clear();
};

#include "../templates/queue.tpp"