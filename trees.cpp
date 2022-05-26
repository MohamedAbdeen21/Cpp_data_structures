#include <iostream>
#include <vector>
using namespace std;

class Node{
	private:
		int value;
		vector<Node>* children;
		Node* parent;
	public:
		Node(int val):value(val),parent(nullptr){}
		bool isRoot() const{
			return (parent == nullptr);
		}
		bool isExternal() const{
			return ((*children).empty());
		}	
		void addChildren(vector<int> vec){
			for (int v: vec){
			(*children).push_back(Node(v));
			}
		}
};

int main(){
	Node x = Node(3);
	cout << x.isRoot() << endl;
	cout << x.isExternal() << endl;
	vector<int> vec = {4,5,6};
	x.addChildren(vec);
	cout << x.isExternal() << endl;

	return 0;
}
