/*  

Given k, find the geometric sum i.e.
1 + 1/2 + 1/4 + 1/8 + ... + 1/(2^k) 
using recursion.

Constraints :
0 <= k <= 1000

Sample Input 1 :
3
Sample Output 1 :
1.87500

*/

double geometricSum(int k) {
    // Write your code here
	if(k==0){
        return 1;
    }
    
    double ans=1;
    for(int i=1; i<=k; i++){
        ans=ans*2;
    }
    ans=1/ans;
    
    return ans +geometricSum(k-1);
}
