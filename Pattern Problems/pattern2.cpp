/*

Sample Input :
5
Sample Output :
    1
   212
  32123
 4321234
543212345

*/

#include<iostream>
using namespace std;

int main(){

	int n;
    cin >> n;

  	for(int i=1;i<=n;i++){
        for(int sp=1;sp<=n-i;sp++){
            cout << " ";
        }
        
        int j = i;
        for( ;j>=1 ;j-- ){
            cout << j;
        }
        
        j=2;
        for(;j<=i;j++){
            cout << j;
        }
        
        cout << endl;
    }
}