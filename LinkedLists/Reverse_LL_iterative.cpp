#include <iostream>
using namespace std;
#include "Node.cpp"

Node *takeinput() {
    int data;
    cin >> data;
    Node *head = NULL, *tail = NULL;
    while (data != -1) {
        Node *newnode = new Node(data);
        if (head == NULL) {
            head = newnode;
            tail = newnode;
        } else {
            tail->next = newnode;
            tail = newnode;
        }
        cin >> data;
    }
    return head;
}

Node *reverseLinkedList(Node *head) {
    // Write your code here
	if(head==NULL || head->next==NULL)
	return head;
	
	Node * prev=NULL;
	Node * curr=head;
	Node * next=curr->next;

	while(curr!=NULL)
	{
		next=curr->next;
		curr->next=prev;
		prev=curr;
		curr=next;
	}
	return prev;
}

void print(Node *head) {
    Node *temp = head;

    while (temp != NULL) {
        cout << temp->data << " ";
        temp = temp->next;
    }

    cout << "\n";
}

int main() {
    int t;
    cin >> t;

    while (t--) {
        Node *head = takeinput();
        head = reverseLinkedList(head);
        print(head);
    }

    return 0;
}

/*
I/P:
1   //t
1 2 3 4 5 6 7 8 -1
O/P:
8 7 6 5 4 3 2 1   
*/