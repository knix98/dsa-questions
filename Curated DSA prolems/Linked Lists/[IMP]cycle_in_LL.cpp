/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204225/offering/2650149/problem/13919?leftPanelTabValue=SUBMISSION
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

// can look at striver(TUF) LL cycle videos if want to revise
// Question 1 : detect whether cycle is there in LL
bool detectCycle(Node *head){
	if(head == NULL || head->next == NULL) return false;

    // slow and fast both would start from head only, but for my code I have to move them to their respective 2nd position intially
	Node *fast = head->next->next, *slow = head->next;
	while(fast != NULL && fast->next != NULL){
		if(fast == slow) return true;
		fast = fast->next->next;
		slow = slow->next;
	}

	return false;
}



// Question 2 : detect whether cycle and then return starting node of loop or return NULL
Node *firstNode(Node *head){
    if(head == NULL || head->next == NULL) return NULL;

    Node *slow = head->next, *fast = head->next->next;
    while(fast != NULL && fast->next != NULL){
        if(slow == fast) break;
        fast = fast->next->next;
        slow = slow->next;
    }

    if(fast != slow) return NULL;

    slow = head;
    while(fast != slow) {
        slow = slow->next;
        fast = fast->next;
    }

    return slow;
}



// Question 3 : return length of loop in LL
// solution : just find the node at which fast and slow coincide, then from that node traverse the whole loop till you again reach this node
// and keep counting the number of nodes in the loop