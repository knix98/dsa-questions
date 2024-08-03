/*
Pairwise Sum of Hamming Distance

You are given an array ARR having N integers. Your task is to find the sum of Hamming Distance for each pair of the array elements.
Hamming Distance for two given integers 'A' and 'B' is defined as the minimum number of bits that needs to be toggled to make both the integers equal.
For example:
Consider A=4 and B=7
Binary representation of 4 = 100
Binary representation of 7 = 111
For the given example, if we flip the values of the last two least significant bits of A to 1 then A will become 7. As we can change the value of A to B by 2 flips. Therefore the Hamming Distance, in this case, is 2.
Input format:
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains an integer ‘N’ denoting the number of elements in the array.

The second line of each test contains 'N' space-separated integers denoting the array elements.
Output Format:
For each test case, return the sum of Hamming Distance for all the pairs.
Note:
You are not required to print anything just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 10^4
0 <= ARR[i] <=10^9

Time limit: 1 second
Sample Input 1:
2
3
4 1 3
2
2 2
Sample Output 1:
12
0
Explanation of sample input 1:
For the first test case:
All the 9 possible pairs of array elements are (4,4), (4,1), (4,3), (1,4), (1,1), (1,3), (3,4), (3,1), (3,3)
1) (4,4) => Hamming Distance = 0
2) (4,1) => Hamming Distance = 2
3) (4,3) => Hamming Distance = 3 
4) (1,4) => Hamming Distance = 2
5) (1,1) => Hamming Distance = 0
6) (1,3) => Hamming Distance = 1
7) (3,4) => Hamming Distance = 3
8) (3,1) => Hamming Distance = 1
9) (3,3) => Hamming Distance = 0
The sum of all the above values is 12. Therefore, the answer is 12 in this case.

For the second test case:
As all the elements of the array are equal, the hamming distance is 0 for every pair of array elements. Therefore the overall sum of Hamming distance is 0 in this case.
Sample Input 2:
2
4
1 1 5 7
1
4
Sample Output 2:
14
0
*/






// Approach : as int range given is 32 bits in question ( <= 10^9 ), so for each of the 31 positions of bits (i=0 to 30) we can check
// how many 1s and 0s are there in all these given numbers a t particualr bit position
// and then for example we get that at 0th bit position we found four 0s and two 1s amongst all the numbers
// so we know that the pairs of (0,1) will result in toggling of 1 of the bit from the pair
// so number of (0,1) pairs would be 4*2 = 8
// but as the question as the question says that we have to count (a,b) and (b,a) separately
// so total toggling required at 0th bit position amongst all the numbers would be = 8*2 = 16
// similarly do for all the other 30 positions and add them to get the final answer total
// Time : O(n * 31)

#define ll long long
 
long long int sumOfHammingDistance(int *arr, int n) {
    ll ans = 0;

    for(int i=0; i<31; i++){
        ll ones = 0, zeroes = 0;
        int checker = 1<<i;
        
        for(int j=0; j<n; j++){
            if((arr[j] & checker) == 0) zeroes++;
            else ones++;
        }

        ans += (zeroes * ones * 2);
    }

    return ans;
}