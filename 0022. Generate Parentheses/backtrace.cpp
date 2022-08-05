class Solution {
public:
    vector<string> ret;
    vector<string> generateParenthesis(int n) {
        vector<char> buffer;
        backtrace(n, 0, 0, buffer);
        return ret;
    }
    
    void backtrace(int n, int leftN, int rightN, vector<char>& buffer){
        if(leftN == n && rightN == n){
            ret.push_back(string(buffer.begin(), buffer.end()));
            return;
        }
        if(leftN < n){
            buffer.push_back('(');
            backtrace(n, leftN + 1, rightN, buffer);
            buffer.pop_back();
        }
        if(rightN < leftN){
            buffer.push_back(')');
            backtrace(n, leftN, rightN + 1, buffer);
            buffer.pop_back();
        }
    }
};