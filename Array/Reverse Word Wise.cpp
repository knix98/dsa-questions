/*

Reverse the given string word wise. That is, the last word in given string should come at 1st place, 
last second word at 2nd place and so on. Individual words should remain as it is.

Constraints :
0 <= |S| <= 10^7
where |S| represents the length of string, S.

Sample Input 1:
Welcome to Coding Ninjas
Sample Output 1:
Ninjas Coding to Welcome

*/

void reverseArr(char a[], int st, int end){
    while(st<end){
        char temp = a[st];
        a[st] = a[end];
        a[end] = temp;
        st++;
        end--;
    }
}

//better and clean code with less number of loops visible
void reverseStringWordWise(char a[]){
    int previousSpace = -1;
    
    int i=0;
    for( ; a[i] != '\0'; i++){ //first reverse every word at their places itself
        if(a[i] == ' '){
            reverseArr(a, previousSpace+1, i-1);
            previousSpace = i;
        }
    }
    
    reverseArr(a, previousSpace+1, i-1); //the last word would not be reversed by the loop above, so reverse it here
    reverseArr(a, 0, i-1); //in the end reverse the whole array
}

//code written by me in 1st attempt, same O(n) time complexity, but not clean code with more number of loops
/*
void reverseStringWordWise(char a[]){
    int j=0;
    for( ; a[j] != '\0'; j++){
        
    }
    
    reverseArr(a, 0, --j); //reverse the whole arr first
    
    int k=0; //k=index where a word starts
    while(k <= j){
        int i=k; //i=index where word ends by a space 
        while(a[i] != ' ' && i<=j){
            i++;
        }
        
        reverseArr(a, k, i-1);
        
        while(a[i] == ' ' && i<=j){ //finding the start of the next word
            i++;
        }
        
        k=i; //assigning the index of start of the next word to k
    }
}
*/