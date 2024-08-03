/*
For a given expression in the form of a string, find if there exist any redundant brackets or not. 
It is given that the expression contains only rounded brackets or parenthesis and the input expression will always be balanced.
A pair of the bracket is said to be redundant when a sub-expression is surrounded by unnecessary or needless brackets.
Example:
Expression: (a+b)+c
Since there are no needless brackets, hence, the output must be 'false'.

Expression: ((a+b))
The expression can be reduced to (a+b). Hence the expression has redundant brackets and the output will be 'true'.

Sample Input 1:
a+(b)+c 
Sample Output 1:
true

Sample Input 2:
(a+b)
Sample Output 2:
false
*/


//Solution: Input expression is balanced means --> situation like (b+) would not be encountered since expression inside each bracket is balanced in itself
//Only take care of situations like (), (a)
//(a+b)+c doesn't have any redundant brackets, similarly (a+b)


#include<stack>
#include<string>
using namespace std;

bool checkRedundantBrackets(string expression) {
	// Write your code here
    stack<char> s;
    for(int i=0; i<expression.length(); i++){
        if(expression[i] != ')'){ //keep pushing all the chars in the stack until ')' is encountered
            s.push(expression[i]);
        }
        else{
            int count =0; //when ')' is encountered then check by popping the stack that whether there are more than 1 chars before we
            for( ; s.top()!='('; ){ //encounter 1st '(' in the stack
                s.pop();
                if(s.empty()){
                    return true;
                }
                count++;
            }
            if(count<=1){
                return true;
            }
            else{
                s.pop();
                continue;
            }
        }
    }
    
    return false;
}