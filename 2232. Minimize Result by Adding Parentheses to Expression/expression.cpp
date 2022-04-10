class Solution {
public:
    string minimizeResult(string exp) {
        int len = exp.size(), plusPos = 0, minVal = INT_MAX;
        string ret;
        vector<int> left, right;
        bool found = false;
        for(int i = 0; i < len; ++i){
            if(exp[i] == '+'){
                found = true;
                continue;
            }
            if(found){
                right.push_back(exp[i] - '0');
            }else{
                left.push_back(exp[i] - '0');
            }
        }
        //printV(left);
        //printV(right);
        
        int leftLen = left.size(), rightLen = right.size();
        for(int i = 0; i < leftLen; ++i){
            for(int j = 1; j < rightLen + 1; ++j){
                pair<int, int> leftVal = split(left, i);
                pair<int, int> rightVal = split(right, j);
                int a = leftVal.first == 0 ? 1: leftVal.first;
                int b = leftVal.second + rightVal.first;
                int c = rightVal.second == 0? 1: rightVal.second;
                int val = a * b * c;
                // cout << leftVal.first << "," << leftVal.second << endl;
                // cout << rightVal.first << "," << rightVal.second << endl;
                // cout << "a:" << a << ", b:" << b << ", c:" << c << endl;
                // cout << "val:" << val << endl;
                if(val < minVal){
                    ret = getRet(left, i, right, j);
                    minVal = val;
                }
            }
        }
        return ret;
    }
    
    pair<int, int> split(const vector<int>& v, int index){
        //cout << "split:" << index << endl;
        int left = 0, right = 0, len = v.size();
        for(int i = 0; i < index; ++i){
            left += (v[i] * pow(10, (index - i - 1)));
        }
        for(int i = index; i < len; ++i){
            right += (v[i] * pow(10, (len - 1 - i)));
        }
        return pair<int, int>(left, right);
    }
    
    string getRet(const vector<int>& left, int p1, const vector<int>& right, int p2){
        string ret = "";
        int len1 = left.size(), len2 = right.size();
        for(int i = 0; i < len1; ++i){
            if(i == p1){
                ret += '(';
            }
            ret += (left[i] + '0');
        }
        ret += '+';
        for(int i = 0; i < len2; ++i){
            if(i == p2){
                ret += ')';
            }
            ret += (right[i] + '0');
        }
        if(p2 == len2){
            ret += ')';
        }
        return ret;
    }
    
    void printV(const vector<int>& v){
        for(int i: v){
            cout << i << ",";
        }
        cout << endl;
    }
};