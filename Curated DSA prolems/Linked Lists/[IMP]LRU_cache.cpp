/*
https://classroom.codingninjas.com/app/classroom/me/11692/content/204226/offering/2650150/problem/14071?leftPanelTabValue=PROBLEM

Ninjas was feeling bored one day. He went for a walk and suddenly thought of a problem which he was unable to solve. Can you help Ninja out?

Your task is to design and implement a data structure for Least Recently Used (LRU) cache to support the following operations:

1. get(key) - Return the value of the key if the key exists in the cache, otherwise return -1.

2. put(key, value), Insert the value in the cache if the key is not already present or update the value of the given key if the key is already present. When the cache reaches its capacity, it should invalidate the least recently used item before inserting the new item.
You will be given ‘Q’ queries to process. Each query will belong to one of these two types:
Type 0: for get(key) operation.
Type 1: for put(key, value) operation.
Note :
1. The cache is initialized with a capacity (the maximum number of unique keys it can hold at a time).

2. Access to an item or key is defined as a get or a put operation on the key. The least recently used key is the one with the oldest access time.
Detailed explanation ( Input/output format, Notes, Images )
Constraints :
1 <= C <= 10^4
1 <= Q <= 10^5
1 <= key, value <= 10^9

Time Limit: 1 sec
Sample Input 1 :
3 11
1 1 1
1 2 2
1 3 3
1 4 5
0 3
0 1
0 4
1 2 3
0 1
0 3
0 2
Sample Output 1 :
3
-1
5
-1
3
3
Explanation to Sample Input 1 :
alt-text

Initializing a cache of capacity 3, LRUCache cache = new LRUCache(3);
Then each operation is performed as shown in the above figure.
cache.put(1,1)
cache.put(2,2)
cache.put(3,3)
cache.put(4,5)
cache.get(3)      // returns 3
cache.get(1)      // returns -1
cache.get(2)      // returns 2
cache.put(5,5)
cache.get(4)      // returns -1
cache.get(3)      // returns 3
Sample Input 2 :
2 6
1 1 1
1 2 2
0 2
1 3 3
0 3
0 1
Sample Output 2 :
2
3
-1
*/



/*
We would use a LL for maintaining the keys in order of their usage (LRU) and a map for maintaining the pointers to the corresponding key's nodes in LL.
here we would have to use doubly linked list => so that we are able to remove nodes from in between in O(1) using node pointer from map
But when using DLL we have to be carefull of taking care of both the left and the right pointers of a node, and also edge cases like if 
the node to be removed is head or tail of DLL
*/
#include<unordered_map>

class Node{
public:
    int key, value;
    Node *left, *right;

    Node(int k, int v){
        key = k;
        value = v;
        left = right = NULL;
    }
};

class LRUCache
{
    int capacity, size;
    unordered_map<int, Node*> mp;
    Node *head, *tail;

public:
    LRUCache(int capacity)
    {
        this->capacity = capacity;
        size = 0;
        head = tail = NULL;
    }

    void makeTargetHead(Node* target){
        if(head == target) return;
        else if (tail == target) {
          target->left->right = NULL;
          tail = target->left;
        }
        else{
            target->left->right = target->right;
            target->right->left = target->left;
        }

        target->left = NULL;
        target->right = head;
        head->left = target;
        head = target;
    }

    int get(int key)
    {
        if(mp.count(key) == 0) return -1;

        Node* target = mp[key];
        makeTargetHead(target);

        return target->value;
    } 

    void put(int key, int value)
    {
        if(mp.count(key) > 0){
            Node* target = mp[key];
            target->value = value;
            makeTargetHead(target);
        }
        else{
            mp[key] = new Node(key, value);

            if(size < capacity){
                size++;
            }
            else{
                Node* prevTail = tail;

                if(head == tail) head = tail = NULL;
                else{
                    tail = tail->left;
                    tail->right = NULL;
                }
                
                mp.erase(prevTail->key);
                delete prevTail;
            }

            Node* target = mp[key];
            target->right = head;
            if(head != NULL) head->left = target;
            head = target;
			if(tail == NULL) tail = target;
        }
    }
};