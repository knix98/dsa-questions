/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204216/offering/2653314/problem/13752?leftPanelTabValue=PROBLEM

You have been given an integer array/list 'ARR' of size 'N'. You are supposed to tell that if it could become non-decreasing by modifying at most 1 element.

We define an array as non-decreasing, if ARR[i] <= ARR[i + 1] holds for every i (0-based) such that (0 <= i <= N - 2).

Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 50
1 <= N <= 10 ^ 4
- 10 ^ 9 <= ARR[i] <= 10 ^ 9

Where 'N' is the size of the given array/list.
And, ARR[i] denotes the i-th element in the array/list 'ARR'.

Time Limit: 1sec
Sample Input 1 :
2
4
5 7 2 10
3
8 4 2
Sample Output 1 :
true
false
Explanation to Sample Input 1 :
For Test Case 1 we can have a possible non-decreasing array: 5 7 8 10
Where only the element at index 1 has been modified.

For Test Case 2 there is no possible way to make the array non-decreasing by modifying at most 1 element.

*/


// APPROACH : the graph for this arr should not have a dip anywhere. So whenever a dip encountered between i and i-1
// try to correct it by either bringing i up atmost to level of i+1 or by bringing i-1 down atmost to level of i-2
// draw the graph once of an increasing points , and then in between 2 points bring a dip and then you will understand the above point
bool isPossible(int *arr, int n) {
    bool dicrepencyEncountered = false;
    for(int i=1; i<n; i++){
        if(arr[i] < arr[i-1]){
            if(dicrepencyEncountered) return false;  // if 2nd discrepency encountered, return false

            dicrepencyEncountered = true;

            // checking whether this dicrepenecy can be solved
            if(i == 1 || i == n-1){
                // then start or end of arr case
                if(i==1) arr[0] = arr[1];
                else arr[i] = arr[i-1];
            }
            // the following 2 else ifs are cases where i is in middle of the arr
            else if(arr[i+1] >= arr[i-1]){
                arr[i] = arr[i+1];
            }
            else if(arr[i-2] <= arr[i]){
                arr[i-1] = arr[i-2];
            }
            else {
                // this dicrepency cant be solved, so return false;
                return false;
            }
        }
    }

    return true;
}