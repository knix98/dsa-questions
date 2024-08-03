/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204225/offering/2650149/problem/13941?leftPanelTabValue=SUBMISSION

Ninja has been given a biotonic doubly linked list. Ninja has to sort the given biotonic doubly linked list.

Note :
Biotonic Doubly linked list is the one which is first increasing and then decreasing. A strictly increasing or strictly decreasing doubly linked list is also biotonic.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= T <= 10
1 <= N <= 5 * 10^4
-10^9 <= data <= 10^9 and data != -1

Where T is the number of test cases, N is the length of the doubly linked list.

Time Limit: 1sec
Sample Input 1:
3
1 5 8 4 2 -1
9 10 -1
4 3 -1
Sample Output 1:
1 2 4 5 8 -1
9 10 -1
3 4 -1
Explanation For Sample Input 1:
For the first test case : 
On sorting the doubly linked list, we get
1 2 4 5 8
Sample Input 2:
2
-9 -6 -5 -3 1 5 7 7 9 7 -1
-14 -12 -2 7 9 14 -8 -11 -1
Sample Output 2:
-9 -6 -5 -3 1 5 7 7 7 9 -1
-14 -12 -11 -8 -2 7 9 14 -1
*/




/****************************************************************

    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node *prev;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
		        this->prev = NULL;
	        }
        };

*****************************************************************/

// APPROACH : keep 2 pointers => 1 at start of DLL (temp1) and other at end of DLL (temp2)
// and then go forward on temp1 and backward on temp2 comparing and merging them in a resultant DLL
// IMPORTANT : the thing to take care about when dealing with DLL is that you have to connect both next and prev pointers of any node
Node *sortDLL(Node *head) {
	if(head == NULL || head->next == NULL) return head;

	Node *temp1 = head, *temp2 = head;
	while(temp2->next != NULL) temp2 = temp2->next;

	head = NULL;
	Node *tail = NULL;
	Node *attach;
	while(temp1 != temp2){
		if(temp1->data < temp2->data){
			attach = temp1;
			temp1 = temp1->next;
		}
		else{
			attach = temp2;
			temp2 = temp2->prev;
		}

		attach->prev = NULL;
		attach->next = NULL;

		if(head == NULL) {
			head = tail = attach;
		}
		else{
			tail->next = attach;
			attach->prev = tail;
			tail = attach;
		}
	}

	tail->next = temp1;
	temp1->prev = tail;
	temp1->next = NULL;

	return head;
}