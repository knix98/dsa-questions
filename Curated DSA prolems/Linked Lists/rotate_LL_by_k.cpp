/*
https://www.codingninjas.com/studio/problems/rotate-linked-list_920454

You are given a linked list having ‘n’ nodes and an integer ‘k’.



You have to rotate the linked list to the right by ‘k’ positions .



Example :
Input: linked list = [1 2 3 4] , k = 2

Output: 3 4 1 2

Explanation:
We have to rotate the given linked list to the right 2 times. After rotating it to the right once it becomes 4->1->2->3. After rotating it to the right again, it becomes 3->4->1->2. 


Detailed explanation ( Input/output format, Notes, Images )
Sample Input 1 :
6
1 2 3 4 5 6
2


Sample Output 1 :
5 6 1 2 3 4


Explanation For Sample Input 1 :
For the first test case, after 1st clockwise rotation the modified linked list will be : 6->1->2->3->4->5
After, 2nd clockwise rotated the modified linked list will be : 5->6->1->2->3->4.
Thus the output is: 5 6 1 2 3 4.


Sample Input 2 :
3
3 6 9 
0


Sample Output 2:
3 6 9


Explanation For Sample Input 2 :
In this test case, ‘k’ is 0 therefore there will be no rotation, so the linked list remains unchanged.


Expected Time Complexity:
Try to do this in O(n).


Constraints :
1 <= n <= 10^5
0 <= Node.data <= 10^9 
0 <= k <= 10^5

Time Limit: 1 sec
*/




/**
 * Definition for singly-linked list.
 * class Node {
 * public:
 *     int data;
 *     Node *next;
 *     Node() : data(0), next(nullptr) {}
 *     Node(int x) : data(x), next(nullptr) {}
 *     Node(int x, Node *next) : data(x), next(next) {}
 * };
 */


// APPROACH : we dont know n (size of LL). So 1 approach could be determining n by 1 extra traversal first.
// other approach is : we know k => so take pointer t2 till kth node
// then start t1 from head and increase both t1 and t2 till t2 reaches last node
// at this moment, t1->next = starting node of the portion of LL which needs to be rotated
Node *rotate(Node *head, int k) {
     if(k == 0) return head;

     Node *h1, *t1, *h2, *t2;
     
     // taking t2 till kth node
     int count = k;
     t2 = head;
     while(t2 != NULL && count--) t2 = t2->next;

     if(t2 == NULL) {  // means k >= n , so we can simply k = k % n and then call recursion
          int n = k - count;
          k = k % n;
          return rotate(head, k);
     }

     t1 = head;
     while(t2->next != NULL) {
          t1 = t1->next;
          t2 = t2->next;
     }

     h1 = head;
     h2 = t1->next;

     // now we have heads(h1 and h2) and tails(t1 and t2) of both the portions
     t1->next = NULL;
     t2->next = h1;
     head = h2;
     
     return head;
}
