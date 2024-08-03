class Solution {
public:
    ListNode* reverseLL(ListNode* head) {
        if(!head || !head->next) return head;

        ListNode *prev = NULL, *curr = head, *next = NULL;
        while(curr) {
            next = curr->next;
            curr->next = prev;
            prev = curr;
            curr = next;
        }

        return prev;
    }

    void reorderList(ListNode* head) {
        if(!head || !head->next || !head->next->next) return;

        // first reach the mid point of LL
        ListNode* fast = head, *slow = head;
        while(fast->next && fast->next->next) fast = fast->next->next, slow = slow->next;

        // reverse head2
        ListNode *head2 = slow->next;
        slow->next = NULL;
        head2 = reverseLL(head2);

        // combine 2 LLs
        ListNode *head1 = head->next;
        ListNode *temp = head;
        while(head2) {
            temp->next = head2;
            temp = temp->next;
            head2 = head2->next;

            if(head1) {
                temp->next = head1;
                temp = temp->next;
                head1 = head1->next;
            }
        }

        temp->next = NULL;
    }
};