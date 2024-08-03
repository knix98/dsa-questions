/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204217/offering/2650137/problem/13834?leftPanelTabValue=PROBLEM

Sam always likes to challenge Ninja with some problems. Today, he has come to Ninja for another challenge. Sam took a sorted array and rotated it clockwise by an unknown amount.

For example, he took a sorted array = [1, 2, 3, 4, 5] and if he rotates it by 2, then the array becomes: [4, 5, 1, 2, 3].
After rotating the sorted array, he asked Ninja Q queries, for each query Ninja has to search whether the number asked in that query is present in the rotated array or not, if the number is present then Ninja needs to tell Sam the index of the number, otherwise, he needs to tell Sam -1.

Since Ninja does not want to lose the challenge, he asked you to help him for the same. Your task is to find the index of the number asked in the query if it exists.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= N <= 10^6
-10^9 <= A[i] <= 10^9
1 <= Q <= 500
-10^9 <= Q[i] <= 10^9

Time Limit: 1sec
Sample Input 1:
5
4 5 1 2 3
3
5
7
4
Sample Output 1:
1
-1
0
Explanation For Sample 1:
In the 1st test case, 5 is found at the index of 1

In the 2nd test case, 3 is not found in the array, hence return -1.

In the 3rd test case, 4 is found at the index of 0.
Sample Input 2:
7
14 25 36 47 51 62 3
4
3
25
52
51
Sample Output 2:
6
1
-1
4
        
*/



// explanation written inb CN CP hand notes of binary search chapter in the starting
int search(int* arr, int n, int key) 
{
    int i=0, j=n-1;
    while(i<=j){
        int mid = (i+j)/2;

        if(arr[mid] == key) return mid;

        if(arr[mid] <= arr[j]){
            if(key > arr[mid] && key <= arr[j]) i = mid+1;
            else j = mid-1;
        }
        else{
            if(key < arr[mid] && key >= arr[i]) j = mid-1;
            else i = mid+1;
        }
    }

    return -1;
}