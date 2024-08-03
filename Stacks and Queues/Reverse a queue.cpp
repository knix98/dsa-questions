/*
You have been given a queue that can store integers as the data. 
You are required to write a function that reverses the populated queue itself without using any other data structures.
*/

#include<queue>
#include<iostream>
using namespace std;

void reverseQueue(queue<int> &input) {
	// Write your code here
    if(input.size()<=1){
        return;
    }
    
    int front = input.front();
    input.pop();
    reverseQueue(input);
    input.push(front);
}