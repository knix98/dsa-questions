/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575414/offering/8882758/problem/7284
*/


// explanation written in CN CP notes => combinatorics 2
#define ll long long

long countWays(int n)
{
    ll ans = ((ll)(n-1) * (n-2)) / 2;  // n-1Cr-1 ... r==3

    int u = (n-1)/2; // this is important => since atleast 1 to be given to third person, so we left with n-1 items
    int l = n/3;

    ans -= ((u-l) * 3);

    if((n % 3) == 0) ans--;

    return (long)(ans);
}