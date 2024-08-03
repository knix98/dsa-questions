/*
For a given singly linked list of integers, arrange the elements such that all the even numbers are placed 
after the odd numbers. The relative order of the odd and even terms should remain unchanged.
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

Node *evenAfterOdd(Node *head)
{
	Node *eH = NULL, *eT = NULL, *oH = NULL, *oT = NULL; //eH = even head, oH = odd head
    Node *it = head; //it = iterator over whole LL
    while(it != NULL){
        if(it->data % 2 == 0){
            if(eH == NULL){
                eH = it;
                eT = it;
            }
            else{
                eT->next = it;
                eT = it;
            }
        }
        else{
            if(oH == NULL){
                oH = it;
                oT = it;
            }
            else{
                oT->next = it;
                oT = it;
            }
        }
        
        it = it->next;
    }
    
    if(oT == NULL){
        return eH;
    }
    else if(eT == NULL){
        return oH;
    }
    
    oT->next = eH; // connecting the even LL and odd LL
    eT->next = NULL;
    
    return oH;
}