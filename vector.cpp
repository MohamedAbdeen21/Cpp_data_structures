// Mohamed Yasser Abdeen 120190031

#include <iostream>
using namespace std;

class Vector{
private:
	int nsize;
	int capacity;
	int* A;
public:
	Vector(){nsize = 0; capacity = 0; A = new int[0];}
	Vector(int n){nsize = 0; capacity = n; A = new int[n];}
	~Vector(){delete [] A;}
	bool empty() const;
	void reserve(int n);
	void resize(int n);
	void insert(int i, const int& d);
	void push_back(const int& d);
	void pop_back();
	void erase(int i);
	int size();
	int& at(int i);
	int& operator[](int i);
	int& front();
	int& back();
	
};

void Vector::reserve(int n){
	if (n < capacity){
		return;
	}else{
		int* B = new int[capacity + n];
		for (int i = 0; i != capacity; ++i){
			B[i] = A[i];
		}
		delete [] A;
		A = B;
		capacity = capacity + n;
	}
}

void Vector::resize(int n){
	int* B = new int[n];
	for (int i = 0; i != n; ++i){
		B[i] = A[i];
	}
	delete [] A;
	A = B;
	capacity = n;
}

bool Vector::empty() const{
	return (nsize == 0);
}

int& Vector::at(int i){
	if (i < 0 || i >= nsize){
		throw out_of_range("Index out of range");
	}
	return A[i];
}

int& Vector::operator[](int i){
	return A[i];
}

int Vector::size(){
	return nsize;
}

void Vector::push_back(const int& d){
	A[nsize] = d;
	nsize++;
}

void Vector::insert(int i, const int& d){
	if (nsize == capacity){
		reserve(10);
	}
	for (int k = nsize; k != i; --k){
		A[k] = A[k-1];
	}
	A[i] = d;
	nsize++;
}

void Vector::erase(int i){
	for (int k = i + 1; k < nsize; ++k){
		A[k-1] = A[k];
	}
	nsize--;
}

void Vector::pop_back(){
	nsize--;
}
int& Vector::front(){
	return A[0];
}

int& Vector::back(){
	return A[nsize];
}

int main(){
	Vector v;
	v.push_back(7);
	cout << v[0] << endl;
	v.insert(0,1);
	cout << v[1] << endl;
	v.insert(1,2);
	v.erase(0);
	cout << v[0] << endl;
	v.insert(0,1);
	v.erase(1);
	cout << v[0] << endl;
	return 0;
}























