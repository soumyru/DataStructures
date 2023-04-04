#include <iostream>
using namespace std;
#include "TrieNode.cpp"
#include <string>
class Trie
{
    TrieNode *root;

    public:
    Trie()
    {
        root=new TrieNode('\0');
    }
    //For us to use
    bool search(TrieNode *root,string word)
    {
        if(word.size()==0)
        return root->isTerminal;

        //small calculation
        int index=word[0]-'a';
        TrieNode * child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else
        {
            return false;
        }

        return search(child,word.substr(1));
    }
    //For user
    bool search(string word)
    {
        return search(root,word);
    }

    //For us to use
    void insertWord(TrieNode * root,string word)
    {
        //Base Case
        if(word.size()==0)
        {
            root->isTerminal=true;
            return;
        }

        //Small Calculation
        int index=word[0]-'a'; // word[0]-a=0 , word[0]-b=1 and so on...
        TrieNode * child;
        if(root->children[index]!=NULL)
        {
            child=root->children[index];
        }
        else{
            child=new TrieNode(word[0]);
            root->children[index]=child;
        }

        insertWord(child,word.substr(1));
    }

    //For user
    void insertWord(string word)
    {
        insertWord(root,word);
    }

    //For us to use
    void removeWord(TrieNode * root,string word)
    {
        //Base Case
        if(word.size()==0)
        {
            root->isTerminal=false; //terminal will be true if word exists, otherwise false 
            return;
        }

        //small calculation
        int index=word[0]-'a'; // word[0]-a=0 , word[0]-b=1 and so on...
        TrieNode * child;
        if(root->children[index]!=NULL) //is root's children != NULL?
        {
            child=root->children[index];  //child=root's children's address
        }
        else
        {
            return; //Word not found
        }
        removeWord(child,word.substr(1)); //substring of word from index 1 i.e., after removing 1st letter //if word='and
        //word.substr(1)=nd
        //now for next recursive call child becomes the root and substring becomes the word goes until word!=""

        if(child->isTerminal==false)
        {
            for(int i=0;i<26;i++)
            {
                if(child->children[i]!=NULL)
                return;
            }
        delete child;
        root->children[index]=NULL;
        }
        
    }

    //For user
    void removeWord(string word)
    {
        removeWord(root,word);
    }
};