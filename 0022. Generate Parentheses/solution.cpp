class Solution {
public:
    int max;
    vector<string> generateParenthesis(int n) {
        max = n;
        vector<string> ret = vector<string>();
        string cur = "";
        backTrace(ret, cur, 0, 0);
        return ret;
    }
    
    void backTrace(vector<string>& ret, string cur, int numOfLeft, int numOfRight){
        if(cur.size() == max * 2){
            ret.push_back(cur);
            return;
        }
        
        if(numOfLeft < max){
            backTrace(ret, cur+"(", numOfLeft+1, numOfRight);
        }
        if(numOfRight < numOfLeft){
            backTrace(ret, cur+")", numOfLeft, numOfRight+1);
        }
    }
};