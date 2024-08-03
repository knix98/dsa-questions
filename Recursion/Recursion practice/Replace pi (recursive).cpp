/*

Given a string, compute recursively a new string where all appearances of "pi" have been replaced by "3.14".

Constraints :
1 <= |S| <= 50
where |S| represents the length of string S. 

Sample Input 1 :
xpix
Sample Output :
x3.14x

*/

// Change in the given string itself. So no need to return or print anything

void shift(char *a){
    int i=0;
    for(; a[i]!='\0'; i++){
    }
    for(int j=i; j>=0; j--){
        a[j+2]=a[j];
    }
}

void replacePi(char input[]) {
	// Write your code here
    
    if(input[1]=='\0'){ //base case
        return;
    }
    
    replacePi(input+1); //recursive call
    
    if(input[0]=='p' && input[1]=='i'){ //small calculation part
        shift(input+2);
        input[0]='3';
        input[1]='.';
        input[2]='1';
        input[3]='4';
        return;
    }
    else{
        return;
    }
}