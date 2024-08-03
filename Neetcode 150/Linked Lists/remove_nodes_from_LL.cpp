/*
https://leetcode.com/problems/remove-nodes-from-linked-list/description/
*/

class Solution {
public:
   ListNode* reverseLL(ListNode *head) {
      ListNode *prev = NULL, *curr = head, *next = NULL;
      while(curr) {
         next = curr->next;
         curr->next = prev;
         prev = curr;
         curr = next;
      }

      return prev;
   }

    // could have done this similar approach using a dp array for maintaining the maxTillNow for each index
    // but for doing it in O(1) space we are doing it using the approach of reversing the LL
    // reverse approach taken from neetcode
   ListNode* removeNodes(ListNode* head) {
      head = reverseLL(head);

      ListNode *temp = head, *del = NULL;
      int maxTillNow = temp->val;
      while(temp->next) {
         if(temp->next->val < maxTillNow) {
            del = temp->next;
            temp->next = del->next;
            delete del;
         }
         else {
            maxTillNow = temp->next->val;
            temp = temp->next;
         }
      }

      return reverseLL(head);
   }
};