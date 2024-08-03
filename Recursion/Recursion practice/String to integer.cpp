/*

Write a recursive function to convert a given string into the number it represents. 
That is input will be a numeric string that contains only numbers, 
you need to convert the string into corresponding integer and return the answer.

Input format :
Numeric string S (string, Eg. "1234")
Output format :
Corresponding integer N (int, Eg. 1234)

Constraints :
0 < |S| <= 9
where |S| represents length of string S.

*/

#include<cstring>
int stringToNumber(char input[]) {
    // Write your code here
	if(input[0] == '\0'){
        return 0;
    }
    
    int lastDigit = input[strlen(input)-1] - '0'; //save the last char as (int)(last digit)
    input[strlen(input)-1] = '\0'; //end the string by removing the last char
    
    int smallAns = stringToNumber(input); //recursion on the reduced string
    
    return lastDigit + (smallAns*10);
}
