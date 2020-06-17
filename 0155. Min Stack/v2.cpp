class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int> m;
    MinStack() {
        
    }
    
    void push(int x) {
        data.push_back(x);
        if(!m.empty()){
            int last = m.back();
            x = min(x, last);
        }
        m.push_back(x);
    }
    
    void pop() {
        data.pop_back();
        m.pop_back();
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return m.back();
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