/*
Given an array of n elements, where each element is at most k away from its target position, 
devise an algorithm that sorts in O(n log k) time. For example, 
let us consider k is 2, an element at index 7 in the sorted array, which can be at indexes 5, 6, 7, 8, 9 in the given array.

Input : arr[] = {6, 5, 3, 2, 8, 10, 9}
            k = 3 
Output : arr[] = {2, 3, 5, 6, 8, 9, 10}

Input : arr[] = {10, 9, 8, 7, 4, 70, 60, 50}
         k = 4
Output : arr[] = {4, 7, 8, 9, 10, 50, 60, 70}
*/


//Solution explanation written in DSA revision notes
#include<iostream>
using namespace std;
#include<queue>
void sort_k_sorted_array(int a[], int n, int k){ //n = size of array 
    if(n<=1 || k==0) return;

    priority_queue<int, vector<int>, greater<int>> pq; // a min pq, since we need to sort in ascending order

    for(int i=0; i<k+1; i++){ //first push the first k+1 elements into min-pq to determine the first element in the sorted array
        pq.push(a[i]);
    }

    int j=0; //this index wud keep storing the final sorted values
    for(int i=k+1; i<n; i++){
        a[j] = pq.top(); 
        j++;
        pq.pop();
        pq.push(a[i]);
    }

    while(!pq.empty()){
        a[j] = pq.top();
        j++;
        pq.pop();
    }
}