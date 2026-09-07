class MinStack {
    stack<pair<int, int>> mpp;
public:
    MinStack() {
        // stack<pair<int, int>> mpp;
    }
    
    void push(int value) {
        if(mpp.empty()){
            mpp.push({value, value});
        }else{
            mpp.push({value, min(value, mpp.top().second)});
        }
    }
    
    void pop() {
        mpp.pop();
    }
    
    int top() {
        return mpp.top().first;
    }
    
    int getMin() {
        return mpp.top().second;
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(value);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */