class Solution {
public:
    string multiply(string n1, string n2) {
        if(n1.size() == 0 || n2.size() == 0)
            return {};
        int len1 = n1.size(), len2 = n2.size();

        vector<string> map = Mapper(n1, n2);
        string ret = Reducer(map);

        // skip leading zero
        int start = 0, l = ret.size();
        while(start < l && ret[start] == '0')
            start++;
        ret = ret.substr(start, l - start);
        // special ""
        if(ret == "") ret = "0";

        return ret;
    }

    vector<string> Mapper(string n1, string n2){
        int len1 = n1.size(), len2 = n2.size();
        vector<string> ret;
        for(int i = len2 - 1; i >= 0; --i){
            char c = n2[i];
            string res = mul(n1, c);
            // add
            for(int j = i + 1; j < len2; ++j){
                res = res + '0';
            }
            ret.push_back(res);
        }

        return ret;
    }

    string Reducer(vector<string> v){
        int len = v.size();
        string ret = v[0];
        for(int i = 1; i < len; ++i){
            string s = v[i];
            ret = add(ret, v[i]);
        }

        return  ret;
    }

    string mul(string s, char c){
        int len = s.size(), carry = 0;
        string ret = "";
        for(int i = len - 1; i >= 0; --i){
            char left = s[i];
            int res = (left - '0') * (c - '0') + carry;
            int remain = res % 10;
            carry = res / 10;
            ret = (char)(remain + '0') + ret;
        }
        if(carry != 0){
            ret = (char)(carry + '0') + ret;
        }

        return ret;
    }

    string add(string s1, string s2){
        int len1 = s1.size(), len2 = s2.size(), len = max(len1, len2);
        if(len1 > len2)
            preprocess(s2, len1);
        else if(len1 < len2)
            preprocess(s1, len2);
        string ret = "";
        int carry = 0;
        for(int i = len - 1; i >= 0; --i){
            int res = (s1[i] - '0') + (s2[i] - '0') + carry;
            carry = res / 10;
            int remain = res % 10;
            ret = (char)(remain + '0') + ret;
        }
        if(carry != 0){
            ret = (char)(carry + '0') + ret;
        }
        return ret;
    }

    void preprocess(string& s, int dst){
        int len = s.size();
        for(int i = len; i < dst; ++i){
            s = "0" + s;
        }
    }
};