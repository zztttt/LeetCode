class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        int len = s.size(), ret = 0, curNum = 0, sign = 1;//sign is to record the last op type
        stack<int> stk;
        for(int i = 0; i < len; ++i){
            char c = s[i];
            switch(c){
                case ' ':
                    break;
                case '0':case '1':case '2':case '3':case '4':
                case '5':case '6':case '7':case '8':case '9':
                    curNum = curNum * 10 + (int)(c - '0');
                    break;
                case '+':
                    ret = ret + sign * curNum;
                    curNum = 0;
                    sign = 1;
                    break;
                case '-':
                    ret = ret + sign * curNum;
                    curNum = 0;
                    sign = -1;
                    break;
                case '(':
                    // record the last num, and the the state to default
                    stk.push(ret);
                    stk.push(sign);
                    ret = 0;
                    sign = 1;
                    curNum = 0;
                    break;
                case ')':
                    ret = ret + sign * curNum;
                    curNum = 0;
                    if(!stk.empty()){
                        int lastSign = stk.top();
                        stk.pop();
                        int lastVal = stk.top();
                        stk.pop();
                        ret = lastVal + lastSign * ret;
                    }
                    break;
                default:
                    cout << "assert:" << c << endl;
                    assert(0);
            }
        }
        if(curNum != 0)
            ret = ret + sign * curNum;
        
        return ret;
    }
};