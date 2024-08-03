/*
You have been given a singly linked list of integers where the elements are sorted in ascending order. 
Write a function that removes the consecutive duplicate values such that the given list 
only contains unique elements and returns the head to the updated list.

Sample Input 1 :
1 2 3 3 3 3 4 4 4 5 5 7 -1
Sample Output 1 :
1 2 3 4 5 7 
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

Node *removeDuplicates(Node *head)
{
    //Write your code here
    if(head == NULL || head->next == NULL){
        return head;
    }
    
    Node *temp = head;
    while(temp->next != NULL){
        if(temp->data == temp->next->data){
            Node *del = temp->next;
            temp->next = del->next;
            delete del;
        }
        else{
            temp = temp->next;
        }
    }
    
    return head;
}