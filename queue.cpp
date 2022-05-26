#include <iostream>
using namespace std;

#include <deque>

class queue{
private:
    int n = 0;
    deque<int> q;
public:
    void push(const int& d);
    int get_size() const;
    void pop();
    int top() const;
    int get_size();
    void status();
};

void queue::status()
{
    deque<int>::iterator it;
    for (it = q.begin(); it != q.end(); ++it)
        cout << ' ' << *it;
    cout << '\n';
}

void queue::push(const int& d){
    q.push_back(d);
    n++;
}

int queue::get_size(){
    return n;
}

void queue::pop() {
    q.pop_front();
    n--;
}

int queue::top() const{
    return q.front();
}


int main(){
    queue m;
    m.push(3);
    m.push(4);
    cout << '\n' << m.top() << endl;
    m.status();
    m.pop();
    m.status();
    return 0;
}
