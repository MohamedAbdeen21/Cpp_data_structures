#include <iostream>
using namespace std;

class Circularq{
private:
	int front;
	int rear;
	int n;
	int* arr;
	int size;
public:
	Circularq(si):{front = -1; rear = -1; n = 0; arr = new
int[si],size = si}
	bool isEmpty() const;
	bool isFull() const;
	int getFront() const;
	int getRear() const;
	int getSize() const;
	void push(const int& d);
	void pop();
	void top() const;
};

bool Circularq::isEmpty() const{
	return (n == 0);
}

bool Circularq::isFull() const{
	return (n == size);
}

int Circularq::getFront() const{
	return arr[front];
}

int Circularq::getRear() const{
	return arr[rear]
}

int Circularq::getSize() const;
	return n;
}

void Circualrq::push(const int& d){
	if (isEmpty()){
		front = 0;
		rear = 0;
	}else if (isFull()){
		throw "Queue is full!"
	}else if (rear == size-1 && front != 0){
		rear = 0;
	}else{
		rear++;
	}
	arr[rear] = d;
	n++;
}
	
void Circularq::pop(){
	if (isEmpty()){
		throw "Queue is empty!"
	}else if (front == rear){
		front = -1;
		rear = -1;
		n--;
	}else if (front == size - 1){
		front = 0;
	}else{
		front++;
	}

int Circularq::top() const{
	if (isEmpty()){
		throw "Queue is empty!"
	}else{
		return arr[front];
	}
}

int main(){
	Circualrq q(3);
	q.push(3);
	q.push(2);
	q.push(1);
	cout << q.top() << endl;
	q.pop();
	cout << q.top() << endl;
	q.push(4);
	cout << q.top() << endl;
	q.pop();
	q.pop();
	return 0
}
