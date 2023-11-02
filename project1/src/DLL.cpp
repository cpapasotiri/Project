#include <iostream>
#include "DLL.hpp"

using namespace std;

DLL::Node::Node(int data) : Data(data), Next(nullptr), Prev(nullptr) {}
DLL::DLL() : Start(nullptr), End(nullptr), Count(0) {}
DLL::~DLL() {}
int DLL::size() { return Count; }
bool DLL::isEmpty() { return Count == 0; }
Node *DLL::getFirst()
{
    if (isEmpty())
    { // If DLL is empty, print a warning message
        cout << "The list is empty!" << endl;
    }
    return Start;
}
Node *DLL::getLast()
{
    if (isEmpty())
    { // If DLL is empty, print a warning message
        cout << "The list is empty!" << endl;
    }
    return End;
}

Node *DLL::getPrevious(int nodeIndex)
{
    if (isEmpty())
    { // If DLL is empty, print a warning message
        cout << "The list is empty!" << endl;
    }

    Node *current = Start;
    for (int i = 0; i < nodeIndex; i++)
    {
        if (current->Next != nullptr)
        { // In any other case, move till that node if it exists
            current = current->Next;
        }
    }
    cout << "Node number" << nodeIndex - 1 << "has value:" << current->Prev->Data << endl;

    return current->Prev;
}

Node *DLL::getNext(int nodeIndex) // Asking the number of the node, of which the next node should be given
{
    Node *current = Start;
    if (isEmpty())
    {
        cout << "The list is empty!" << endl; // If DLL is empty, print a warning message
    }
    if (nodeIndex == 0)
    {
        GetFirst(); // If the node's number given is 0, get the first node
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
        }
        cout << "Node number " << nodeIndex + 1 << " has value " << current->Next->Data << endl;
        return current->Next; // Return the next node of the given
    }
}

void DLL::addBefore(Node *nextNode, int data) // Asking for the node before of which the new node will be added
{                                             // and the Data of new node
    cout << "Number " << data << " to be added before number " << nextNode->Data << "!" << endl;
    if (nextNode == nullptr)
    {
        cout << "The given next node cannot be empty!" << endl; // If the node given is empty return
        return;
    }

    Node *newNode = new Node(data);
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

void DLL::addAfter(Node *prevNode, int data) // Asking for the node after of which the new node will be added
{                                            // and the Data of new node

    cout << "Number " << data << " to be added after number " << prevNode->Data << "!" << endl;
    if (prevNode == nullptr)
    {
        cout << "The given previous node cannot be empty!" << endl; // If the node given is empty return
        return;
    }
    Node *newNode = new Node(data);
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

void DLL::addFirst(int data)
{
    cout << "Number " << data << " to be added in first node!" << endl;
    Node *newNode = new Node(data);
    Node *current = Start; // Pointer to node named current, to be showing on DLL's Start
    newNode->Next = Start;  // Inserting the new node in first place
    newNode->Prev = nullptr;
    if (!isEmpty())
    {
        Start->Prev = newNode;
    }
    // Connecting DLL's Start node with the new node
    Start = newNode;
    Count++; // Increase DLL's size by one
    if (size() <= 1)
    {
        End = newNode; // If it's the only node, connect it also with the Start node
    }
    return;
}

void DLL::addLast(int data)
{
    cout << "Number " << data << " to be added in last node!" << endl;
    Node *newNode = new Node(data); 
    Node *current = Start;        // Pointer to node named current, to be showing on DLL's Start          
    newNode->Next = nullptr;        // Inserting the new node in first place
    if (isEmpty())
    {
        AddFirst(data); // If the list is empty, add node in firts place
        delete newNode;
        return;
    }
    for (int i = 0; i < (size() - 1); i++)
    {
        current = current->Next; // Otherwise, move till the previous of the last node
    }
    current->Next = newNode;
    newNode->Prev = current; // Add it in the last place
    Start = newNode;          // Connect with the Start node
    Count++;                 // Increase DLL's size by one
    return;
}

void DLL:remove(Node *nodeToRm) // Asking for the node to be removed
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
    Count--;         // Decrease DLL's size by one
    return;
}

void print() /*This function is from the first chapter: Linked Data Representations
                            changed to be used for integers*/
{
    Node *N;
    cout << "(";
    N = Start;
    while (N != nullptr)
    {
        cout << N->Data;
        N = N->Next;
        if (N != nullptr)
            cout << ",";
    }
    cout << ")" << endl;
}