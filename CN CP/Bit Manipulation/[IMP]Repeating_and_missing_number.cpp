/*
You are given an array 'nums' consisting of first N positive integers. But from the N integers, one of the integers occurs twice in the array, and one of the integers is missing. You need to determine the repeating and the missing integer.
Example:
Let the array be [1, 2, 3, 4, 4, 5]. In the given array ‘4’ occurs twice and the number ‘6’ is missing.
Input format:
The very first line of input contains an integer ‘T’ denoting the number of test cases. 

The first line of every test case contains an integer ‘N’ denoting the number of elements present in the array.

The second line of every test case contains ‘N’ space-separated integers denoting the elements present in the array.
Output format:
For each test case, print the two space-separated integers denoting the repeating and the missing numbers, in the same order.
Note:
You do not need to print anything, it has already been taken care of. Just implement the given function. 
Follow Up:
Can you solve this in O(N) time and O(1) space complexities?
Constraints:
1 <= T <= 100 
2 <= N <= 10^4
1 <= nums[i] <= N

Time Limit: 1 sec
Sample Input 1:
2
5
1 4 2 5 2
2
2 2    
Sample Output 1:
2 3
2 1
Explanation For Sample Input 1:
For the first test case we have, array: [1, 4, 2, 5, 2] and N = 5.

In the given array ‘2’ occurs twice and the number ‘3’ is missing. Hence, we output 2 and 3 for the repeating and the missing number, respectively.

For the second test case we have, array: [2, 2] and N = 2.

In the given array ‘2’ occurs twice and the number ‘1’ is missing. Hence, we output 2 and 1 for the repeating and the missing number, respectively.
Sample Input 2:
3
4
1 2 2 3
10
1 3 4 5 5 6 7 8 9 10
3
1 2 2
Sample Output 2:
2 4 
2 5 
2 3
*/



// look at both the approaches, but definitely this first approach only is the one to be taken, because is very less intuitive and would never come to mind
// Approach 1 : without bit manipulation : since we know that all the elements are within the range [1,n]
// so we can say that every element [1,n] can be connected to some index [0, n-1] present in the array,
// through the relation i = elem - 1  (where i = index assigned by us to any elem)
// so we can try to make the element at each such index negative, and if we find that one such index's elem is already negative,
// means this would have been definitely done by the repeating elem in the array
// and for finding the elem which is not present in the array, just check which elem is not negative after all this operation
vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    vector<int> ans;

    for(int i=0; i<nums.size(); i++){
        int currElem = nums[i];

        // in the equation between indexes and elems (i = elem - 1) , elem should be positive number
        if(currElem < 0) currElem *= -1;

        nums[currElem - 1] *= -1;

        if(nums[currElem - 1] > 0) {   // we found the repeating elem
            ans.push_back(currElem);  

            // but make this elem -ve again , because in future we need to check for the missing elem, by checking which elem remained +ve in the end
            nums[currElem - 1] *= -1;
        }
    }

    for(int i=0; i<nums.size(); i++) {
        if (nums[i] > 0) {
            ans.push_back(i + 1);
            return ans;
        }
    }
}


// APPROACH 2 : using bit manipulation
// In question it is asking us to do this problem in O(n) time and constant space.
// But without bit manipulation this wouldnt be possible, since we would have to maintain a frequency table
// At most, without using freq table, we would be able to find value of a-b (by subtracting sum of n numbers from sum of given numbers)
// But using one equation only , we cant find a and b numerically
// So we use bit manipulation and get a^b.

vector<int> findRepeatingAndMissingNumbers(vector<int> nums)
{
    int N = nums.size();
    int xorOfGivenNums = 0;
    int xorOfFirstNnums = 0;

    for(int i=0; i<N; i++){
        xorOfGivenNums ^= nums[i];
        xorOfFirstNnums ^= (i+1);
    }

    int missingXORrecurring = xorOfGivenNums ^ xorOfFirstNnums;  // we get a^b

    // need to find the first bit from right , at which the 2 numbers differ
    int i=0;
    while((missingXORrecurring & (1<<i)) == 0) i++;

    int xorOfGivenNumsWithIthBitSet = 0;
    int xorOfGivenNumsWithIthBitUnset = 0;
    int xorOfFirstNNumsWithIthBitSet = 0;
    int xorOfFirstNNumsWithIthBitUnset = 0;

    int bitChecker = 1<<i;
    for(int j=0; j<N; j++){
        if((nums[j] & bitChecker) == 0){
            xorOfGivenNumsWithIthBitUnset ^= nums[j];
        }
        else{
            xorOfGivenNumsWithIthBitSet ^= nums[j];
        }

        if(((j+1) & bitChecker) == 0){
            xorOfFirstNNumsWithIthBitUnset ^= (j+1);
        }
        else{
            xorOfFirstNNumsWithIthBitSet ^= (j+1);
        }
    }

    int num1 = xorOfGivenNumsWithIthBitUnset ^ xorOfFirstNNumsWithIthBitUnset;
    int num2 = xorOfGivenNumsWithIthBitSet ^ xorOfFirstNNumsWithIthBitSet;

    int repeatingNum, missingNum;
    for(int j=0; j<N; j++){
        if(nums[j] == num1){
            repeatingNum = num1;
            missingNum = num2;
            break;
        }
        if(nums[j] == num2){
            repeatingNum = num2;
            missingNum = num1;
            break;
        }
    }

    return {repeatingNum, missingNum};
}