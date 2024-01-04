
#include "queue.hpp"


template <typename T>
Queue<T>::Queue() : size(0), front(nullptr), rear(nullptr) {}

template <typename T>
Queue<T>::Queue(const Queue<T> &other) : size(0), front(nullptr), rear(nullptr)
{
    // If the queue is empty, no need to copy
    if (other.front == nullptr)
    {
        return;
    }

    // Copy the front element
    front = new Node(other.front->data);
    rear = front;

    // Copy the rest of the elements
    Node *source_node = other.front->next;
    while (source_node != nullptr)
    {
        rear->next = new Node(source_node->data);
        rear = rear->next;
        source_node = source_node->next;
    }
    size = other.size;
}

template <typename T>
Queue<T>::~Queue()
{
    while (!is_empty()) 
    {
        dequeue();
    }
}

template <typename T>
Queue<T>& Queue<T>::operator=(const Queue<T> &other)
{
    if (this == &other)
    { 
        // Clear the current queue to create space for the new elements
        clear();
    
        // Copy the elements from the other queue
        typename Queue<T>::Node *current = other.front;
        while (current != nullptr)
        {
            enqueue(current->data);
            current = current->next;
        }
    }
    return *this;
}

template <typename T>
bool Queue<T>::is_empty() const
{
    return (front == nullptr) && (size == 0);
}

template <typename T>
bool Queue<T>::contains(T &element)
{
    Node *current = front;
    while (current != nullptr)
    {
        if (current->data == element)
        {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void Queue<T>::enqueue(T* data)
{
    Node *newNode = new Node(data);
    if(is_empty())
    {
        front = newNode;
        rear = newNode;
    }
    else
    {
        rear->next = newNode;
        rear = newNode;
    }
    size++;
}

template <typename T>
void Queue<T>::dequeue()
{
    if (is_empty())
    {
        cerr << "Queue is empty, can't dequeue" << endl;
    }
 
    Node *current = front;
    front = front->next;
    delete current;
    size--;

    if (front == nullptr)
    {
        rear = nullptr; // Queue is empty now
    }    
}

template <typename T>
T* Queue<T>::front_value() const
{
    if (is_empty())
    {
        cerr << "Queue is empty, no front value" << endl;
        return nullptr;
    }

    return front->data;
}

template <typename T>
T* Queue<T>::peek(size_t position) const
{
    if (is_empty())
    {
        cerr << "Queue is empty, no front value" << endl;
        return nullptr;
    }

    if (position >= size)
    {
        cerr << "Position is out of bounds" << endl;
        return nullptr;
    }

    Node *current = front;
    for (size_t i = 0; i < position; i++)
    {
        current = current->next;
    }
    return current->data;
}

template <typename T>
size_t Queue<T>::get_size() const
{
    return size;
}

template <typename T>
typename Queue<T>::Node* Queue<T>::get_front() const 
{
    return front;
}

template <typename T>
typename Queue<T>::Node* Queue<T>::get_rear() const 
{
    return rear;
}

template <typename T>
void Queue<T>::print()
{
    if (is_empty())
    {
        cout << "Queue is empty" << endl;
        return;
    }

    Node *current = front;
    while (current != nullptr)
    {   
        cout << (*current->data).get_id(); // Assuming T is always a pointer to Job<int>
        cout << " ";
        current = current->next;
    }
    cout << endl;
}

template <typename T>
void Queue<T>::clear()
{
    while (!is_empty()) 
    {
        dequeue();
    }
}