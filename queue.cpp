#include <iostream>
using namespace std;

class Queue{
private:
    int size;
    int front;
    int rear;
    int *Q;
public:
    Queue(){
        front=rear=-1;
        size=10;
        Q=new int[size];
    }
    Queue(int size){
        front=rear=-1;
        this->size=size;
        Q=new int[size];
    }
    void enqueue(int x);
    int dequeue();
    void display();
};
void Queue::enqueue(int x){
    if(rear==size-1){
        cout<<"queue is full"<<endl;
    }else{
        rear++;
        Q[rear]=x;
    }
}
int Queue::dequeue(){
    int x=-1;
    if(front==rear){
        cout<<"queue is empty"<<endl;
    }else{
        front++;
        x=Q[front];
    }
    return x;
}
void Queue::display(){
    for(int i=front+1;i<=rear;i++){
        cout<<Q[i]<<" ";
    }
    cout<<endl;
}

int main() {
	Queue q(5);
	cout<<q.dequeue()<<endl;
	q.enqueue(2);
	q.enqueue(3);
	q.enqueue(4);
	q.enqueue(5);
	q.enqueue(6);
	q.enqueue(7);
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	cout<<q.dequeue()<<endl;
	q.display();
	return 0;
}
