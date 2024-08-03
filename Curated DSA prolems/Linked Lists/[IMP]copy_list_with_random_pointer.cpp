/*
https://leetcode.com/problems/copy-list-with-random-pointer/
*/


/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* next;
    Node* random;
    
    Node(int _val) {
        val = _val;
        next = NULL;
        random = NULL;
    }
};
*/

// APPROACH 1 : using hashmap , Time = O(n), space = O(n)
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        unordered_map<Node*, Node*> mp; // this will keep a track of which nodes from original LL have already been created in the new copy LL

        Node *head1 = new Node(head->val);
        mp[head] = head1;
        Node *tail = head1;

        while(head != NULL){  // head will be traversing over original LL and tail will be constructing copy LL 1 by 1
            if(head->next == NULL){
                tail->next = NULL;
            }
            else if(mp.count(head->next) > 0){
                tail->next = mp[head->next];
            }
            else{
                Node *temp = new Node(head->next->val);
                mp[head->next] = temp;
                tail->next = temp;
            }

            if(head->random == NULL){
                tail->random = NULL;
            }
            else if(mp.count(head->random) > 0){
                tail->random = mp[head->random];
            }
            else{
                Node *temp = new Node(head->random->val);
                mp[head->random] = temp;
                tail->random = temp;
            }

            tail = tail->next;
            head = head->next;
        }

        return head1;
    }
};




// APPROACH 2 : Time : O(n), space : O(1)
/*
Solution #2: Interweaving Nodes Method
Intuition and Logic Behind the Solution
    The crux of this method is to interweave the nodes of the original and copied lists. This interweaving allows us to set the random pointers for the new nodes without needing additional memory for mapping.

Step-by-step Explanation
Initialization and Interweaving:
    Traverse the original list.
    For each node, create a corresponding new node and place it between the current node and the current node's next.

Setting Random Pointers:
    Traverse the interweaved list.
    For each old node, set its corresponding new node's random pointer.

Separating Lists:
    Traverse the interweaved list again to separate the old and new lists.
*/
class Solution {
public:
    Node* copyRandomList(Node* head) {
        if(head == NULL) return head;

        // first inserting copy nodes in between (after every node) in original LL
        Node *temp = head;
        Node *t;
        while(temp != NULL){
            t = new Node(temp->val);
            t->next = temp->next;
            temp->next = t;
            temp = t->next;
        }

        // then connecting random pointers for the copy nodes
        temp = head;
        while(temp != NULL){
            t = temp->next;
            if(temp->random == NULL) t->random = NULL;
            else{
                t->random = temp->random->next;
            }

            temp = temp->next->next;
        }

        // finally connecting next pointers of the copy nodes and also disconnecting them from original LL
        temp = head;
        Node *head1 = head->next; // this would be head of copy LL
        while(temp != NULL){
            t = temp->next; // t = curr copy node
            temp->next = t->next; // temp connected to next node in original LL
            
            if(t->next != NULL){
                t->next = temp->next->next; // t connected to next node in copy LL
            }

            temp = temp->next;
        }

        return head1;
    }
};