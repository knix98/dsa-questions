/*  

Write a program to do basic string compression. For a character which is consecutively repeated more than once, 
replace consecutive duplicate occurrences with the count of repetitions.

Example:
If a string has 'x' repeated 5 times, replace this "xxxxx" with "x5".

The string is compressed only when the repeated character count is more than 1.
Note: Consecutive count of every character in the input string is less than or equal to 9.

Constraints:
0 <= N <= 10^6

Where 'N' is the length of the input string.

Time Limit: 1 sec

Sample Input 1:
aaabbccdsa
Sample Output 1:
a3b2c2dsa

*/

#include <iostream>
#include <cstring>
#include<string>
using namespace std;

void getCompressedString(char *input) {
    int filler = 0, st = 0; //filler wud fill the solution values starting from index 0, st = starting index of any consecutive chars
    while(input[st] != '\0'){
        int i = st + 1; //i=iterator for checking the length of consecutive chars
        while(input[i] != '\0' && input[i] == input[i-1]){
            i++;
        }
        
        if(i - st > 1){
            input[filler] = input[st];
            input[++filler] = i - st + 48;
        }
        else{
            input[filler] = input[st];
        }
        
        filler++;
        st = i;
    }
    
    input[filler] = '\0';
}

int main() {
    int size = 1e6;
    char str[size];
    cin >> str;
    getCompressedString(str);
    cout << str << endl;
}