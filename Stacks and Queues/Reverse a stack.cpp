/*
You have been given two stacks that can store integers as the data. Out of the two given stacks, 
one is populated and the other one is empty. You are required to write a function that reverses 
the populated stack using the one which is empty.
*/

#include<stack>
#include<iostream>
using namespace std;

//explanation about the solution written in the 'first time notes'
void reverseStack(stack<int> &input, stack<int> &extra) {
    //Write your code here
    if(input.size()<=1){ //base case
        return;
    }
    
    int top = input.top();
    input.pop();
    reverseStack(input, extra); //recursive call
    while(!input.empty()){
        extra.push(input.top());
        input.pop();
    }
    
    input.push(top);
    
    while(!extra.empty()){
        input.push(extra.top());
        extra.pop();
    }
}