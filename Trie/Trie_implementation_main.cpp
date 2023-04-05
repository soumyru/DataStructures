#include<iostream>
using namespace std;
#include "Trie_implementation.cpp"

int main()
{
    Trie t;
    t.insertWord("and");
    t.insertWord("are");
    t.insertWord("dot");

    cout<<t.search("and")<<endl; //1

    t.removeWord("and");
    cout<<t.search("and")<<endl; //0


}