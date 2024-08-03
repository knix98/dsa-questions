/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575396/offering/8882414/problem/11798?leftPanelTabValue=PROBLEM

Ninja is planning to organize an exhibition in which ‘2N’ peoples are coming. The hall’s capacity in which the exhibition is going to take place is only ‘N’. So, ninja thinks of organizing two exhibitions in 2 different cities, ‘CITY_A’ and ‘CITY_B’, each of capacity ‘N’. All ‘2N’ people will come to the exhibition but in the group of ‘N’ in two different cities. Ninja wants your help in organizing this event.

You are given an array ‘COST’ where “COST[i] = [COST_TO_Ai, COST_TO_Bi]”, in which ‘COST_TO_Ai’ is the cost of the ith person to fly to the city A, and ‘COST_TO_Bi’ is the cost of the ith person to fly to the city B. Your task is to find the minimum cost of organizing the exhibition in which every person flies to a city such that exactly ‘N’ people arrive in each city.

Note:

The intersection of the set of the persons who go to ‘CITY_A’ to those going to ‘CITY_B’ is to be disjoint set, whereas the union must be the ‘2N’.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 10
1 <= N <= 50
COST.length == 2*N
1 <= CostToAi, CostToBi <= 10^4

Time Limit: 1sec
Sample Input 1:
1
2
5 100
50 10
10 200
100 20
Sample Output 1:
45
Explanation for sample input 1:
The first person will go to City ‘A’ at the cost of 5.

The second person will go to City ‘B’ at the cost of 10.

The third person will go to City ‘A’ at the cost of 10.
The last person will go to City ‘B’ at the cost of 20.
So, the total minimum cost will be = 5 + 10 + 10 + 20 = 45. There is no other way to get the cost less than 45.
Sample Input 2:
1
1
200 200
100 200
Sample Output 2:
300
Explanation for sample input 2:
The first person will go to City ‘B’ at the cost of 200.

The second person will go to City ‘A’ at the cost of 100.
So, the total minimum cost will be = 200 + 100 = 300. There is no other way to get the cost less than 300.
*/






/*
Mathematical Explanation :-
let costs = [[a1,b1], [a2,b2], [a3,b3], [a4,b4], [a5, b5], [a6, b6]]

lets suppose this is the final answer arrangement : in which 1, 2, 3 go to A and rest to B
totalCost = (a1 + a2 + a3) + (b4 + b5+ b6)

add and subtract a4,a5,a6
totalCost = (a1 + a2 + a3 + a4 + a5 + a6) + (b4 - a4 + b5 - a5 + b6 - a6)
               = (total_a_sum) + (person4_cost_diff + person5_cost_diff + person6_cost_diff)

Now total_a_sum is fixed/constant
So to minimise the cost we have to minimise the the second bracket sum
and to do that we have to find n such persons (out of total 2n persons) whose b - a difference is minimum
*/

int findMinCost(int n, vector<vector<int>> &cost)
{
	int total_a_sum = 0;
	vector<int> diff(cost.size()); // for storing the b-a diff values

	for(int i=0; i<cost.size(); i++){
		total_a_sum += cost[i][0];
		diff[i] = cost[i][1] - cost[i][0];
	}

	sort(diff.begin(), diff.end()); // since we need to get n minmum diff values

	int finalCost = total_a_sum;
	for(int i=0; i<n; i++){
		finalCost += diff[i];
	}

	return finalCost;
}