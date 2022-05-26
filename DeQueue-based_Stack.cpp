#include <iostream>
using namespace std;

#include <deque>

class Mystack{
private:
    int n = 0;
    deque<int> q;
public:
    void push(const int& d);
    int get_size() const;
    void pop();
    int top() const;
    void status();
};

void Mystack::status()
{
    deque<int>::iterator it;
    for (it = q.begin(); it != q.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

void Mystack::push(const int& d){
    q.push_front(d);
    n++;
}

int Mystack::get_size() const{
    return n;
}

void Mystack::pop() {
    q.pop_front();
    n--;
}

int Mystack::top() const{
    return q.front();
}


int main(){
    Mystack m;
    m.push(3);
    m.push(4);
    cout << m.top();
    m.status();
    m.pop();
    m.status();
    return 0;
}
