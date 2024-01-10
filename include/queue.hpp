#pragma once

#include <iostream>

using namespace std;

template <typename T>
class Node
{
public:
    T* data;
    Node<T>* next;
    Node(T* data) : data(data), next(nullptr) {};  
};

template <typename T>
class Queue
{
    size_t size;
    Node<T> *front;
    Node<T> *rear;

public:
    Queue();
    Queue(const Queue<T>& other);
    ~Queue();
    Queue<T>& operator=(const Queue<T>& other);
    bool is_empty() const;
    bool contains(T &element);
    void enqueue(T* data);
    T* dequeue();
    T* front_value() const;
    T* peek(size_t position) const;
    size_t get_size() const;
    Node<T>* get_front() const;
    Node<T>* get_rear() const;
    void print();
    void clear();
};

#include "../templates/queue.tpp"