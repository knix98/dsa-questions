/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204439/offering/2653310/problem/14212?leftPanelTabValue=PROBLEM
*/



#include<set>

void replaceele(int* arr,int n)
{
    set<int> s;
    s.insert(arr[n-1]);
    arr[n-1] = -1;

    int currAns;
    for(int i=n-2; i>=0; i--){
        auto it = s.upper_bound(arr[i]);

        if(it == s.end()) currAns = -1;
        else currAns = *it;

        s.insert(arr[i]);
        arr[i] = currAns;
    }
}