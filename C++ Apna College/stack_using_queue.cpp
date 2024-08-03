#include<bits/stdc++.h>
using namespace std;

class nikhilStack{
    queue<int> a; // will always be pushing new elements in a 
    queue<int> b; // b is helper queue

    public:
    void push(int x) {
        a.push(x);
    }

    int pop() { // will returned the popped element
        if(a.empty()){
            return INT_MIN;
        }

        while(a.size() > 1){ // transfer all (leaving only the last entered element) elements from a to b
            int front = a.front();
            a.pop();
            b.push(front);
        }

        int ans = a.front(); // last entered element is the answer
        a.pop();

        // while(!b.empty()){ // transfer elements again from b to a , because we are pushing in a only by default
        //     a.push(b.front());
        //     b.pop();
        // }

        // since now all the elements excluding the poppped element is in queue b, we need to swap queues a and b
        queue<int> temp = b; 
        b = a;
        a = temp;

        return ans;
    }
};

int main() {
    nikhilStack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);

    cout << st.pop() << endl;
    cout << st.pop() << endl;

    st.push(5);
    st.push(6);

    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
    cout << st.pop() << endl;
}