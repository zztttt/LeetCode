class Solution {
public:
    int calculate(string s) {
        if(s.size() == 0)
            return 0;
        s = s + "+"; // for final commit
        //cout << "s:" << s << endl;
        int len = s.size(), preNum = 0, curNum = 0, ret = 0;
        char lastOp = '+';
        for(int i = 0; i < len; ++i){
            char cur = s[i];
            if(cur == ' ')
                continue;
            if(isDigit(cur)){
                curNum = curNum * 10 + (int)(cur - '0');
            }else if(cur == '+' || cur == '-'){
                if(lastOp == '+'){
                    ret = ret + preNum + curNum;
                }else if(lastOp == '-'){
                    ret = ret + preNum - curNum;
                }else if(lastOp == '*'){
                    ret = ret + preNum * curNum;
                }else if(lastOp == '/'){
                    ret = ret + preNum / curNum;
                }
                curNum = 0;
                preNum = 0;
                lastOp = cur;
            }else if(cur == '*' || cur == '/'){
                if(lastOp == '+'){
                    preNum = curNum;
                }
                else if(lastOp == '-'){
                    preNum = -curNum;
                }else if(lastOp == '*'){
                    preNum = preNum * curNum;
                }else if(lastOp == '/'){
                    preNum = preNum / curNum;
                }
                curNum = 0;
                lastOp = cur;
            }
            
            //cout << "cur:" << cur << endl;
            //cout << "preNum:" << preNum << ", curNum:" << curNum << ", lastOp:" << lastOp <<endl;
        }
        return ret;
    }
    
    bool isDigit(char c){
        return c >= '0' && c <= '9';
    }
};