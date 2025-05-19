#include <stack>
#include <algorithm>
#include <cmath>
class MinStack {
    public:
    std::stack<int> curr_stack;
    std::stack<int> min_stack;
    int curr_min = 0;
    MinStack() {
    }
    
    void push(int val) {
        if(min_stack.empty()){curr_min = val;}
        else{
            curr_min = std::min(val,min_stack.top());
        }
        curr_stack.push(val);
        min_stack.push(curr_min);
    }
    
    void pop() {
        curr_stack.pop();
        min_stack.pop();
    }
    
    int top() {
        return curr_stack.top();
    }
    
    int getMin() {
        return min_stack.top();
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