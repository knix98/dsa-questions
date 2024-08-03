/*
You have been given a singly linked list of integers. Write a function to print the list in a reverse order.
To explain it further, you need to start printing the data from the tail and move towards the head of the list, 
printing the head data at the end.
Note :
You can’t change any of the pointers in the linked list, just print it in the reverse order.
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

// Here we cant modify the LL. Hence recursive is the only solution to print in reverse
void printReverse(Node *head)
{
    if(head == NULL){
        return;
    }
    
    printReverse(head->next);//recursion call to print the passed smaller LL in reverse
    
    cout << head->data << " ";
}