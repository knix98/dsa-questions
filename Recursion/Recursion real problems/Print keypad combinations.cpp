/*

Given an integer n, using phone keypad find out and print all the possible strings that can be made using digits of input n.
Note : The order of strings are not important. Just print different strings in new lines.

Constraints :
1 <= n <= 10^6

Sample Input:
23
Sample Output:
ad
ae
af
bd
be
bf
cd
ce
cf

*/

#include <iostream>
#include <string>
using namespace std;

void printKeypad(int num, string print, string options[]){
    if(num <= 1){
        cout << print << endl;
        return;
    }
    
    int lastDigit = num%10;
    for(int i=0; i<options[lastDigit].size(); i++){ //attaching the appropriate option of lastDigit to the print string and sending for recursion
        printKeypad(num/10, options[lastDigit][i] + print, options); 
    }
}

void printKeypad(int num){
    string options[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
    printKeypad(num, "", options);
}