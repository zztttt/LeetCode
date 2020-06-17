class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> _data;
    vector<int> _min;
    MinStack() {
        
    }
    
    void push(int x) {
        
        int curMin;
        if(_min.size() > 0)
            curMin = x < _min.back()? x:_min.back();
        else
            curMin = x;
        _data.push_back(x);
        _min.push_back(curMin);
    }
    
    void pop() {
        _data.pop_back();
        _min.pop_back();
    }
    
    int top() {
        return _data.back();
    }
    
    int getMin() {
        return _min.back();
    }
};

/**
 * Your MinStack object will be instantiated and called as such:
 * MinStack* obj = new MinStack();
 * obj->push(x);
 * obj->pop();
 * int param_3 = obj->top();
 * int param_4 = obj->getMin();
 */