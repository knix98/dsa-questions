/*
Given k different arrays, which are sorted individually (in ascending order).
You need to merge all the given arrays such that output array should be sorted (in ascending order).
The lengths of all the k arrays are different.
*/

#include <vector>
#include <queue>
using namespace std;

class object
{
public:
    vector<int> *pointer; // will contain pointer to one of the k vectors
    int index;            // will indicate the current index in the current vector

    object(vector<int> *x, int y)
    { // constructor
        pointer = x;
        index = y;
    }
};

class cmp
{ // comparator class for the inbuilt priority queue
public:
    bool operator()(const object &a, const object &b)
    {                                                           // operator overloading
        return a.pointer->at(a.index) > b.pointer->at(b.index); // to create min heap
    }
};

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{
    vector<int> output;
    priority_queue<object, vector<object>, cmp> pq;

    for (int i = 0; i < input.size(); i++)
    {
        object p(input[i], 0);
        pq.push(p);
    }

    while (!pq.empty())
    {
        object min = pq.top();
        pq.pop();
        output.push_back(min.pointer->at(min.index));
        (min.index)++;
        if (min.index < min.pointer->size())
        {
            pq.push(min);
        }
    }

    return output;
}

// 2nd CODE : Similar approach, just done using inbuilt pair class
class cmp
{
public:
    bool operator()(pair<vector<int> *, int> &a, pair<vector<int> *, int> &b)
    {
        return a.first->at(a.second) > b.first->at(b.second);
    }
};

vector<int> mergeKSortedArrays(vector<vector<int> *> input)
{

    priority_queue<pair<vector<int> *, int>, vector<pair<vector<int> *, int>>, cmp> pq;
    for (int i = 0; i < input.size(); i++)
    {
        pair<vector<int> *, int> p;
        p.first = input[i];
        p.second = 0;

        pq.push(p);
    }

    vector<int> output;

    while (!pq.empty())
    {
        pair<vector<int> *, int> top = pq.top();
        pq.pop();
        output.push_back(top.first->at(top.second));
        top.second++;
        if (top.second < top.first->size())
            pq.push(top);
    }

    return output;
}