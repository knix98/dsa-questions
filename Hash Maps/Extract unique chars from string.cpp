/*
Given a string S, you need to remove all the duplicates.
That means, the output string should contain each character only once.
The respective order of characters should remain same, as in the input string.

Sample Input 1 :
ababacd
Sample Output 1 :
abcd
Sample Input 2 :
abcde
Sample Output 2 :
abcde
*/

#include <unordered_map>
#include <string>
using namespace std;
string uniqueChar(string str)
{
    // Write your code here
    string ans = "";
    unordered_map<char, int> uniqueChars;
    for (int i = 0; i < str.length(); i++)
    {
        if (uniqueChars.count(str[i]) == 0)
        {
            uniqueChars[str[i]] = 1;
            ans += str[i];
        }
    }

    return ans;
}