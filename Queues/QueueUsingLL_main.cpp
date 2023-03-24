#include<iostream>
using namespace std;
#include "QueueUsingLL.cpp"

int main(){
    QueueUsingLL<int> q;
    q.enqueue(10);
    q.enqueue(20);
    q.enqueue(30);
    q.enqueue(40);
    q.enqueue(50);
    q.enqueue(60);

    cout<<q.front()<<endl;//10 
    cout<<q.dequeue()<<endl;//10
    cout<<q.dequeue()<<endl;//20
    cout<<q.dequeue()<<endl;//30

    cout<<q.getSize()<<endl;//3
    cout<<q.isEmpty()<<endl;//0 //false
}