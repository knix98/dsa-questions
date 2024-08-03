/*
This code contains 2 problems solutions.
the min-stack problem has given us an O(1) alternative to retrieving the minimum element in the currently present elements
*/


/*
Problem 1 : Min Stack (without popMin operation)
leetcode : https://leetcode.com/problems/min-stack/description/
solution inspired by neetcode video : https://www.youtube.com/watch?v=qkLl7nAwDPo
NOTE : we can similarly implement a max stack also
*/
class MinStack {
private:
stack<pair<int,int>> s; // <val, minm val in stack uptill this point starting from the bottom of stack>

public:
    MinStack() {
        
    }
    
    void push(int val) {
        int minm; 
        if(s.empty()) minm = val;
        else minm = min(val, s.top().second);

        s.push({val, minm});
    }
    
    void pop() {
        s.pop();
    }
    
    int top() {
        return s.top().first;
    }
    
    int getMin() {
        return s.top().second;
    }
};



/*
Problem 2 : Max Stack (with popMax operation)
Lintcode : https://www.lintcode.com/problem/859/
solution inspired by : https://www.youtube.com/watch?v=BcZzdkvCQ0s

Intuition : to maintain the relative order of elems like in a stack, we will use a doubly-linked-list (DLL), which would maintain the order as well as help
in O(1) removal of any node from inbetween in popMax() operation
For maintain the decreasing order of elems we would use a decreasing order map
*/
class Node   // DLL node
{
public:
   int val;
   Node *next, *prev;

   Node(int val)
   {
      this->val = val;
      next = prev = NULL;
   }
};

// Custom comparator for descending order
struct DescendingOrder {
    bool operator()(const int& lhs, const int& rhs) const {
        return lhs > rhs;
    }
};

class MaxStack
{
private:
   Node *tail;
   map<int, vector<Node*>, DescendingOrder> mp;  // key = int inside DLL, value = vector of all nodes which has this value with the topmost one being at the back of the vector

public:
   MaxStack()
   {
      tail = NULL;
   }

   void push(int number)
   {
      Node *newNode = new Node(number);
      if(tail) tail->next = newNode;
      newNode->prev = tail;
      tail = newNode;

      mp[number].push_back(newNode);
   }

   int pop()
   {
      Node *secondLast = tail->prev;
      int ans = tail->val;
      delete tail;
      tail = secondLast;
      if(tail) tail->next = NULL;

      mp[ans].pop_back();
      if(mp[ans].size() == 0) mp.erase(ans);  // IMP : if we dont remove a int from map, when its vector is empty, then it would stay at the begin of map
                                              // and would give segmentation error when we try to get the back() elem of an empty vector

      return ans;
   }

   int top()
   {
      return tail->val;
   }

   int peekMax()
   {
      return mp.begin()->first;
   }

   int popMax()
   {
      Node *maxm = mp.begin()->second.back();
      int ans = maxm->val;
      mp.begin()->second.pop_back();
      if(mp[ans].size() == 0) mp.erase(ans);  // IMP : if we dont remove a int from map, when its vector is empty, then it would stay at the begin of map
                                              // and would give segmentation error when we try to get the back() elem of an empty vector

      if(maxm->prev) maxm->prev->next = maxm->next;
      if(maxm->next) maxm->next->prev = maxm->prev;
      if(maxm == tail) tail = maxm->prev;
      delete maxm;

      return ans;
   }
};