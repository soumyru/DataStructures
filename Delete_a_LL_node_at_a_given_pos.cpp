#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
};

void push(Node** head_ref,int new_data)
{
    Node* new_node=new Node();
    new_node->data=new_data;
    new_node->next=(*head_ref);
    (*head_ref)=new_node;
}

void deleteNode(Node** head_ref,int pos)
{
    if(*head_ref==NULL)//if LL is empty
    return;

    Node* temp=*head_ref;//stored head node

    if(pos==0)//if head needs to be removed
    {
        *head_ref=temp->next;//change head
        free(temp);//free old head
        return;
    }

    for(int i=0;temp!=NULL&&i<pos-1;i++)//find prev node of the node eto be deleted
    {
        temp=temp->next;
    }

    if (temp==NULL || temp->next==NULL)//if pos is more than no. of nodes
    return;

    Node* next=temp->next->next;//temp->node is the node to be deleted , so storing pointer to the next node of it

    free(temp->next);//unlink node from LL
    temp->next=next;//unlinked deleted node from list
}

void printList(Node* node)
{
    while(node!=NULL)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
}


int main()
{
    Node* head=NULL; //empty list
    push(&head,7);
    push(&head,1);
    push(&head,3);
    push(&head,2);
    push(&head,8);
    cout<<"Created LL: ";
    printList(head);
    deleteNode(&head,4);
    cout<<"\nLinked List after deletion at position 4: ";
    printList(head);
    return 0;
}

