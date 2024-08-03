/*

A child is running up a staircase with N steps, and can hop either 1 step, 2 steps or 3 steps at a time. 
Implement a method to count how many possible ways the child can run up to the stairs. 
You need to return number of possible ways W.

*/

int staircase(int n){
    if(n==0){ //base cases: do dry run and u will find out the reason
        return 1;
    }
    else if(n<0){
        return 0;
    }
    
    int x1 = staircase(n-1);
    int x2 = staircase(n-2);
    int x3 = staircase(n-3);
    
    return x1+x2+x3;
}


//A more understandable soln written below, in which u manually figure out 
//number of ways for n=1,2,3 and call recursions for n>3;

/*
int staircase(int n){
	if(n==1){
        return 1;
    }    
    if(n==2){
        return 2;
    }
    if(n==3){
        return 4;
    }
    if(n>3){
        int x = staircase(n-1);
        int y = staircase(n-2);
        int z = staircase(n-3);
        return x+y+z;
    }
*/