/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575393/offering/8882365/problem/7575?leftPanelTabValue=PROBLEM

You are given string S of length N, and an integer K. Your task is to find the length of the longest substring that contains at most K distinct characters.

Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= K <= 26
1 <= N <= 10^4

Time Limit: 1sec
Sample Input 1:
2
2
abcba
1
abccc
Sample Output 1:
3
3
Explanation of the Sample Input1:
Test Case 1:
K = 2 in the first test case so we can choose substring ‘bcb’ having 2 distinct characters which are less than equal to K=2. 
We cannot get any other substring of length 4 or greater having distinct characters less than equal to 2.
Test Case 2:
K = 1 in the second test case so we can choose substring ‘ccc’ having only 1 distinct character which is less than equal to K=1. 
We cannot get any other substring of length 4 or greater having distinct characters less than equal to 1.
*/



// Method 1 : latest approach : applying sliding-window or 2-pointer techniques is more easier by this method :
// calculating a valid index range ending at each j of the array/string
int getLengthofLongestSubstring(int k, string s)
{
   unordered_map<char, int> fq;  // you can also use a normal char frequency table of size 26 vector
   int distinct_chars = 0;
   
   int i=0, j=0;
   int ans = 0;

   // we will calculate longest valid substr length possible at every j
   while(j < s.size()){
      fq[s[j]]++;      
      if(fq[s[j]] == 1) distinct_chars++;

      while(distinct_chars > k) {
         fq[s[i]]--;
         if(fq[s[i]] == 0) distinct_chars--;
         i++;
      }

      if(j-i+1 > ans) ans = j-i+1;  // comparing longest valid substr at this j with global ans

      j++;
   }

   return ans;
}



// Method 2
int getLengthofLongestSubstring(int k, string s)
{
   vector<int> fq(26, 0);

    int count = 0; // will keep the count of distinct chars in the current window
    int ans = 0;

    int i=0, j=0; // i == window starting, j = end window
    while(j < s.size()){
        fq[s[j] - 'a']++;
        if(fq[s[j] - 'a'] == 1) count++; // means a new character has been found for the current window

        while(count > k){  // shorten the window from beginning if count of distinct chars is >k
            fq[s[i] - 'a']--;
            if(fq[s[i] - 'a'] == 0) count--; // decrease the count , if freq of a char reaches zero in the current window
            i++;
        }

        if(count <= k) {
            if(j-i+1 > ans) ans = j-i+1; // check whether the current window size is the largest window size
        }

        j++;
    }

    return ans;
}