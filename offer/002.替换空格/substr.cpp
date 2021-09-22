class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param s string字符串 
     * @return string字符串
     */
    string replaceSpace(string s) {
        // write code here
        vector<string> tokens;
        string ret = "";
        int len = s.size(), start = 0;
        for(int i = 0; i < len; ++i){
            if(s[i] == ' '){
                string tmp = s.substr(start, i - start);
                tokens.push_back(tmp);
                //cout << "tmp size:" << tmp.size() << tmp << endl;
                start = i + 1;
            }
        }
        tokens.push_back(s.substr(start, len - start));
        
        len = tokens.size();
        for(int i = 0 ; i < len - 1; ++i){
            ret = ret +  tokens[i] + "%20";
        }
        ret += tokens.back();
        return ret;
    }
};