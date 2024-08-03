/*
You have been given a head to a singly linked list of integers. 
Write a function check to whether the list given is a 'Palindrome' or not.
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

// this is the best solution for this problem , because time = O(n) and we are not using any extra space
//SOLUTION...................
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

bool isPalindrome(Node *head)
{
    if(head == NULL || head->next == NULL){
        return true;
    }
    
	Node *fast = head; //fast would reach the end
    Node *slow = head; //slow would reach till mid point
    
    while(fast->next != NULL && fast->next->next != NULL){ //first find mid-point of LL
        fast = fast->next->next;
        slow = slow->next;
    }
    
    Node *head2 = reverseLL(slow->next); //reverse the other half LL
    Node *head1 = head;
    slow->next = NULL; //ending of head1
    
    while(head1 != NULL && head2 != NULL){ //compare 1st half LL and 2nd half reversed LL
        if(head1->data != head2->data){
            return false;
        }
        head1 = head1->next;
        head2 = head2->next;
    }
    
    return true;
}