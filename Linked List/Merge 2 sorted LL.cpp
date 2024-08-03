/*
You have been given two sorted(in ascending order) singly linked lists of integers.
Write a function to merge them in such a way that the resulting singly linked list is also sorted(in ascending order) 
and return the new head to the list.
Note :
Try solving this in O(1) auxiliary space.
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

// latest iterative approach written by me, same as the second approach, but easier to read
Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == NULL) return head2;
    else if(head2 == NULL) return head1;

    Node *head = NULL, *tail = NULL;
    while(head1 != NULL && head2 != NULL){
        Node* attach;
        if(head1->data < head2->data){
            attach = head1;
            head1 = head1->next;
        }
        else{
            attach = head2;
            head2 = head2->next;
        }
        attach->next = NULL;

        if(head == NULL){
            head = tail = attach;
        }
        else{
            tail->next = attach;
            tail = tail->next;
        }
    }

    if(head1 == NULL){
        tail->next = head2;
    }
    else{
        tail->next = head1;
    }

    return head;
}


//First Approach: Time comp: O(N+M), Space Comp: O(1).......................................................

//this func wud include *temp2 node right after *temp1 in LL1 and return the new head of LL2(i.e temp2->next)  
Node* includeNode(Node *temp1, Node *temp2){
    Node *newTemp2 = temp2->next;
    temp2->next = temp1->next;
    temp1->next = temp2;
    
    return newTemp2;
}

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){ //(head1 == NULL && head2 == NULL) also handled here
        return head1;
    }
    
    Node *ansHead = (head1->data < head2->data) ? head1 : head2; //establishing head of LL1(in which all the nodes will be sorted)
    Node *temp2 = (head1->data < head2->data) ? head2 : head1; //temp2 to travel over LL2
    Node *temp1 = ansHead; //temp1 to travel over LL1
    
    while(temp2 != NULL && temp1->next != NULL){
        if(temp1->next->data >= temp2->data){ //if temp2 node should be included now in final LL, then do it!
            temp2 = includeNode(temp1, temp2);
        }
        
        temp1 = temp1->next; //otherwise keep iterating over the final LL
    }
    
    if(temp2 != NULL){ //if some part of LL2 still remains while LL1 finished
        temp1->next = temp2;
    }
    
    return ansHead;
}



//APPROACH 2: RECURSIVE APPROACH: .......................................................
//Time: O(N+M), beacause each of the nodes from both the LLs will be called only once
//Space: O(N+M), for saving the execution contexts of all the calls

Node *mergeTwoSortedLinkedLists(Node *head1, Node *head2)
{
    if(head1 == NULL){
        return head2;
    }
    else if(head2 == NULL){
        return head1;
    }
    
	Node *head = (head1->data <= head2->data) ? head1 : head2; //save the smaller of the 2 given heads, in head
    Node *newHead2 = (head1->data <= head2->data) ? head2 : head1; //save the other head
    Node *smallHead = mergeTwoSortedLinkedLists(head->next, newHead2); //send for sorting the 2 heads, excluding the saved smaller head
    
    head->next = smallHead;
    
    return head;
}