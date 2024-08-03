/*
You have been given a linked list of integers. Your task is to write a function that inserts a node at a given position,
'pos'.
Note:
Assume that the Indexing for the linked list always starts from 0.

If the given position 'pos' is greater than length of linked list, then you should return the same linked list without any change.
And if position 'pos' is equal to length of input linked list, then insert the node at the last position.

Sample Input 1:
3 4 5 2 6 1 9 -1
3 100
Sample Output 1:
3 4 5 100 2 6 1 9
*/

#include<iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int data)
    {
        this->data = data;
        this->next = NULL;
    }
};

Node* insertNode(Node *head, int i, int &data){
    if(i==0){ // (i==0 && head==0) case also handled here
        Node *temp = new Node(data);
        temp->next = head;
        return temp;
    }
    if(head == NULL){ // here i!=0, which means the i which was given originally was out of bounds of the LL
        return NULL;
    }

    Node *smallHead = insertNode(head->next, i-1, data);

    head->next = smallHead;

    return head;
}