#include <iostream>
using namespace std;

class node{
private:
    int data;
    node* next;
    
friend class linkedList;
};

class linkedList{
private:
    node* head;
    node* tail;
    int sizeOf;
    node* traverse(const int& n);
public:
    linkedList():head(NULL),tail(NULL),sizeOf(0){};
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

node* linkedList::traverse(const int& n){
if (n>sizeOf-1 || n < 0){
    throw std::out_of_range("Index out of range!");
}
node* ptr = head;
for (int i = 0; i != n; ++i){
    ptr = ptr -> next;
}
return ptr;
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
node* newNode = new node;
newNode -> data = d;
newNode -> next = head;
head = newNode;
sizeOf++;
if (sizeOf == 1)
    tail = newNode;
}

void linkedList::addEnd(const int& d){
node* newNode = new node;
newNode -> data = d;
newNode -> next = NULL;
tail -> next = newNode;
tail = newNode;
sizeOf++;
if (sizeOf == 1)
    head = newNode;
}

void linkedList::insertAt(const int& n,const int& d){
try{
if (n == 0)
    addFront(d);
else if (n == -1)
    addEnd(d);
else{
node* ptr = traverse(n-1);
node* newNode = new node;
newNode -> data = d;
newNode -> next = ptr -> next;
ptr -> next = newNode;
sizeOf++;
}
}
catch(std::out_of_range& exc){
        cout << exc.what() << endl;
    }
}

void linkedList::removeAt(const int& n){
if (n == 0)
    removeFront();
else if (n> sizeOf -1)
    cout << "Index out of range!" << endl;
else{
node* prev = traverse(n-1);
node* old = prev -> next;
prev -> next = old -> next;
delete old;
sizeOf--;
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

void linkedList::removeFront(){
if (isEmpty())
    cout << "List is already empty!" << endl;
else{
node* old = head;
head = old -> next;
delete old;
sizeOf--;
if (sizeOf == 0)
    tail = NULL;
}
}

void linkedList::removeEnd(){
if (isEmpty())
    cout << "List is already empty!" << endl;
else{
node* old = tail;
node* ptr = traverse(sizeOf-2);
ptr -> next = NULL;
tail = ptr;
delete old;
sizeOf--;
}
}

void linkedList::print() const {
node* ptr = head;
while (ptr != 0){
    cout << ptr -> data << " ";
    ptr = ptr -> next;
}
cout << endl;
}

int main(){

return 0;
}
