#include <iostream>
using namespace std;

class Mystack{
private:
    int n = 0;
    int* q;
    int capacity;
public:
    Mystack(int cap = 99): q(new int[cap]), capacity(cap){}
    void push(const int& d);
    int get_size() const;
    void pop();
    int top() const;
    void status();
};

void Mystack::status()
{
	for (int i = 0; i < n; ++i){
		cout << q[i] << " ";
	}
	cout << capacity << endl;
	cout << endl;
}

void Mystack::push(const int& d){
    q[n] = d;
    n++;
}

int Mystack::get_size() const{
    return n;
}

void Mystack::pop() {
    n--;
}

int Mystack::top() const{
    return q[n-1];
}


int main(){
    Mystack m(10);
    m.push(3);
    m.push(4);
    m.push(4);
    cout << m.top() << endl;
    m.status();
    m.pop();
    m.push(69);
    m.status();
    return 0;
}
















