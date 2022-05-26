using namespace std;
#include <bits/stdc++.h>

class PQ{
	public:
int H [10] = {999,999,999,999,999,999,999,999,999,999};
int last = 1;

int parent(int index){
	return index/2;
}

int leftchild(int index){
	return index*2 + 1;
}

int rightchild(int index){
	return index*2;
}

int top(){
	return H[1];
}

void swap(int index1, int index2){
	int temp = H[index1];
	H[index1] = H[index2];
	H[index2] = temp;
}

void upheap(int index){
	while (H[parent(index)] > H[index]){
		if (parent(index) == 0) break;
		swap(parent(index), index);
		index = parent(index);
	}
}

void downheap(int index = 1){
	int minim = H[leftchild(index)] <= H[rightchild(index)]? leftchild(index):rightchild(index);
	if (H[index] < H[minim]) return;
	else{
		swap(index,minim); 
		downheap(minim);
	}
}

void insert(int value){
	H[last] = value;
	upheap(last++);
}

void remove(){
	if (last == 2){ H[1] = 999; return;}
	H[1] = H[--last];
	H[last] = 999;
	downheap();
}

};

int main(){
	PQ p;
	p.insert(2);
	p.insert(5);
	p.remove();
	p.insert(0);
	for (auto i: p.H) cout << i << " ";
	cout << p.top() << endl;
	return 0;
}
