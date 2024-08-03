/*
Assume that the value of a = 1, b = 2, c = 3, ... , z = 26. You are given a numeric string S. 
Write a program to return the list of all possible codes that can be generated from the given string.
Note : The order of codes are not important. And input string does not contain 0s.

Constraints :
1 <= Length of String S <= 10

Sample Input:
1123
Sample Output:
aabc
kbc
alc
aaw
kw
*/

// 1. Return codes
// NEW LEARNING THING: how chars are converted to their corresponding code
#include<iostream>
#include<cstring>
using namespace std;

int getCodes(string input, string output[10000], int opstart) {
    
    //BASE CASE: initiate a solution in the output arr, when reached the end of input arr
    //Reaching the end of input arr means we have accumulated a possible code
    if(input.empty()){
        output[opstart] = "";
        return 1;
    }
    
    int size1 = getCodes(input.substr(1), output, opstart);
    
    //IMP: look at how the char from input[0] is converted to it's corresponding code
    char ch1 = (char)(input[0] - '0' + 96);
    for(int i=opstart; i < opstart+size1; i++){
        output[i] = ch1 + output[i];
    }
    
    int size2 = 0;
    if(input.size() >= 2){
        int digit = (input[0] - '0')*10 + (input[1] - '0'); //
        if(digit <= 26){
            char ch2 = (char)(digit + 96);
            size2 = getCodes(input.substr(2), output, opstart+size1);
            for(int i=opstart+size1; i < opstart+size1+size2; i++){
                output[i] = ch2 + output[i];
            }
        }
    }
    
    return size1+size2;
}

int getCodes(string input, string output[10000]){
    return getCodes(input, output, 0);
}


// 2. Print Codes
void printer(string input, string print){
    //BASE CASE: when reach the end of input string, that means a possible code has been accumulated in print
    if(input.empty()){
        cout << print << endl;
        return;
    }
    
    char code1 = input[0] - '0' + 96;
    printer(input.substr(1), print+code1);
    
    if(input.size() >= 2){
        int digit = (input[0] - '0')*10 + (input[1] - '0');
        if(digit <= 26){
            char code2 = (char)(digit + 96);
            printer(input.substr(2), print+code2);
        }
    }
}

void printAllPossibleCodes(string input) {
    printer(input, "");
}