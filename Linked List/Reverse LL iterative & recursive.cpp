/*

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



//RECURSIVE.......................
//Time: O(n)
//Space: O(n)
Node *reverseLinkedListRec(Node *head){
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node* smallHead = reverseLinkedListRec(head->next);
    head->next->next = head;
    head->next = NULL;
    return smallHead;
}


//ITERATIVE..........................
//Space O(1), Time O(n)
Node* reverseLL(Node *head){
    if(head->next == NULL){
        return head;
    }
    
    Node *prev = NULL;
    Node *curr = head;
    
    while(curr != NULL){
        Node *nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }
    
    return prev;
}