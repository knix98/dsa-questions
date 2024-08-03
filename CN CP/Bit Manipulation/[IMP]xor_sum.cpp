/*
Xor Sum

You are given two arrays, ‘arr1’ of size 'N' and ‘arr2’ of size 'M'. You need to create an array of bitwise AND of all the possible pairs between the elements of both arrays, and your task is to find the XOR sum of the array. The XOR sum of an array is equal to the XOR of all elements of the array.
Note:
The XOR sum of [A, B, C] is equal to A XOR B XOR C.
For example:
You are given an ‘arr1’ = [3, 2, 8] and ‘arr2’ = [1, 4, 3], therefore the AND of all possible pairs is [(3 & 1), (3 & 4), (3 & 3), (2 & 1), (2 & 4), (2 & 3), (8 & 1), (8 & 4), (8 & 3)]. So the resulting Array will be [1, 0, 3, 0, 0, 2, 0, 0, 0] therefore XOR sum of the result array is 0 . Hence the answer is 0.
Input Format:
The first line of input contains the single integer ‘T’ representing the number of test cases.

The first line of each test case contains two space-separated integers, ‘N’ and ‘M’, representing the size of ‘arr1’ and ‘arr2’, respectively.

The second line of  each test case contains ‘N’ space-separated integers representing the elements of the array ‘arr1’

The third line of each test case contains ‘M’ space-separated integers representing the elements of the array ‘arr2’.
Output Format:
For each test case, print the single integer representing the XOR sum of bitwise AND of all pairs of the arrays ‘arr1’ and ‘arr2’.

Print a separate line for each test case.
Constraints:
1 <= T <= 10
1 <= N, M <= 10^6
0 <= arr1[i], arr2[i] <= 10^9

Time Limit: 1 sec
Note:
You do not need to print anything. It has already been taken care of. Just implement the function.
Sample Input 1:
2
3 3
3 2 8
1 4 3
2 1
4 12
8
Sample Output 1:
0
8
Explanation :
For the first test case, ‘arr1’ = [3, 2, 8] and ‘arr2’ = [1, 4, 3], therefore the AND of all possible pairs is [(3 & 1), (3 & 4), (3 & 3), (2 & 1), (2 & 4), (2 & 3), (8 & 1), (8 & 4), (8 & 3)]. So the resulting array will be [1, 0, 3, 0, 0, 2, 0, 0, 0] therefore XOR sum of the result array is 0. Hence the answer is 0.

For the second test case ‘arr1’ = [4, 12] and ‘arr2’ = [8], therefore the AND of all possible pairs is [(4 & 8), (12 & 8)]. So the resulting array will be [0, 8] therefore XOR sum of the result array is 8. Hence the answer is 8.
Sample Input 2:
2
5 10
28 92 14 19 51
100 5 20 15 31 99 51 49 63 23
8 4
59 34 95 83 83 89 71 9
12 62 72 0
Sample Output 2:
44
80
*/





// lets consider only the bits at a particular bit position , lets say 0th position
// so if after getting all the new numbers generated by doing AND operation amongst different elems of arr1 and arr2
// the bits at 0th positions are 0,1,1,1,0,0 
// So we know that, if we are doing XOR operation amongst 0s and 1s , then result depends upon whether number of set bits are odd or even
// So in this example, on doing XOR amongst 0,1,1,1,0,0  , result would be 1
// which means in our final answer int, there would be a set bit at 0th position

// So the approach is, we just need to get the number of set bits at the particular bit position, for every bit position
// Now if number of set bits at 0th position in arr1 is 3 and number of set bits at 0th position in arr2 is 2
// then the number of total set bits that we would get in the AND operations numbers array at 0th position would be 3*2  = 6

int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    int ans = 0;
    int bitPositionMultiplier = 1;

    for(int i=0; i<31; i++){
        int arr1Ones = 0, arr2Ones = 0; // for finding number of set bits at ith position in arr1 and arr2 separately
        int checker = 1<<i;

        for(int j=0; j<max(arr1.size(), arr2.size()); j++){
            if(j < arr1.size() && ((arr1[j] & checker) != 0)) arr1Ones++;
            if(j < arr2.size() && ((arr2[j] & checker) != 0)) arr2Ones++;
        }

        int totalOnesAfterAndOperationAtThisBitPosition = arr1Ones * arr2Ones;  //  total set bits that we would get in the AND operations numbers array at ith position
        if(totalOnesAfterAndOperationAtThisBitPosition % 2 == 1) ans += bitPositionMultiplier; // if there is a set bit in our final answer int, at this position, then we need to add (2^i) in our answer

        bitPositionMultiplier *= 2;
    }

    return ans;
}




// latest code I wrote using same approach as above but with a little more trick optimisation
int xorSum(vector<int> &arr1, vector<int> &arr2)
{
    int ans = 0;
    for(int i=0; i<31; i++){
        int ones = 0;  // counting set bits at ith bit position in elems of arr1
        for(int a : arr1){
            if(a & 1<<i) ones++;
        }

        if(!(ones % 2)) continue;  // if set bits found are even, means eventually total set bits would also be even after multiplication
                                   // so in ans at this bit position, there would be 0, so continue

        ones = 0;
        for(int a : arr2){ // now counting set bits at ith bit position in elems of arr2
            if(a & 1<<i) ones++;
        }

        if(ones % 2) ans = ans | 1<<i;  // from previous traversal over arr1 we know that there are odd set bits in arr1 at ith bit position
                                        // so if odd set bits in arr1 at ith bit position in arr2 also , then only we would get 
                                        // total set bits would also be odd after multiplication, so then only set a bit at this bit position in ans 
    }

    return ans;
}