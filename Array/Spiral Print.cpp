#include<iostream>
using namespace std;
/*

For a given two-dimensional integer array/list of size (N x M), print it in a spiral form. 
That is, you need to print in the order followed for every iteration:
a. First row(left to right)
b. Last column(top to bottom)
c. Last row(right to left)
d. First column(bottom to top)
Mind that every element will be printed only once.

Input:
1  2  3  4 
5  6  7  8
9 10 11 12

Output:
1 2 3 4 8 12 11 10 9 5 6 7

*/

void spiralPrint(int **a, int n, int m)
{
    int r=m-1, b=n-1, l=0, t=1; //right, bottom, left, top limits(till where to print)
    int i=0, j=0; //initial starting point (a[0][0] should be printed first)
    
    while(1){
        if(j > r){ //make a diagram on paper and u will be able to figure out these conditions logic
            return;
        }
        else{
            for( ; j<=r; j++){
                cout << a[i][j] << " ";
            }
            r--; //update right limit for the future round
            i++; //update i to go the next element, which would be printed first in the bottom round of printing
            j--; //j would have gone over the right limit in the for loop, so just bringing it back
        }
        
        if(i > b){
            return;
        }
        else{
            for( ; i<=b; i++){
                cout << a[i][j] << " ";
            }
            b--; j--; i--;
        }
        
        if(j < l){
            return;
        }
        else{
            for( ; j>=l; j--){
                cout << a[i][j] << " ";
            }
            l++; i--; j++;
        }
        
        if(i < t){
            return;
        }
        else{
            for( ; i>=t; i--){
                cout << a[i][j] << " ";
            }
            t++; j++; i++;
        }
    }
}