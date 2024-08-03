/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204217/offering/2650137/problem/14206?leftPanelTabValue=PROBLEM

The ultimate Ninja Ankush is very happy because all of his students have invited him to their respective parties. But the ultimate Ninja Ankush is terrible at remembering the dates of these events.

Mary has a list of dates of these events. Can you help the Ultimate Ninja sort the list of dates to be easier for him to track the parties? He may even take you with him if you do a good job.

More Formally, You are given an array ‘dates’ consisting of ‘N’ dates. You have to sort this array and print the array in sorted order.

For example:
If ‘dates’ = [ [13,6,2007] , [2,6,2001] , [10,8,2019] , [1,6,2007] ]
Sorted Order of Dates will be :
‘dates’ = [ [ 2,6,2001] , [1,6,2007] , [13,6,2007],  [10,8,2019] ]  
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10 ^ 6
1 <= ‘dates[i][0]’ <= 31
1 <= ‘dates[i][1]’ <=12
2000 <= ‘dates[i][2]’ <=2099

Time limit: 1 sec
Sample Input 1:
2
3    
21 6 2011
11 4 2009
17 8 2009 
2
8 5 2001
5 5 2000
Sample Output 1:
11 4 2009
17 8 2009
21 6 2011
5 5 2000
8 5 2001
Explanation of sample input 1:
For the first test case, 
The sorted list of the dates of events will be: [‘11 April 2009’, ‘17 August 2009’, ‘21 June 2011’]. Hence, the answer of this test case is  [ [ 11,4,2009] , [17,8,2009] , [21,6,2011] ].

For the second test case,
The given dates are [8 May 2001, 5 May 2000]. Clearly since 2000 < 2001. Therefore the answer will be [[5, 5, 2000], [8, 5, 2001]].  
Sample Input 2:
2
3
14 5 2008
16 1 2001
23 3 2098
4
15 7 2000
21 4 2005
29 2 2004
30 12 2001 
Sample Output 2:
16 1 2001
14 5 2008
23 3 2098
15 7 2000
30 12 2001
29 2 2004
21 4 2005
*/




// Time = space = O(N) , N = number of elems in arr
void countSort(vector<vector<int>> &dates, int pos, int maxVal){
	int n = dates.size();
	vector<int> fq(maxVal + 1, 0);
	vector<vector<int>> sortedDates(n, vector<int>(3));

	for(int i=0; i<n; i++){
		fq[dates[i][pos]]++;
	}

    // update fq arr to find the actual position of elems in sorted arr
	for(int i=1; i<=maxVal; i++){
		fq[i] += fq[i-1];
	}

	// we will start from back of dates arr, because suppose we sorting months currently
	// so days are already sorted in dates arr, so if we start from back of dates arr, then we will find the days of a month in decreasing order
	// and that's what we want , because the sortedIndex values also contain the max index for any month initially
	for(int i=n-1; i>=0; i--){
		int sortedIndex = fq[dates[i][pos]] - 1;

        // Building up the sorted arr using fq arr
		sortedDates[sortedIndex] = dates[i];

        // decrementing fq
		fq[dates[i][pos]]--;
	}

    // copying sorted arr to original arr
	for(int i=0; i<n; i++){
		dates[i] = sortedDates[i];
	} 
}

vector<vector<int>> sortBigListDates(vector<vector<int>> &dates)
{
	// we would sort the days first, because then they would guide the sorting of months and then 
	// sorted days and months would drive the sorting of year
	countSort(dates, 0, 31);
	countSort(dates, 1, 12);
	countSort(dates, 2, 2099);
	return dates;
}