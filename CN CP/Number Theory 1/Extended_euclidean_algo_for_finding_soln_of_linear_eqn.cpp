/*
Find integer solution (if exists) of ax + by = c.  
You will be given a,b,c as inputs
*/

// explanation and mathematical proofs are all written in CN CP hand notes
#include <iostream>
using namespace std;

// this func would take a and b as input args, and reference variables x,y 
// this func would first get gcd(a,b) thru recursion (lets say g = gcd(a,b))
// and then calculate solution of eqn => ax + by = g , and store the solution in ref variables (x,y)
// and then simply return g
int extendedGCD(int a,int b, int& x, int& y){
    if(b==0){ // base case when b = 0, then we know g = a, and (x,y) = (1,0)
        x=1;
        y=0;
        return a;
    }

    int x1,y1; // for storing solution of next eqn , i.e bx + (a%b)y = g
    int g=extendedGCD(b,a%b,x1,y1);
    x=y1;
    y=x1-(a/b)*y1;
    return g;
}

int main(){
    int a,b,c,g,x,y;
    cin>>a>>b>>c;

    g=extendedGCD(a,b,x,y);

    if(c%g ==0) cout <<" x = "<< x*(c/g) << " y = " << y*(c/g);      // if c is divisible by g, then only integer soln can exist
    else        cout<<"Integer solution of this LDE does not exists";
}