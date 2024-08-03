/*

Given a string S (that can contain multiple words), you need to find the word which has minimum length.
Note : If multiple words are of same length, then answer will be first minimum length word in the string.
Words are seperated by single space only.

Constraints :
1 <= Length of String S <= 10^5

Sample Input 1 :
this is test string
Sample Output 1 :
is

*/


/* input - Input String
*  output - Save the result in the output array (passed as argument). You don’t have to 
*  print or return the result
*/
#include<climits>
#include<cstring>
void minLengthWord(char a[], char output[]){
		
	int mws, ml = INT_MAX; //mws = minm word start(i.e starting index of shortest word), ml = length of shortest word
	
    for(int i=0; i<strlen(a); i++){
        if(a[i] != ' '){
            int ws=i, we=i; //we = word end index, ws = word start index
            while(a[we] != ' ' && a[we] != '\0'){
                we++;
            }
            
            if(we-ws < ml){
                mws = ws;
                ml = we-ws;
            }
            
            i = we;
        }
    }
    
    for(int i=0; i<ml; i++){
        output[i] = a[mws];
        mws++;
    }
    
    output[ml] = '\0';
}