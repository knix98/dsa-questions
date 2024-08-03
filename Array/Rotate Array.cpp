/*

You have been given a random integer array/list(ARR) of size N. 
Write a function that rotates the given array/list by D elements(towards the left).

Sample Input 1:
1 2 3 4 5 6 7
2
Sample Output 1:
3 4 5 6 7 1 2

*/


void rotate(int *a, int d, int n)
{
    //first rotate the whole array, by swapping each element with its corresponding opposite element
    for(int i=0,j=n-1; i<j; i++,j--){
        a[i] ^= a[j] ^= a[i] ^= a[j];
    }
    
    //then rotate the array from i=0 to j=n-d-1
    for(int i=0,j=n-1-d; i<j; i++,j--){
        a[i] ^= a[j] ^= a[i] ^= a[j];
    }
    
    //then rotate the remaining arr from i=n-d to j=n-1
    for(int i=n-d,j=n-1; i<j; i++,j--){
        a[i] ^= a[j] ^= a[i] ^= a[j];
    }
}