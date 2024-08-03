/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204217/offering/2650137/problem/13832?leftPanelTabValue=PROBLEM

Given an array 'arr' of size 'N', find the minimum number of swaps required to be made between any two elements to sort the array in ascending order. The array does not contain duplicates i.e all the elements of the array are distinct.

Example :

Let the given array be [1,5,4,3,2]  we swap index 1 with 4 i.e. 5 -> 2 and 2 with 3 i.e. 4 -> 3 to form the sorted array {1, 2, 3, 4, 5}.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= T <= 100
1 <= N <= 1000
0 <= ARR[i] <= 10 ^ 9

Where 'ARR[i]' is the value of the input array elements.

Time Limit: 1 sec
Sample Input 1:
2
5
2 4 5 1 3
4
9 1 8 4
Sample Output 1:
3
2
Explanation of Sample Input 1:
For the first test case, swap index 0 with 3 i.e. 2 -> 1 and 1 with 3 i.e. 4 -> 2 and finally index 2 with index 4 i.e 5 ->3 
to form the sorted array {1, 2, 3, 4,5}. Hence one swap is needed

For the second test case, swap index 0 with 1 i.e. 9 -> 1 and index 1 with 3 i.e. 9 -> 4 to form the sorted array {1, 4,8,9}. Hence 2 swaps are needed.
Sample Input 2:
2
4
1 2 3 4
6
3 5 2 4 6 8
Sample Output 2:
0
3

*/




int minSwaps(vector<int> &arr) {
	int n = arr.size();

	map<int,int> pos;
	for(int i=0; i<n; i++){
		pos[arr[i]] = i;
	}

	int i=0;
	int swaps = 0;
	for(auto j : pos){
		if(arr[i] != j.first){
			// means correct elem is not present at i, according to sorted order
			swaps++;
			
			int bIndex = j.second;   // current index of correct elem
			int aIndex = i;  // current index of incorrect elem
			
			arr[bIndex] ^= arr[aIndex] ^= arr[bIndex] ^= arr[aIndex];

			pos[arr[aIndex]] = aIndex;
			pos[arr[bIndex]] = bIndex;
		}

		i++;
	}

	return swaps;
}