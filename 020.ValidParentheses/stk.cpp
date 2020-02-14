class Solution {
public:
    bool isValid(string s) {
        if(s.size() == 0)
            return true;
        int len = s.size(), pos = 1;
        stack<char> stk;
        stk.push(s[0]);
        while(pos <= len - 1){
            if(stk.empty()){
                stk.push(s[pos]);
            }else{
                char top = stk.top(), cur = s[pos];
                if(isMatching(top, cur)){
                    stk.pop();
                }else{
                    stk.push(cur);
                }
            }
            pos++;
        }
        //cout << "empty? " << stk.empty() << ", pos:" << pos << endl;
        return stk.empty() && pos == len;
    }

    bool isMatching(char a, char b){
        switch(a){
            case '(': return b == ')';
            case '{': return b == '}';
            case '[': return b == ']';
        }
        return false;
    }
};