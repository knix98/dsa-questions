/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204226/offering/2650150/problem/14205?leftPanelTabValue=SUBMISSION

You are a student of the Ultimate Ninja Ankush, and today is the day you prove yourself to the Ultimate Ninja Ankush by solving whatever problem Ankush throws at you.

You have been given two arrays having an equal number of elements. You have to find whether one array is the valid stack permutation of the other. An array is said to be a valid stack permutation of the other if and only if after applying some push and pop operations onto the sequence of elements in that array, will result in the other array.

Tell correctly whether the array is valid stack permutation or not, to prove your worth to the Ultimate Ninja Ankush.

Example 1:

Input:
N = 3
A = {1,2,3}
B = {2,1,3}
Output:
1
Explanation:
1. push 1 from A to stack
2. push 2 from A to stack
3. pop 2 from stack to B
4. pop 1 from stack to B
5. push 3 from A to stack
6. pop 3 from stack to B
 

Example 2:

Input:
N = 3
A = {1,2,3}
B = {3,1,2}
Output:
0
Explanation:
Not Possible

Note:
Please note that the arrays will only contain unique elements.
Detailed explanation ( Input/output format, Notes, Images )
Constraints:
1 <= ‘T’ <= 10
1 <= ‘N’ <= 10000
0 <= ‘FIRST[i]’, ‘OTHER[i]’ <= 10^5

Where 'FIRST[i]' and 'OTHER[i]' denote the value of the i-th element of the input arrays.

Time limit: 1 sec.
Sample Input 1:
2
3
2 4 6
4 6 2
4
2 4 6 5
6 2 4 1
Sample Output 1:
YES
NO
Explanation of Sample Output 1:
In test case 1, [2,4,6] can be transformed into [4,6,2] to by doing the following:
push ‘2’ 
pop ‘4’ 
push ‘4’ 
pop ‘2’ 
push ‘6’ 
pop ‘6’ 


In test case 2, There is now way 2,4,6,5 can be converted into [6,2,4,1] since there is a mismatch between elements that are of 1 and 5.
Sample Input 2:
2
3
2 4 6
2 3 4
1
5
5
Sample Output 2:
NO
YES
Explanation for Sample Output 2:
In test case 1, the 'FIRST' array does not contain 3 but the 'OTHER' array contains 3. So, the other is not the valid stack permutation.

In test case 2, the only array containing ‘5’ as an element is the valid stack permutation of the array [5].
*/




// when we push elems from arr 'a' into stack, then for making elems of arr b, we only have the option of picking elems from st.top()
// so if the curr elem of 'b', is not found on top of stack, then we will push more elems from arr 'a' into the stack , untill we get the current elem of 'b' on top of stack
bool validStackPermutation(vector<int> &a, vector<int> &b) {
	int n = a.size();
	int m = b.size();
	int i=0, j=0;  // i travels over a, j over b
	stack<int> st;

    // trying to get all elems of b in order 
	while(j<m){
        // checking !st.empty() is important. Otherwise error comes
		if(!st.empty() && st.top() == b[j]) {  
			st.pop();
		}
		else{
			while(i<n && a[i] != b[j]){
				st.push(a[i]);
				i++;
			}

			if(i == n) return false; 
			else {
				st.push(a[i]);
				i++;
			}

			st.pop();
		}
		
		j++;  // moving to next elem in b for checking
	}

	return true;
}