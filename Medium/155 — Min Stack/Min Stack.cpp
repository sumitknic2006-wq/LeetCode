#include<iostream>
using namespace std;
class MinStack {
private:
    std::stack<int> st;
    std::stack<int> minSt;

public:
    MinStack() {
        // Stacks are automatically initialized empty in C++
    }
    
    void push(int val) {
        if (st.empty() || minSt.top() >= val) {
            minSt.push(val);
        }
        st.push(val);
    }
    
    void pop() {
        int ele1 = st.top();
        st.pop(); // In C++, pop() returns void, so call top() first
        
        int ele2 = minSt.top();
        if (ele1 == ele2) {
            minSt.pop();
        }
    }
    
    int top() {
        return st.top();
    }
    
    int getMin() {
        return minSt.top();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(val);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */