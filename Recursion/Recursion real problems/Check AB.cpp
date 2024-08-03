/*

Suppose you have a string, S, made up of only 'a's and 'b's. Write a recursive function that checks if the 
string was generated using the following rules:
a. The string begins with an 'a'
b. Each 'a' is followed by nothing or an 'a' or "bb"
c. Each "bb" is followed by nothing or an 'a'
If all the rules are followed by the given string, return true otherwise return false.
Input format :

*/

bool checkAB(char input[]) {
	if(input[0]=='\0'){ //base case
        return true;
    }
    
    if(input[0]!='a'){ //every recursion call should check this condition first, because every call is made after 'bb' 
        return false;  //is encountered or after-if 'bb' is not encountered.....so after 'bb' or after 'a' if 'bb' is not there... 
    }                  //an 'a' should be there
    
    if(input[1]=='b' && input[2]=='b'){
		return checkAB(input+3);        
    }
    else{
        return checkAB(input+1); //if 'bb' is not encountered then call recusion on next element which would
    }								//again start by checking 'a' since 'bb' was not encountered after 'a' in
    								//the previous recursion call
}