#include <iostream>
#include "../include/DLL.hpp"

using namespace std;

template <typename T>
DLL<T>::Node::Node(const Vector<T> &data, int ID) : id(ID), Data(new Vector<T>(data)), Next(nullptr), Prev(nullptr) {}

template <typename T>
DLL<T>::DLL() : Count(0), Start(nullptr), End(nullptr) {}

template <typename T>
DLL<T>::~DLL<T>()
{
    Node *current = Start;
    Node *next = nullptr;
    while (current != nullptr)
    {
        next = current->Next;
        delete current->Data;
        delete current;
        current = next;
    }
}

template <typename T>
int DLL<T>::size() { return Count; }

template <typename T>
bool DLL<T>::isEmpty() { return Count == 0; }

template <typename T>
bool DLL<T>::search(Vector<T> *data)
{
    if (isEmpty())
    {   
        return false; // empty list
    }
    Node *current;
    current = Start;
    for (int i = 0; i < Count; i++)
    {   
        if (current->Data->operator==(*data))
        {   
            return true;
        }
        if (current->Next != nullptr)
        {
            current = current->Next;
        }
    }
    
    return false;
}

template <typename T>
typename DLL<T>::Node *DLL<T>::getFirst()
{
    if (isEmpty())
    { // If DLL<T> is empty, print a warning message
        cout << "The list is empty!" << endl;
    }
    return Start;
}
template <typename T>
typename DLL<T>::Node *DLL<T>::getLast()
{
    if (isEmpty())
    { // If DLL<T> is empty, print a warning message
        cout << "The list is empty!" << endl;
    }
    return End;
}

template <typename T>
typename DLL<T>::Node *DLL<T>::getPrevious(int nodeIndex)
{
    if (isEmpty())
    { // If DLL<T> is empty, print a warning message
        cout << "The list is empty!" << endl;
        return nullptr;
    }

    if (nodeIndex == 0)
    {
        cout << "Node 0 is the first node!" << endl;
    }

    Node *current = Start;
    for (int i = 0; i < nodeIndex; i++)
    {
        if (current->Next != nullptr)
        { // In any other case, move till that node if it exists
            current = current->Next;
        }
    }

    return current->Prev;
}

template <typename T>
typename DLL<T>::Node *DLL<T>::getNext(int nodeIndex) // Asking the number of the node, of which the next node should be given
{
    Node *current = Start;
    if (isEmpty())
    {
        cout << "The list is empty!" << endl; // If DLL<T> is empty, print a warning message
        return nullptr;
    }
    if (nodeIndex == 0)
    {
        if (Count == 1)
        {
            cout << "The list has only one node!" << endl;
            return Start;
        }
        return Start->Next;
    }
    else
    {
        for (int i = 1; i < nodeIndex; i++)
        {
            if (current->Next != nullptr)
            {
                current = current->Next; // In any other case, move till that node if it exists
            }
        }
        if (current->Next == nullptr)
        {
            cout << "The given node is the last one!" << endl; // If the node given is the last one print message
            return End;
        }

        return current->Next; // Return the next node of the given
    }
}

template <typename T>
typename DLL<T>::Node *DLL<T>::getNode(int nodeIndex)
{
    Node *current = Start;
    if (isEmpty())
    {
        cout << "The list is empty!" << endl; // If DLL<T> is empty, print a warning message
        return nullptr;
    }
    if (nodeIndex == 0)
    {
        return Start;
    }
    else
    {
        for (int i = 1; i <= nodeIndex; i++)
        {
            if (current->Next != nullptr)
            {
                current = current->Next; // In any other case, move till that node if it exists
            }
        }

        return current; // Return the next node of the given
    }
}

template <typename T>
void DLL<T>::addFirst(const Vector<T> &data, int ID)
{
    Node *newNode = new Node(data, ID);
    newNode->Next = Start; // Inserting the new node in first place
    newNode->Prev = nullptr;
    if (!isEmpty())
    {
        Start->Prev = newNode;
    }
    // Connecting DLL<T>'s Start node with the new node
    Start = newNode;
    Count++; // Increase DLL's size by one
    if (size() <= 1)
    {
        End = newNode; // If it's the only node, connect it also with the Start node
    }
    return;
}

template <typename T>
void DLL<T>::addLast(const Vector<T> &data, int ID)
{
    Node *newNode = new Node(data, ID);
    newNode->Next = nullptr; // Inserting the new node in first place
    if (isEmpty())
    {
        addFirst(data,ID); // If the list is empty, add node in firts place
        return;
    }

    newNode->Next = nullptr;
    newNode->Prev = End; // Newnode's previous node is the current last node
    End->Next = newNode; // Update the next node of the current last node to point to the new node
    End = newNode;       // Connect the new node with the End node
    Count++;             // Increase DLL's size by one
    return;
}

template <typename T>
void DLL<T>::addBefore(Node* nextNode, const Vector<T> &data, int ID) // Asking for the node before of which the new node will be added
{                                             // and the Data of new node
    // cout << "Number " << data << " to be added before number " << nextNode->Data << "!" << endl;
    if (nextNode == nullptr)
    {
        cout << "The given next node cannot be empty!" << endl; // If the node given is empty return
        return;
    }

    Node *newNode = new Node(data, ID);
    newNode->Prev = nextNode->Prev;
    nextNode->Prev = newNode; // Inserting the new node in the exact place
    newNode->Next = nextNode;
    if (newNode->Next == Start)
    {
        Start = newNode; // If the new node is added in the first place, connect Start node
    }
    else
    {
        newNode->Prev->Next = newNode; // Otherwise, connect it with the previous node
    }
    Count++; // Increase DLL's size by one
}

template <typename T> 
void DLL<T>::addAfter(Node* prevNode, const Vector<T> &data, int ID) // Asking for the node after of which the new node will be added
{                                            // and the Data of new node

    if (prevNode == nullptr)
    {
        cout << "The given previous node cannot be empty!" << endl; // If the node given is empty return
        return;
    }
    Node *newNode = new Node(data, ID);
    newNode->Next = prevNode->Next;
    prevNode->Next = newNode; // inserting the new node in the exact place
    newNode->Prev = prevNode;
    if (newNode->Next == nullptr)
    {
        End = newNode; // If the new node is added in the last place, connect Start node
    }
    else
    {
        newNode->Next->Prev = newNode; // Otherwise connect it with the Next node
    }
    Count++; // Increase DLL's size by one
}


template <typename T>
void DLL<T>::remove(Node *nodeToRm) // Asking for the node to be removed
{
    if (isEmpty())
    {
        return; // If DLL is empty, there's nothing to be removed, so return
    }
    if (Start == nodeToRm)
    {
        Start = nodeToRm->Next; /*If the first node is to be removed, connect DLL's Start node with
                                                the next node of the one to be removed*/
    }
    if (nodeToRm->Next != nullptr)
    {
        nodeToRm->Next->Prev = nodeToRm->Prev; /*Disconnect the node to be removed from the list if it is connected*/
    }
    if (nodeToRm->Prev != nullptr)
    {
        nodeToRm->Prev->Next = nodeToRm->Next;
    }
    delete nodeToRm; // Finally delete node
    Count--;         // Decrease DLL<T>'s size by one
    return;
}

template <typename T>
void DLL<T>::remove_by_id(int id){
    Node *current = Start;
    if (isEmpty())
    {
        cout << "The list is empty!" << endl; // If DLL<T> is empty, print a warning message
        return ;
    }
    
    for (int i = 0; i < size(); i++)
    {
        if (current->id == id)
        {
            remove(current);
            return;
        } 
        else if (current->Next != nullptr)
        {
            current = current->Next; // In any other case, move till that node if it exists
        }
    }    
}

template <typename T>
void DLL<T>::print()
{
    Node *N;
    N = Start;

    if (isEmpty())
    {   
        cout << "The list is empty!" << endl; // If DLL<T> is empty
        return;
    }

    for (int i = 0; i < Count; i++)
    {
        N->Data->display_vector();
        cout << endl;
        if (N->Next != nullptr)
        {

            N = N->Next;
        }
    }
}