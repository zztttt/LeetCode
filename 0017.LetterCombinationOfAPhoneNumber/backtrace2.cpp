class Solution {
public:
    vector<string> ret;
    vector<string> letterCombinations(string digits) {
        int len = digits.size();
        if(len == 0)
            return {};
        vector<vector<char>> v(len);
        for(int i = 0; i < len; ++i){
            v[i] = mapping(digits[i]);
        }
        vector<char> buffer;
        backtrace(v, 0, buffer);
        return ret;
    }
    
    void backtrace(const vector<vector<char>>& v, int index, vector<char>& buffer){
        int len = v.size();
        if(buffer.size() == len){
            ret.push_back(string(buffer.begin(), buffer.end()));
            return;
        }
        
        const vector<char>& cur = v[index];
        for(const char& c: cur){
            buffer.push_back(c);
            backtrace(v, index + 1, buffer);
            buffer.pop_back();
        }
    }
    
    vector<char> mapping(const char& c){
        switch(c){
            case '2': return {'a', 'b', 'c'};
            case '3': return {'d', 'e', 'f'};
            case '4': return {'g', 'h', 'i'};
            case '5': return {'j', 'k', 'l'};
            case '6': return {'m', 'n', 'o'};
            case '7': return {'p', 'q', 'r', 's'};
            case '8': return {'t', 'u', 'v'};
            case '9': return {'w', 'x', 'y', 'z'};
        }
        return {};
    }
};