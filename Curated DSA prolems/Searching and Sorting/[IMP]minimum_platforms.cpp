/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204217/offering/2650137/problem/13833?leftPanelTabValue=SUBMISSION

You are given the arrival and departure times of all trains which arrive and depart from a particular railway station in the form of 2 arrays 'AT' and 'DT'. Find the minimum number of platforms required such that there is no delay i.e there is no train that needs to wait to arrive at the station.

Note :
1. Every train will depart on the same day and the departure time will always be greater than the arrival time. For example, A train with arrival time 2240 and departure time 1930 is not possible.
2. Time will be given in 24H format and colons will be omitted for convenience. For example, 9:05AM will be given as "905", or 9:10PM will be given as "2110".
3. Also, there will be no leading zeroes in the given times. For example, 12:10AM will be given as “10” and not as “0010”.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 50000
0 <= AT[i] <= DT[i] <= 2359

Where 'AT[i]' and 'DT[i]' are the elements of the arrival and the departure arrays respectively.

Time limit: 1 sec
Sample Input 1:
1
3
900 910 940
920 950 1000

4
100 200 300 400
200 300 400 500
Sample Output 1:
3
1
Explanation of the Sample Output 1:
In test case 1, For the given input, the following will be the schedule of the trains:

We need 2 platforms for #1 and #2 trains. #3 train can use same platform as #1 train, since #1 train will depart by the time the third train arrives.

Thus, minimum 3 platforms are needed for the given input.

In test case 2, For the given input, the following will be the schedule of the trains:

Train 1 arrived at 100 on platform 1. 
Train 1 departed at 200 from platform 1. 
Train 2 arrived at 200 on platform 1.
Train 2 departed at 300 on platform 1.
Train 3 arrived at 300 on platform 1.
Train 3 departed at 400 on platform 1.
Train 4 arrived at 400 on platform 1.
Train 4 departed at 500 on platform 1. 

Thus, only 1 platform is needed for the given input.
Sample Input 2:
2
2
900 1000
999 1100
3
1200 1300 1450
1310 1440 1600    
Sample Output 2:
1
2
Explanation of the Sample Output 2:
In test case 1, For the given input, the following will be the schedule of the trains:

Train 1 arrived at 900 on platform 1. 
Train 1 departed at 999 from platform 1. 
Train 2 arrived at 1000 on platform 1.
Train 2 arrived at 1100 on platform 1.

Thus, only 1 platform is needed for the given input.

In test case 2, For the given input, the following will be the schedule of the trains:

Train 1 arrived at 1200 on platform 1. 
Train 2 arrived at 1300 on platform 2. (since platform 1 was already occupied by train 1). 
Train 1 departed at 1310 from platform 1.
Train 2 departed at 1440 from platform 2.
Train 3 arrived at 1450 on platform 1.
Train 3 departed at 1600 on platform 1.

Thus, minimum 2 platforms are needed for the given input.

*/


// METHOD 1 : time : O(n), space : O(1)
#include<vector>

int calculateMinPatforms(int at[], int dt[], int n) {
    vector<pair<int,int>> a(2360, {0,0});  // indices indicate times from 0 to 2359
    // and at each time we will store how many trains arrived in first and departed in second

    for(int i=0; i<n; i++){
        a[at[i]].first++;
        a[dt[i]].second++;
    }

    int maxTrains = 0;
    int trains = 0;
    for(int i=0; i<2360; i++) {
        trains += a[i].first;
        if(maxTrains < trains) maxTrains = trains;
        trains -= a[i].second;
    }

    return maxTrains;
}


// METHOD 2 : time : O(nlogn), space : O(1)
#include<algorithm>

int calculateMinPatforms(int at[], int dt[], int n) {
    sort(at, at+n);
    sort(dt, dt+n);

    int ai = 0, di = 0;
    int maxTrains = 0;
    int trains = 0;
    while(ai < n){   // we will only count trains till trains are arriving, since after that trains would only leave
                     // and we need to count maxtrains at any point of time
        if(at[ai] <= dt[di]){
            trains++;
            if(trains > maxTrains) maxTrains = trains;
            ai++;
        }
        else{
            trains--;
            di++;
        }
    }

    return maxTrains;
}