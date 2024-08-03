/*
Afzal has been working with an organization called 'Money Traders' for the past few years. The organization is into the money 
trading business. His manager assigned him a task. For a given array/list of stock's prices for N days, 
find the stock's span for each day.
The span of the stock's price today is defined as the maximum number of consecutive days(starting from today and going backwards) 
for which the price of the stock was less than today's price.
For example, if the price of a stock over a period of 7 days are [100, 80, 60, 70, 60, 75, 85], 
then the stock spans will be [1, 1, 1, 2, 1, 4, 6].
Explanation:
On the sixth day when the price of the stock was 75, the span came out to be 4, 
because the last 4 prices(including the current price of 75) were less than the current or the sixth day's price.

Similarly, we can deduce the remaining results.
Afzal has to return an array/list of spans corresponding to each day's stock's price. Help him to achieve the task.

Sample Input 1:
10 10 10 10
Sample Output 1:
1 1 1 1 

Sample Input 2:
60 70 80 100 90 75 80 120
Sample Output 2:
1 2 3 4 1 1 2 8 
*/

#include<stack>
#include<iostream>
using namespace std; 


//explanation about the solution written in the 'first time notes'
int* stockSpan(int *price, int size)  {
	if(size == 0){
        return NULL;
    }
    
    int *span = new int[size];
    stack<int> s; //this stack would contain the indices of the prices which are the local price peaks
    span[0] = 1;
    s.push(0);
    
    for(int i=1; i<size; i++){
        span[i] = 1;
        while(!s.empty() && price[i] > price[s.top()]){
            span[i] += span[s.top()]; //add the span of the smaller price to the span of the bigger price
            s.pop(); //pop the smaller price, since it's no longer a peak
        }
        
        s.push(i); //finally, always push the recent price's index into the stack, because the next price wud first need to be compared with the preceding price 
    }
    
    return span;
}