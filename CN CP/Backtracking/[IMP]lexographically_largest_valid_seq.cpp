/*
You are given a positive integer N. Your task is to create the lexicographically largest sequence of length 2*N - 1 containing integers between 1 to N such that:
1. 1 occurs in the sequence exactly once.
2. Each integer between 2 to N(inclusive) occurs in the sequence exactly twice.
3. For each integer i between 2 to N, the distance between the two occurrences of i should be exactly i.
Note:
1. A sequence A is lexicographically larger than a sequence B (of the same length), if in the first position where A and B differ, sequence A has a number greater than the corresponding number in B.
2. It is guaranteed that under the given constraints, there is always a solution. 
Input Format:
The first line contains an integer, ‘T’ which denotes the number of test cases or queries to be run. Then, the T test cases follow.

The first and the only line of each test case contains one integer N, as described in the problem statement.
Output Format:
For each test case, print in a new line, 2*'N' - 1 space-separated integer representing the lexicographically largest sequence for the given input.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 100
1 <= N <= 20

Time Limit: 1 second
Sample Input 1:
1
2
Sample Output 1:
2 1 2
Explanation Of Sample Input 1:
In test case 1: Since 1 occurs exactly once and 2 occurs exactly twice, and the distance between the two occurrences of 2 is 2. The sequence {2,1,2} is also the lexicographically largest sequence possible that satisfies the given condition.
Sample Input 2:
1
3
Sample Output 2:
3 1 2 3 2
Explanation Of Sample Input 2:
In test case 1: [3, 1, 2, 3, 2] is the largest lexicographically sequence which we need.
*/



// Basically the algo is : that greatest numbers should come at the earliest possible position
// So we start from the MSB (0th) position and try to set the highest number possible in that position thru recursion
// If valid return true, otherwise try with the next largest number
// Time : O(n!), Space : O(n)
bool solve(vector<int> &ans, int ansSize, vector<int> &setDigits, int n, int curIndex){
    if(curIndex == ansSize) return true;  // base case

    if(ans[curIndex] != 0) { // if this index is already set with some digit, then move forward
        return solve(ans, ansSize, setDigits, n, curIndex+1);
    }

    for(int j = n; j >= 1; j--){  // checking the feasibility of largest possible integer at this index
        if(!setDigits[j]){  
            if(j == 1){  // case of setting 1 has to be handeled differently, because only one 1 needs to be set
                ans[curIndex] = j;
                setDigits[j] = 1;

                if(solve(ans, ansSize, setDigits, n, curIndex+1)) return true;
                else{
                    ans[curIndex] = 0;
                    setDigits[j] = 0;
                }
            }
            else if(curIndex + j < ansSize && ans[curIndex + j] == 0){ // if 2 positions are available for a number to be set according to given constraints...
                ans[curIndex] = j;
                ans[curIndex+j] = j;
                setDigits[j] = 1;

                if(solve(ans, ansSize, setDigits, n, curIndex+1)) return true;
                else{
                    ans[curIndex] = 0;
                    ans[curIndex+j] = 0;
                    setDigits[j] = 0;
                }
            }
        }
    }

    return false;
}

vector<int> validSequence(int n) {
    vector<int> ans(2*n - 1, 0);  // for storing the answer sequence
    vector<int> setDigits(n+1, 0); // for maintaining the digits which have been set in the answer sequence

    solve(ans, 2*n - 1, setDigits, n, 0);

    return ans;
}