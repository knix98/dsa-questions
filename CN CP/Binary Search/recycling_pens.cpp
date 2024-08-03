/*
You have 'N' empty pens whose refills have been used up. You have 'R' rupees in your pocket. You have two choices of operations that you can perform each time.
1) Recycle 1 empty pen and get 'K' rupees as a reward.
2) Buy 1 refill for 'C' rupees and combine it with 1 empty pen to make one usable pen.
Your task is to find the maximum number of usable pens that you can get.
For example if you have 'N' = 5 , 'R' = 10 , 'K' = 2 , 'C' = 3. You can recycle one pen and get 2 rupees as a reward so you will have a total of 12 rupees. Now you can buy 4 refills and combine it with 4 pens to make it usable. So your answer is 4.
Input Format :
The first line of the input contains a single integer 'T', denoting the number of test cases. Then the 'T' test case follows.

The first and the only line of each test case consists of 4 non-negative integers 'N', 'R', 'K' and 'C', as described in the problem statement.
Output Format :
For each test case, print a single integer in a new line, denoting the maximum number of usable pens you can get.
Note:
You do not need to print anything. It has already been taken care of. Just implement the given function.
Constraints :
1 <= T <= 10^5
1 <= N <= 10^9
0 <= R <= 10^9
1 <= K <= 10^9
1 <= C <= 10^9

Time limit: 1 sec
Sample Input 1 :
3
10 10 5 5
15 11 3 5
3 20 20 2
Sample Output 1 :
6
7
3
Explanation for Sample input 1 :
In the first test case, you will sell 4 empty pens and you will get 20 rupees so your total money will be 10+20 = 30 and from that, you will buy 6 refills and make 6 usable pens.

In second test case you will sell 8 pens and you will get 8*3=24 rupees and your total money will be 24+11 = 35 and from that, you will buy 7 refills and make 7 usable pens.

In this test case, you have a lot of money to buy but you have only 3 empty pens so you buy 3 refills for 6 rupees and make 3 usable pens.
Sample Input 2 :
3
10 10 1 10
5 0 5 5
6 0 4 2
Sample Output 2 :
1
2
4
Explanation of Sample Input 2 :
In the first test case you can buy 1 refill from the money you have and make 1 usable pen.

In the second test case you can sell 2 empty pens and get 10 rupees and from it, you can buy 2 refills and make 2 usable pens.

In the third test case you can sell 2 empty pens and get 8 rupees and from it, you can buy 4 refills and make 4 usable pens.
*/





#define ll long long

// APPROACH : As we keep on increasing the number of pens that we are recycling for getting money from 0 to n
// we see that we keep on accumulating more money with more money, more pens can be refilled.
// so we just need to find that point or number of pens which when recycled gives us the maximum amount of refilled pens
// so binary search is applicable here

int recyclePens(int n, int r, int k, int c ){
	if(r/c >= n) return n; // if initial money is enough for filling all the pens

	ll ans = 0;  // final ans
	ll i=0, j=n;  // we will binary search over number of pens that we kept (not recycled)

	while (i <= j) {
		ll keepPens = (i + j) / 2;  // pens kept
		ll sellPens = n - keepPens; // pens given for recycle

		ll money = r + (sellPens * k);
		ll filledPens = money / c;  // the maximum amount of pens that we can refill with the total money that we have with us right now
		if (filledPens > keepPens) filledPens = keepPens; 

		ans = filledPens > ans ? filledPens : ans;

		if (filledPens >= keepPens) // means we were able to fill all the keepPens remaining with us, so move right (increasing the number of keep pens)
		i = keepPens + 1;
		else
		j = keepPens - 1; // means we were not able to fill all keepPens, so move left increasing the number of pens recycled for getting more money
	}

    return ans;
}