#include<iostream>
using namespace std;
/*

For a given input string(str), write a function to print all the possible substrings.
Substring
A substring is a contiguous sequence of characters within a string. 
Example: "cod" is a substring of "coding". Whereas, "cdng" is not as the characters taken are not contiguous

*/

void printSubstrings(char input[]) {
	for(int i=0; input[i]!='\0'; i++){
        for(int j=i; input[j]!='\0'; j++){
            for(int k=i; k<=j; k++){
                cout<<input[k];
            }
            cout << endl;
        }
    }
}