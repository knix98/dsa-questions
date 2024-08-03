/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204218/offering/2650138/problem/13917?leftPanelTabValue=PROBLEM

You are given a string 'S'. Your task is to convert it to a "NEIGHBOUR _FREE" string.

String is "NEIGHBOUR _FREE" it does not contain two adjacent same characters.

For Example:

"abbc" in this string "bb" are adjacent but after rearrangement we get "abcb". It doesn't contain any adjacent character which is the same so it's a "NEIGHBOUR \_FREE" string.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10    
0 <= |S| <= 10^5 

Time Limit: 1 sec
Sample Input 1 :
2 
abbc
coding
Sample Output 1 :
Yes
Yes
Explanation :
For the first test case, refer example explaination.

For the second test case, the given string is “coding”. This string does not have two adjacent characters that are the same. So if we return “coding", then we will get an output as “Yes”.
Sample Input 2 :
1
bbbbbb
Sample Output 2 :
Yes
Explanation :
For the first test case, the given string is “bbbbbb”. No matter how you rearrange the characters of the string, it will always remain the same as "bbbbbb". So we return “not possible” as an answer, then we will get an output as ‘Yes”.
*/



string reArrangeString(string &s) {
  int n = s.size();

  // Store frequency of characters in hash array.
  vector<int> hash(26, 0);
  for (char character : s) {
    hash[character - 'a']++;
  }

  // Calculate most frequent character in string.
  char mostFrequentCharacter;
  int maxFrequency = 0;
  for (int character = 0; character < 26; character++) {
    if (hash[character] > maxFrequency) {
      mostFrequentCharacter = 'a' + character;
      maxFrequency = hash[character];
    }
  }

  // If max frequency element > (n+1)/2 then return not possible.
  string notValid = "not possible";
  if (maxFrequency > (n + 1) / 2) {
    return notValid;
  }

  // Assign max frequency element to all even positions.
  string answer = s;
  int currentIndex = 0;
  while (maxFrequency > 0) {
    answer[currentIndex] = mostFrequentCharacter;
    currentIndex += 2;
    maxFrequency--;
  }
  hash[mostFrequentCharacter - 'a'] = 0;

  // Assign remaining characters to even positions and if all even positions are
  // filled then use odd positions.
  for (int character = 0; character < 26; character++) {

    while (hash[character] > 0) {
      // If even positions are filled then set current index to 1 and start
      // filling odd positions.
      if (currentIndex >= n) {
        currentIndex = 1;
      }

      hash[character]--;

      answer[currentIndex] = 'a' + character;
      currentIndex += 2;
    }
  }
  return answer;
}