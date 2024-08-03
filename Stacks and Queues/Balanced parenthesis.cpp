/*
For a given a string expression containing only round brackets or parentheses, check if they are balanced or not. 
Brackets are said to be balanced if the bracket which opens last, closes first.
Example:
Expression: (()())
Since all the opening brackets have their corresponding closing brackets, we say it is balanced and hence the output will be, 'true'.

Note:
The input expression will not contain spaces in between.
*/

#include <stack>
#include <string>
using namespace std;

bool isBalanced(string expression) 
{
    // Write your code here
    stack<char> s;
    for(int i=0; i<expression.length(); i++){
        if(expression[i] == '('){
            s.push('(');
        }
        else if(expression[i] == ')'){
            if(s.empty()){
                return false;
            }
            else{
                s.pop();
            }
        }
    }
    
    if(s.empty()){
        return true;
    }
}