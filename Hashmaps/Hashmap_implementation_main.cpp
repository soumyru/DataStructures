#include<iostream>
#include "Hashmap_implementation.cpp"
using namespace std;

int main()
{
    ourMap<int> map;
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        int value=i+1;
        map.insert(key,value);
        cout<<map.getLoadFactor()<<endl; 

    }
    /*o/p:
    0.2
    0.4
    0.6
    0.4
    0.5
    0.6
    0.7
    0.4
    0.45
    0.5
    */

    cout<<map.size()<<endl; //10
    map.remove("abc2");
    map.remove("abc7");

    cout<<map.size()<<endl; //8
    for(int i=0;i<10;i++)
    {
        char c='0'+i;
        string key="abc";
        key=key+c;
        cout<<key<<":"<<map.getValue(key)<<endl;
    }
    /*
    O/P:
abc0:1
abc1:2
abc2:0
abc3:4
abc4:5
abc5:6
abc6:7
abc7:0
abc8:9
abc9:10
    */
    cout<<map.size()<<endl; //8
}