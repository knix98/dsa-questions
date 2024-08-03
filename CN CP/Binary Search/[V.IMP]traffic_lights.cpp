/*
There is a street of length ‘X’ with 'X' slots numbered from 0 to 'X' (0,1,…, ’X’). Initially, there are no traffic lights in these slots. Later ‘N’ sets of traffic lights are added to the street one after another. The ‘POS’ array tells the position of the ‘i’th light.
Your task is to calculate the length of the longest passage without traffic lights after each addition.
For example:
Given:- ‘X’ = 5 and ‘N’ = 2.
‘POS’[] = 3, 4
The output will be 3 and 3.
Initially, there are no lights, and we install a light at position three; therefore, there is a segment between the 3 and 6. 
Then we install a light at position four; therefore, the largest gap becomes between 0 to 3.
Input format :
The first line of input contains an integer ‘T’ denoting the number of test cases.

The first line of each test case contains two space-separated integers, 'X' and ‘N’, where ‘X’ is the length of the road and ‘N’ is the number of lights.

The next line contains ‘N’ space-separated integers denoting the position of the ith light.
Output format :
For each test case, print a single line containing a single integer denoting the maximum gap for every light we install.

The output of each test case will be printed in a separate line.
Note:
You do not need to print anything; it has already been taken care of. Just implement the given function.
Constraints:
1 <= T <= 10
1 <= N <= 2000
1 <= X <= 10 ^ 8
1 <= POS[i] <= X 

Where ‘T’ is the total number of test cases, ‘N’ is the number of lights we install, ‘X’ is the length of the road, and ‘POS[i]’ denotes the position of the 'i th' light.

Time limit: 1 sec.
Sample Input 1 :
2
5 2
3 4
6 3
4 5 1
Sample Output 1 :
3 3 
4 4 3
Explanation of the Sample Input 1:
For the first test case :  
The output will be 3 3.
Initially, there are no lights, and we install a light at position 3 therefore, there is a segment between the 3 and 6. 
Then we install a light at position 4; therefore, the largest gap becomes between 0 to 3.

For the second test case : 
The output will be 4 4 3.
Initially, there is no light. Then we install a light at position 4. Therefore the max gap becomes between 0 and 4.
Then we install a light at position 5, and the largest gap is still 0 to 4.
Then we install a light at position 1 then the largest gap is between 1 to 4, which is 3.      
Sample Input 2 :
2
6 3
5 3 4
7 4
1 2 3 4
Sample Output 2 :
5 3 3 
6 5 4 3
*/



#include<bits/stdc++.h>

struct Compare {
    bool operator()(int a, int b) const {
        return a > b; // Sort in descending order
    }
};

vector<int> trafficLights(int n, int x, vector<int> &pos)
{
	set<int> lights;  // will store every lights that has been entered till now
	lights.insert(0);
	lights.insert(x); // we are entering start and end points, so that distances are calculated from them

	multiset<int, Compare> dists; // for storing the distances that are currently present on the road (multiset because , we can have more than 1 similar distances)
	dists.insert(x);  // the full distance is the only 1 currently present on road

	vector<int> ans(n);

	for(int i=0; i<n; i++){
		auto it = lights.lower_bound(pos[i]);

		int dist1 = 0, dist2 = 0;
		if(*it != pos[i]){  // if *it == pos[i], that means some light is entering at start or end of road, in that case no need to calculate the new distance, since that all is already been taken care of when we entered the lights in the beginning, even before starting this loop
			int higher_pos = *it;
			it--;   // this is IMP => how to go one step down to previous light in map
			int lower_pos = *it;

			dist1 = higher_pos - pos[i];
			dist2 = pos[i] - lower_pos;

			int remove_old_dist = higher_pos - lower_pos;
			dists.erase(dists.find(remove_old_dist));  // this is IMP, beacause if we do dists.erase(remove_old_dist) , than all the similar distances will be erased
																			// so in multiset if you want to remove only 1 similar value than use find()
																			// in set with unique values only, there is no problem
		}

		dists.insert(dist1);
		dists.insert(dist2); // insert the new distances

		ans[i] = *(dists.begin()); 

		lights.insert(pos[i]);  // finally insert the light 
	}

	return ans;
}