class Solution
{
public:
    void push(int node) {
        stack1.push(node);
    }

    int pop() {
        while(!stack1.empty()){
            int val = stack1.top();
            stack2.push(val);
            stack1.pop();
        }
        int ret = stack2.top();
        stack2.pop();
        while(!stack2.empty()){
            stack1.push(stack2.top());
            stack2.pop();
        }
        return ret;
    }

private:
    stack<int> stack1;
    stack<int> stack2;
};