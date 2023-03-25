#include <iostream>
using namespace std;
#include "StackUsingArray.cpp"

int main()
{
    StackUsingArray s(4);
    s.push(10);
    s.push(20);
    s.push(30);
    s.push(40);
    s.push(50); //stack full

    cout<<s.top()<<endl;//40

    cout<<s.pop()<<endl;//40
    cout<<s.pop()<<endl;//30
    cout<<s.pop()<<endl;//20

    cout<<s.size()<<endl;//1

    cout<<s.isEmpty()<<endl;//false = 0

}

//In case of dynamic array
// int main()
// {
    
//     StackUsingArray s; 
//     s.push(10);
//     s.push(20);
//     s.push(30);
//     s.push(40);
//     s.push(50); 

//     cout<<s.top()<<endl;//50

//     cout<<s.pop()<<endl;//50
//     cout<<s.pop()<<endl;//40
//     cout<<s.pop()<<endl;//30

//     cout<<s.size()<<endl;//2

//     cout<<s.isEmpty()<<endl;//false = 0

// }