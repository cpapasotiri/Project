class DLL
{
    struct Node
    {
        int Data;
        Node *Next;
        Node *Prev;
        Node(int data);
    };
    int Count;
    Node *Start;
    Node *End;

    public:
    DLL();
    ~DLL();
    int size();
    bool isEmpty();
    Node* getFirst();
    Node* getLast();
    Node* getPrevious(int nodeIndex);
    Node* getNext(int nodeIndex);
    void addBefore(Node* nextNode,int data);
    void addAfter(Node* prevNode,int data);
    void addFirst(int data);
    void addLast(int data);
    void remove(Node* nodeToRm);
    void print();
}