#include <iostream>
using namespace std;

class Node{
public:
    int data;
    Node *next;
};
class HashTable{

public:
	Node** HT;
	HashTable();
	int hash(int key);
	void Insert(int key);
	int Search(int key);
	~HashTable();
};

HashTable::HashTable() {
	HT = new Node* [10];
	for (int i=0; i<10; i++){
		HT[i] = nullptr;
	}
}

int HashTable::hash(int key) {
	return key % 10;
}
void HashTable:: Insert(int key){
    int Hiindex=hash(key);
    Node *t=new Node;
    t->data=key;
    t->next=nullptr;
    if(HT[Hiindex]==nullptr){
        HT[Hiindex]=t;
    }else{
        Node *p=HT[Hiindex];
        Node *q=HT[Hiindex];
        while(p && p->data<key){
            q=p;
            p=p->next;
        }
        if(q==HT[Hiindex]){
            t->next=HT[Hiindex];
            HT[Hiindex]=t;
        }else{
            t->next=q->next;
            q->next=t;
        }
    }
}
HashTable::~HashTable() {
	for (int i=0; i<10; i++){
		Node* p = HT[i];
		while (HT[i]){
			HT[i] = HT[i]->next;
			delete p;
			p = HT[i];
		}
	}
	delete [] HT;
}

int HashTable::Search(int key){
    int Hiindex=hash(key);
    Node *p=HT[Hiindex];
    while(p && p->data<=key){
        if(p->data==key){
            return p->data;
        }
        p=p->next;
    }
    return -1;
}

int main() {
	int A[] = {16, 12, 25, 39, 6, 122, 5, 68, 75};
	HashTable H;
	for (int i=0; i<9; i++){
		H.Insert(A[i]);
	}
	cout<<H.Search(122)<<endl;
	return 0;
}
