/*
For a given expression in the form of a string, find the minimum number of brackets that can be reversed in order to make the expression balanced. 
The expression will only contain curly brackets.
If the expression can't be balanced, return -1.
Example:
Expression: {{{{
If we reverse the second and the fourth opening brackets, the whole expression will get balanced. 
Since we have to reverse two brackets to make the expression balanced, the expected output will be 2.

Expression: {{{
In this example, even if we reverse the last opening bracket, we would be left with the first opening bracket 
and hence will not be able to make the expression balanced and the output will be -1.

Sample Input 2:
{{{{}}
Sample Output 2:
1
*/

#include<stack>
#include<string>
using namespace std;

int countBracketReversals(string input) {
    if(input.length() % 2 != 0){ // if odd number of total brackets, then no balancing possible  
        return -1;
    }
    
    int left = 0; //counting the number of '}' left unbalanced after all the already balanced '{}' pairs cancelled out 
    stack<char> s;
    for(int i=0; i<input.length(); i++){
        if(input[i] == '{'){
            s.push(input[i]);
        }
        else{
            if(s.empty()){ //means no '{' present to balance the '}' encountered, so left++
                left++;
            }
            else{ //means a '{}' pair encountered
                s.pop();
            }
        }
    }
    
    /*
        Now 'left' contains the number of '}' remaining unbalanced, stack s contains the number of '{' remaining unbalanced.
        Total '}' + total '{' == even number
    */
    int ans = (left/2) + (s.size() / 2) + (left%2) + (s.size() % 2);
    return ans;
}