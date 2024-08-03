/*

Given an integer array A of size n. Find and print all the leaders present in the input array. 
An array element A[i] is called Leader, if all the elements following it (i.e. present at its right) are 
less than or equal to A[i].
Print all the leader elements separated by space and in the same order they are present in the input array.

Constraints :
1 <= n <= 10^6

Sample Input 1 :
6
3 12 34 2 0 -1
Sample Output 1 :
34 2 0 -1

*/
#include<iostream>
#include<climits>
using namespace std;

void Leaders(int* arr,int len)
{
    int leaderIndex = len-1; //we will store all the leaders starting from the end of the input arr
    int max = INT_MIN;
    
    for(int i=len-1; i>=0; i--){ 
        if(arr[i] >= max){              //condition for being a leader
            max = arr[i];               //update the max
            arr[leaderIndex--] = arr[i];//put the leader at leaderIndex and update leaderIndex for next leader 
        }
    }
    
    for(int i=leaderIndex+1; i<len; i++){ //print all the leaders
        cout << arr[i] << " ";
    }
}