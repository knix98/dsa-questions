/*

For a given two strings, 'str1' and 'str2', check whether they are a permutation of each other or not.

Permutations of each other
Two strings are said to be a permutation of each other when either of the string's characters can be rearranged so that it 
becomes identical to the other one.

Example:
str1= "sinrtg"
str2 = "string"

The character of the first string(str1) can be rearranged to form str2 and hence we can say that the given strings are
a permutation of each other.

Note:
All the characters in the input strings would be in lower case.

*/

bool isPermutation(char input1[], char input2[]) {
    
	int check[26]={0};
    for(int i=0; input1[i]!='\0'; i++){
        check[input1[i]-'a']++;
    }
    
    for(int i=0; input2[i]!='\0'; i++){
        check[input2[i]-'a']--;
    }
    
    for(int i=0; i<26; i++){
    	if(check[i]!=0){
            return false;
        }
    }
    
    return true;
}