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
    void addFront(const int&& d);
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

void linkedList::addFront(const int&& d){
Node* newNode = new Node;
newNode -> data = d;
newNode -> next = head;
newNode -> prev = nullptr;
head = newNode;
sizeOf++;

}

void linkedList::addEnd(const int& d){
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


/*
void linkedList::insertAt(const int& n,const int& d){
try{
if (n == 0)
    addFront(d);
else if (n == -1)
    addEnd(d);

else{
Node* ptr = traverse(n-1);
Node* newNode = new Node;
newNode -> data = d;
newNode -> next = ptr -> next;
newNode -> prev = ptr;
ptr -> next -> prev = newNode;
ptr -> next = newNode;
sizeOf++;
}
}
catch(std::out_of_range& exc){
        cout << exc.what() << endl;
    }
}



int linkedList::retrieveAt(const int& n){
try{
    return traverse(n) -> data;
}
catch(std::out_of_range& exc){
        cout << exc.what() << endl;
        return -1;
    }
}

void linkedList::removeEnd(){
if (isEmpty())
    cout << "List is already empty!" << endl;
else{
Node* old = tail;
Node* ptr = traverse(sizeOf-2);
ptr -> next = NULL;
tail = ptr;
delete old;
sizeOf--;
}
}
*/
void linkedList::print() const {
Node* ptr = head;
while (ptr != 0){
    cout << ptr -> data << " ";
    ptr = ptr -> next;
}
cout << endl;
}

int main(){
linkedList x;
x.addFront(3);
return 0;
}
