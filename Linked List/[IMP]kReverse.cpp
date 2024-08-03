/*
Given a singly linked list of integers, reverse the nodes of the linked list 'k' at a time and return its modified list.
'k' is a positive integer and is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of 'k,' then left-out nodes, in the end, should be reversed as well.
Example :
Given this linked list: 1 -> 2 -> 3 -> 4 -> 5

For k = 2, you should return: 2 -> 1 -> 4 -> 3 -> 5

For k = 3, you should return: 3 -> 2 -> 1 -> 5 -> 4
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


// latest iterative approach written by me
void reverseLL(Node *head){
    Node *curr = head;
    Node *prev = NULL;
    Node *nextt = NULL;
    while(curr != NULL){
        nextt = curr->next;
        curr->next = prev;
        prev = curr;
        curr = nextt;
    }
}

Node *kReverse(Node *head, int k) {
    if(k <= 1) return head;

    Node* temp = head;
    head = NULL;
    Node *leftTail = NULL, *rightHead = NULL;
    Node *smallHead;
    while(temp != NULL){
        smallHead = temp;
        int count = k-1;
        while(count && temp->next != NULL){
            temp=temp->next;
            count--;
        }

        rightHead = temp->next;
        temp->next = NULL;

        // so currently the small intermediate LL which needs to be reversed,
        // this small LL's head is in smallHead and tail is in temp
        reverseLL(smallHead);
        // after reversing small LL, small LL's head is in temp and tail is in smallhead

        // so now lets fit this small LL in main LL using leftTail and rightHead
        if(head == NULL) head = temp;
        else leftTail->next = temp;

        smallHead->next = rightHead;

        // setting leftTail and temp for next iteration
        leftTail = smallHead;
        temp = rightHead;
    }

    return head;
}



//Iterative Approach (more complex)...............................................................................................
// space: O(1), time: O(n)
Node* reverseLL(Node *head){
    if(head == NULL || head->next == NULL){
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

Node *kReverse(Node *head, int k)
{
    if(k == 0){ //this is IMP, since int count is starting from 1, so k==0 case would give error
        return head;
    }
    
	int count = 1;
    Node *temp = head; //for iterating over whole LL
    Node *LHStail = NULL; //for storing the tail node of the LHS disconnected LL
    head = NULL; //will store the final updated head in future
    
    while(temp != NULL){
        Node *countK = temp; //countK would stop when it reaches the Kth node starting from temp node
        while(count != k && countK->next != NULL){
            countK = countK->next;
            count++;
        }
        Node *RHShead = countK->next; //store the head node of the RHS disconnected LL
        countK->next = NULL;
        Node *smallHead = reverseLL(temp); //send the LHS disconnected LL for reversal
        
        if(head == NULL){ //store the updated head only the first time
            head = smallHead;
        }
        temp->next = RHShead; //since temp still is pointing towards the initial head node which has now become the last node after reversal
                              //so connect the temp with RHShead
        
        if(LHStail != NULL){ //if LHStail is not NULL, means it contains the tail of the already kReversed LHS LL
            LHStail->next = smallHead; //so connect the reversed head in the kReversed LHS LL
        }
        
        LHStail = temp; //update the LHS tail, since new k elements were attached to the LHS kReversed LL
        temp = temp->next; //update temp for next round. Now temp points towards RHShead
        count = 1; //restore count to 1
    }
    
    return head;
}


//Recursive Approach (easier solution).....................................................................
Node *kReverse(Node *head, int k)
{
	//Write your code here
	if(head == NULL || head->next == NULL || k==0 || k==1){
        return head;
    }
    
    Node *prev = NULL, *curr = head, *fwd = NULL;
    Node *tail1 = head;
    
    //reverse the first k elements
    for(int i=1; i<=k; i++){
        fwd = curr->next;
        curr->next = prev;
        prev = curr;
        curr = fwd;
        if(curr == NULL){
            return prev;
        }
    }
    
    //send the other remaining LL to recursion
    Node *head1 = prev;
    
    Node *head2 = kReverse(curr, k);
    
    tail1->next = head2;
    
    return head1;
}