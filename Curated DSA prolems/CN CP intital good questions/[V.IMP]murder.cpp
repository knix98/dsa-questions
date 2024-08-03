/*
https://classroom.codingninjas.com/app/classroom/me/22205/content/575395/offering/8882413/problem/7217

Once detective Saikat was solving a murder case. While going to the crime scene he took the stairs and saw that a number is written on every stair. He found it suspicious and decides to remember all the numbers that he has seen till now. While remembering the numbers he found that he can find some pattern in those numbers. So he decides that for each number on the stairs he will note down the sum of all the numbers previously seen on the stairs which are smaller than the present number. Calculate the sum of all the numbers written on his notes diary.

Answer may not fit in integer . You have to take long.

Detailed explanation ( Input/output format, Notes, Images )
Constraints
T<=10^5
1<=N<=10^5
All numbers will be between 0 and 10^9
Sum of N over all test cases doesn't exceed 5*10^5
Output Format
For each test case output one line giving the final sum for each test case.
Sample Input 1:
1
5
1 5 3 6 4
Sample Output 1:
15
Explanation:
For the first number, the contribution to the sum is 0.
For the second number, the contribution to the sum is 1.
For the third number, the contribution to the sum is 1.
For the fourth number, the contribution to the sum is 9 (1+5+3).
For the fifth number, the contribution to the sum is 4 (1+3).
Hence the sum is 15 (0+1+1+9+4).
*/




/*
IMP NOTE : first I was thinking to do this problem using a map (for maintaining ascending order of already encountered elems) and
lower_bound for finding elems amongst these which are smaller than the current elem
But using this technique, I would be able to find only the smaller elems, but not the sum of them
So we have to think of some approach, in which elems smaller than any elem and encountered previously in the arr are counted 1 by 1,
so that as we find these elems, we can keep on adding them up.
Using merge sort algo, we can do so. Because in merge sort, we know the elems which fall towards left of any elem (left half arr) and also
while merging the left and right subarrays we find the smaller elems 1 by 1, so we can keep adding them up.
So IMP => any situation/question where we are compelled to use lower_bound to find smaller elems in a sorted arr, and also nlogn time complexity
is required, we might think of merge sort algo option also, if it solves our problem.
*/
#include<bits/stdc++.h>
using namespace std;

#define ll long long

// INTUITION : using mergesort algo we will be able to divide the whole array and in each smaller divided arrays we will
// be able to find the elements which are smaller but are appearing before a given element in the array
// Basically in the given problem WE HAVE TO TAKE SUMMATION OF ALL THE INVERSION ELEMENTS FOR ALL THE ELEMENTS
// INVERSION ELEMENTS OF AN ELEMENT X : ELEMENTS WHICH ARE SMALLER THAN X AND APPEARING BEFORE X IN THE ARRAY


// this function is supposed to sort the passed array and also add all the inversion sum for this particular array to the global sum
void mergeSort(vector<ll> &v, int st, int en, ll &sum){
    if(st >= en) return;

    int mid = (st+en)/2;

    // IMPORTANT : division should always be mid and mid+1 (dont do mid-1 and mid) because if st ==0 and en == 1
    // then mid == 0 and mid-1 == -1
    mergeSort(v, st, mid, sum); 
    mergeSort(v, mid+1, en, sum);

    vector<ll> temp((en-st)+1);

    // assuming that the inversions sum in the two halves have been handeled already
    // now we just need to find : for each right array element => how many elements from the left array are appearing before it

    int i=st, j=mid+1, k=0;
    ll leftElemSum = 0; // a variable for storing the sum of all the left array elements which have been placed in the sorted (temp) array
    while(i <= mid && j <= en){
        if(v[i] < v[j]){
            temp[k++] = v[i];
            leftElemSum += v[i];
            i++;
        }
        else{
            temp[k++] = v[j];
            sum += leftElemSum; // whenever a right element added in temp, add the leftElemSum to the global sum
            j++;
        }
    }

    while(i <= mid) {
        temp[k++] = v[i++];
    }
    while(j <= en) {
        temp[k++] = v[j++];
        sum += leftElemSum;
    }

    for(int p=st, q=0; p <= en; p++, q++){
        v[p] = temp[q];
    }
}

int main(){
    int t;
    cin >> t;

    while(t--){
        int n;
        cin >> n;

        vector<ll> v(n);
        for(int i=0; i<n; i++){
            cin >> v[i];
        }

        ll sum = 0; // this would store the final sum answer
        mergeSort(v, 0, n-1, sum);

        cout << sum << endl;
    }

    return 0;
}