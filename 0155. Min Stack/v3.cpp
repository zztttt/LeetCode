class MinStack {
public:
    stack<int> value;
    stack<int> minV;
    MinStack() {
        
    }
    
    void push(int val) {
        value.push(val);
        if(minV.empty()){
            minV.push(val);
        }else{
            int curMin = minV.top();
            if(val < curMin)
                minV.push(val);
            else
                minV.push(curMin);
        }   
    }
    
    void pop() {
        value.pop();
        minV.pop();
    }
    
    int top() {
        return value.top();
    }
    
    int getMin() {
        return minV.top();
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