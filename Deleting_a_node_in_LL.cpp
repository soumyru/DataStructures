#include<bits/stdc++.h>
using namespace std;

class Node //Node
{
    public:
    int data; //data
    Node* next; //pointer to next node
};

void push(Node** head_ref,int new_data)
{
    Node* new_node=new Node();// allocated a new node at the front  of the list
    new_node->data=new_data;//assigned data in new node
    new_node->next=(*head_ref);//linked new node with pointer (or ref) to head node
    (*head_ref)=new_node;
}

void deleteNode(Node** head_ref,int key)//Given a pointer to head of a list and key //this Fn deletes 1st occurence of key in LL
{
    Node* temp=*head_ref;//head node stored
    Node* prev=NULL;
    
    if(temp!=NULL && temp->data==key)//if head node itself hold the key to be deleted
    {
        *head_ref=temp->next;//changed head
        delete temp;//freed old head
        return;
    }
    else//else search for the key to be deleted
    {
        while(temp!=NULL&& temp->data!=key)
        {
            prev=temp;
            temp=temp->next;
        }

        if(temp==NULL)//if key was not in LL
        return;

        prev->next=temp->next;//unlinked the node from LL
        //delete operator is used either for the pointers pointing to the memory allocated using the new operator or for a NULL
        delete temp;//freed memory
    }

}

void printList(Node* node)//prints LL contents starting from given node
{ 
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}


int main()
{
    //staring with empty list   
    Node* head=NULL;   //Since L.L. is empty, value of head is NULL.v

    //Adding elements in LL
    push(&head,7);
    push(&head,1);
    push(&head,3);
    push(&head,2);
    puts("Created LL: ");//It prints the passed string with a newline and returns an integer value. 
    //puts can only print string.
    printList(head);
    deleteNode(&head,1);
    puts("\nLL after deletion of 1: ");
    printList(head);
    return 0;
}