/*
Angry Children

Bill Gates is on one of his philanthropic journeys to a village in Utopia. He has N packets of candies and would like to distribute one packet to each of the K children in the village (each packet may contain different number of candies). To avoid a fight between the children, he would like to pick K out of N packets such that the unfairness is minimized.
Suppose the K packets have (x1, x2, x3,....xk) candies in them, where xi denotes the number of candies in the ith packet, then we define unfairness as

unfairness=0;
for(i=0;i<n;i++)
    for(j=i;j<n;j++)
        unfairness+=abs(xi-xj)
abs(x) denotes absolute value of x.

Input Format:
First line will contain T(number of test cases), and each test case consists of two lines.
The first line contains two space-separated integers N and K.
The second line will contain N space-separated integers, where Ith integer denotes the candy in the Ith packet.
Output Format:
For each test case print a single integer which will be minimum unfairness in newline.
Constraints
1 <= T <= 10
2<=N<=10^5
2<=K<=N
0<= number of candies in each packet <=10^6

Sample Input
1
7 3
10 100 300 200 1000 20 30
Sample Output
40
Explanation
Bill Gates will choose packets having 10, 20 and 30 candies.So unfairness will be |10-20| + |20-30| + |10-30| = 40. We can verify that it will be minimum in this way.
*/




// Explanation of algo written in CN CP hand notes of DP-1 
#include <bits/stdc++.h>

using namespace std;

#define ll long long

long long int solve(ll arr[], int n, int k)
{
    sort(arr,arr+n);
    vector<long long> prefixSum(n, 0);
    prefixSum[0] = arr[0];
    for(int i=1; i<n; i++) prefixSum[i] = arr[i] + prefixSum[i-1];

    ll curr = 0;  // first window of k size starting from i=0
    for(int i=0;i<k;i++)
    {
        curr += ((prefixSum[k-1] - prefixSum[i]) - (arr[i] * (k-1-i)));
    }
    ll ans = curr;

    // sliding the window 1 element at a time, untill the end
    for(int i=k;i<n;i++)
    {
        ll sumOfCommonElems = prefixSum[i-1] - prefixSum[i-k];
        curr = curr - (sumOfCommonElems - ((k-1) * arr[i-k]));
        curr = curr + (((k-1) * arr[i]) - sumOfCommonElems);
        ans = min(ans,curr);
    }

    return ans;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n,k;
        cin>>n>>k;
        ll arr[n];
        for(int i=0;i<n;i++)
        {
            cin>>arr[i];
        }
        cout<<solve(arr,n,k)<<endl;
    }
}