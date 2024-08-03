/*

For a given a string(str), find and return the highest occurring character.

Example:
Input String: "abcdeapapqarr"
Expected Output: 'a'
Since 'a' has appeared four times in the string which happens to be the highest frequency character, the answer would be 'a'.
If there are two characters in the input string with the same frequency, return the character which comes first in the input string.

Consider:
Assume all the characters in the given string to be in lowercase always.

Sample Input 1:
abdefgbabfba
Sample Output 1:
b

Sample Input 2:
xy
Sample Output 2:
x

*/

char highestOccurringChar(char input[]) {
    int freq[26] = {0}; //frequency table
    
    for(int i=0; input[i] != '\0'; i++){ //update freq table
        freq[input[i] - 'a']++;
    }
    
    int maxFreq = 0; 
    char maxChar;
    for(int i=0; input[i] != '\0'; i++){ //whichever char has maxm freq and comes first in the input arr, will automatically be saved in maxChar
        if(freq[input[i] - 'a'] > maxFreq){
            maxFreq = freq[input[i] - 'a'];
            maxChar = input[i];
        }
    }
    
    return maxChar;
}