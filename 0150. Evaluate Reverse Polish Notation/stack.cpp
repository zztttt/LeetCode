class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        int len = tokens.size();
        if(len == 0) return 0;
        stack<string> stk;
        // token pos in tokens
        int pos = 1;
        stk.push(tokens[0]);
        while(!stk.empty()){
            string tmp = stk.top();
            if(stk.size() == 1 && pos == len)
                return stoi(tmp);
            if(isOperator(tmp)){
                stk.pop();
                string right = stk.top();
                stk.pop();
                string left = stk.top();
                stk.pop();
                string res = calculate(left, right, tmp[0]);
                stk.push(res);
            }else{
                stk.push(tokens[pos++]);
            }
        }
        assert(0);
    }
    
    bool isOperator(string s){
        return (s == "+")||(s == "-")||(s == "*")||(s == "/");
    }
    
    string calculate(string left, string right, char op){
        int a = stoi(left), b = stoi(right);
        int res;
        switch(op){
            case '+':
                res = a + b;
                break;
            case '-':
                res = a - b;
                break;
            case '*':
                res = a * b;
                break;
            case '/':
                res = a / b;
                break;
        }
        return to_string(res);
    }
};