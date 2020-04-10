class MinStack {
public:
    /** initialize your data structure here. */
    vector<int> data;
    vector<int> minV;
    int size = 0;
    MinStack() {
    
    }
    
    void push(int x) {
        int curMin = x;
        if(size != 0){
            int top = minV.back();
            curMin = min(curMin, top);
        }
        data.push_back(x);
        minV.push_back(curMin);
        size++;
    }
    
    void pop() {
        data.pop_back();
        minV.pop_back();
        size--;
    }
    
    int top() {
        return data.back();
    }
    
    int getMin() {
        return minV.back();
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