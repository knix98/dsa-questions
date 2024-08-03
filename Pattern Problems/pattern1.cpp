/*

Sample Input :
   5


Sample Output :

1234554321
1234**4321
123****321
12******21
1********1

*/

#include<iostream>
using namespace std;


int main(){

	int n;
    cin >> n;
    
    for(int i=1;i<=n;i++){
        int j=1;
        for(;j<=n-i+1;j++){
            cout << j;
        }
        
        for(int st=1;st<=2*(i-1);st++){
            cout << "*";
        }
        
        j=n-i+1;
        for(;j>=1;j--){
            cout << j;
        }
        cout << endl;
    }

}