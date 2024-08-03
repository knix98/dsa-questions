/*
You have been given a random integer array/list(ARR) and a number X. 
Find and return the triplet(s) in the array/list which sum to X.
Note :
Given array/list can contain duplicate elements.
*/

#include<algorithm>
using namespace std;

int pairSum(int *arr, int n, int num)
{   
    int pairs = 0;
    int i=0,j=n-1; //i to iterate from start, j to iterate from end
    while(i<j){
        if((arr[i]+arr[j]) < num){
            i++;
        }
        else if((arr[i]+arr[j]) > num){
            j--;
        }
        else if((arr[i]+arr[j]) == num){
            if(arr[i+1]==arr[i] || arr[j-1]==arr[j]){//checking whether there are multiple occurrences of arr[i] or arr[j]
                int in=1,jn=1;//'in' for counting occurrences of arr[i] and 'jn' for occurrences of arr[j]						 
                while(arr[i+1]==arr[i]){
                    in++;
                    i++;
                }
                
                if(i==j){//implies this type of case - [1,2,3,3,3,3,4,5]     
                    pairs = pairs + (in*(in-1))/2;
                    return pairs;
                }
                
                while(arr[j-1]==arr[j]){
                    jn++;
                    j--;
                }
                
                pairs = pairs + (in*jn);//after counting in,jn for this sort of case[1,2,3,3,4,5,5,5,6,7]
                i++;j--;
            }
            else{ //if multiple occurrences of arr[i] and arr[j] are not there
                pairs++;
                i++;j--;
            }
        }
    }
    
    return pairs;
}  

int tripletSum(int *arr, int n, int num)
{
	//Write your code here
    sort(arr, arr+n); //sort this array first step only...so that sorting happens only once and before anything else
    int triplets=0;
    
    for(int i=0; i<n-2; i++){
        triplets += pairSum(arr+i+1, n-i-1, num-arr[i]);
    }
    
    return triplets;
}