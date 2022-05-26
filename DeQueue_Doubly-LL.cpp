#include <iostream>
using namespace std;

class Node{
private:
    int data;
    Node* next;
    Node* prev;
friend class linkedList;
};

class linkedList{
private:
    Node* head;
    Node* tail;
    int sizeOf;
    Node* traverse(const int& n);
public:
    linkedList(){head = nullptr;tail = nullptr;sizeOf = 0;};
    ~linkedList(){while(!isEmpty()) removeFront();}
    int getHead() const;
    int getTail() const;
    int retrieveAt(const int& n);
    bool isEmpty() const;
    void addFront(const int& d);
    void addEnd(const int& d);
    void insertAt(const int& n,const int& d);
    void removeAt(const int& n);
    void removeFront();
    void removeEnd();
    void print() const;
};

Node* linkedList::traverse(const int& n){
if (n>sizeOf-1)
    throw std::out_of_range("Index out of range!");

if (n > sizeOf/2){
    Node* ptr = tail;
    for (int i = 0; i != n; ++i)
        ptr = ptr -> prev;
}
else{
Node* ptr = head;
for (int i = 0; i != n; ++i)
    ptr = ptr -> next;

return ptr;
}
}

int linkedList::getHead() const{
    if (sizeOf == 0)
        return 0;
    else
    return head -> data;
}

int linkedList::getTail() const{
    if (sizeOf == 0)
        return 0;
    else
    return tail -> data;
}

bool linkedList::isEmpty() const{
    return (sizeOf == 0);
}

void linkedList::addFront(const int& d){
    Node* newNode = new Node;
    newNode -> data = d;
    newNode -> next = head;
    newNode -> prev = nullptr;
    head = newNode;
    if (isEmpty())
        tail = newNode;
    sizeOf++;
}

void linkedList::addEnd(const int& d){
    if (isEmpty())
        addFront(d);
    else{
    Node* newNode = new Node;
    newNode -> data = d;
    newNode -> next = NULL;
    newNode -> prev = tail;
    tail -> next = newNode;
    tail = newNode;
    sizeOf++;
    if (sizeOf == 1)
        head = newNode;
}
}

void linkedList::removeFront(){
    Node* old = head;
    head = head -> next;
    delete old;
    sizeOf--;
    if (head != nullptr)
    head -> prev = nullptr;
}

void linkedList::removeEnd(){
    Node* old = tail;
    tail = tail -> prev;
    tail -> next = nullptr;
    delete old;
    sizeOf--;
}

void linkedList::print() const {
    Node* ptr = head;
    while (ptr != 0){
        cout << ptr -> data << " ";
        ptr = ptr -> next;
    }
    cout << endl;
}

class dequeue{
private:
    int n = 0;
    linkedList dlist;
public:
    void push_f(const int& d);
    void push_r(const int& d);
    void remove_f();
    void remove_r();
    void print() const;
    int get_size() const;
};

void dequeue::push_f(const int& d){
    dlist.addFront(d);
    n++;
}

void dequeue::push_r(const int& d){
    dlist.addEnd(d);
    n++;
}

void dequeue::print() const{
    dlist.print();
}

void dequeue::remove_f(){
    dlist.removeFront();
    n--;
}

void dequeue::remove_r(){
    dlist.removeEnd();
    n--;
}

int dequeue::get_size() const{
    return n;
}

int main(){
    dequeue dq;
    dq.push_f(5);
    dq.push_f(4);
    dq.push_r(3);
    dq.print();
    dq.remove_f();
    dq.print();
    dq.remove_r();
    cout << dq.get_size() << endl;
    dq.print();
    return 0;
}
