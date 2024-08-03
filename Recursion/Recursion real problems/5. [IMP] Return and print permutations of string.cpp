/*
Given a string S, find and return all the possible permutations of the input string.
Note 1 : The order of permutations is not important.
Note 2 : If original string contains duplicate characters, permutations will also be duplicates.

Sample Input :
abc
Sample Output :
abc
acb
bac
bca
cab
cba
*/

// 1. Return all permutations
#include <string>
using namespace std;

//string input has been passed by reference becoz, every time a new input string is created and stored in
//a var newInput(look below in code) and passed to recursion, so no need to create another storage for this
//newInput
int helper(string &input, string *output, int opstart){
    //BASE CASE: initiate a solution on reaching the end of input string
    if(input.empty()){
        output[opstart] = "";
        return 1;
    }
    
    int opstart1 = opstart; //preserve opstart because opstart1 would be updated
    for(int i=0; i<input.size(); i++){
        string newInput = input.substr(0,i) + input.substr(i+1);
        
        int size = helper(newInput, output, opstart1);
        
        for(int j=opstart1; j<opstart1+size; j++){
            output[j] = input[i] + output[j];
        }
        
        opstart1 = opstart1 + size;
    }
    
    return opstart1 - opstart;
}

int returnPermutations(string input, string output[]){
   	helper(input, output, 0);
}



// 2. Print all permutations
#include <iostream>
#include <string>
using namespace std;

void printer(string &input, string print){
    if(input.empty()){
        cout << print << endl;
        return;
    }
    
    for(int i=0; i<input.size(); i++){
        string newInput = input.substr(0,i) + input.substr(i+1);
        printer(newInput, print + input[i]);
    }
}

void printPermutations(string input){
	printer(input, "");
}