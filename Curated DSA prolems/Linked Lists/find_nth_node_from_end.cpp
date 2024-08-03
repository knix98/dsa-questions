/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204225/offering/2650149/problem/14049?leftPanelTabValue=PROBLEM

Ninja has been given a Singly Linked List having N nodes. As part of a test, he has been asked to find the Nth node from the end of the linked list. Since Ninja is not so good at studies, he asked you to help him with the same.

Your task is to find the Nth node from last.

For Example
If the given list is (4 -> 3 -> 2 -> 7) and N = 2:

Then the 2nd node from the end is 2.
Detailed explanation ( Input/output format, Notes, Images )
Input Format
The first line of input contains a single integer T, representing the number of test cases or queries to be run. 

The first line of each test case contains the elements of the linked list separated by a single space and terminated by -1. Hence, -1 would never be a list element.

The second line contains an integer ‘N’, the position of the node from the end which you have to find.
Output Format
For each test case, print the value of the N-th node from the end.

Print the output of each test case in a separate line.
Note
You do not need to print anything. Just implement the given function and return a pointer pointing to the node which is at the N-th position from the last of the linked list.
Constraints
1 <= T <= 10
1 <= L <= 10^4
-10^9 <= data <= 10^9 
1<= N <= L
data != -1

Time Limit:  sec
Sample Input 1
2
5 6 7 9 -1
3
10 15 12 -1
1
Sample Output 1
6
12
Explanation for Sample Input 1
In the 1st test case, the 3rd node from the end is 6.
In the 2nd  test case, the 1st node from the end is 12.
Sample Input 2
2
5 4 3 6 7 -1
4
5 -5 -1
2
Sample Output 2
4
5
*/




/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

//FIRST APPROACH : first count total number of nodes by traversal, then traverse again to get 
// to the target node and return that node

Node* nthNodeFromEnd(Node* head, int n)
{
	int length = 1;
	Node* temp = head;

	while(temp->next != NULL){
		temp = temp->next;
		length++;
	}

	int nodeIndex = length - n;
	temp = head;
	while(nodeIndex != 0){
		temp = temp->next;
		nodeIndex--;
	}

	return temp;
}


// SECOND APPROACH : giving answer in 1 traversal only
Node *nthNodeFromEnd(Node *head, int n){
	Node *ptr1 = head;
	Node *ptr2 = head;

	int i = 1;

	//first make the ptr1 reach nth node
	while(i < n){
		ptr1 = ptr1->next;
		i++;
	}

	//then make both ptrs move till ptr1 reaches the end;
	while(ptr1->next != NULL){
		ptr1 = ptr1->next;
		ptr2 = ptr2->next;
	}

	return ptr2;
}