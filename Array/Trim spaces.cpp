/*

Given an input string S that contains multiple words, you need to remove all the spaces present in the input string.
There can be multiple spaces present after any word.

Constraints :
1 <= Length of string S <= 10^6

Sample Input :
abc def g hi
Sample Output :
abcdefghi

*/

void trimSpaces(char a[]) {
    int c=0, i=0; //c=index where next char should be placed, i=iterator over the whole array
    
    for( ; a[i] != '\0'; i++){
        if(a[i] != ' '){
            a[c] = a[i]; //whenever iterator encounters a non-space char, send this char to the a[c] where the next char should be placed
            c++;
        }
    }
    
    a[c] = '\0'; //in the end eliminate the string
}