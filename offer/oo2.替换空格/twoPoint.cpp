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
        int blankCount = 0;
        for(char c:s){
            if(c == ' ')
                blankCount++;
        }
        int oldLen = s.size(), newLen = s.size() + blankCount * 2;
        char temp[4] = "%20";
        char str[oldLen + 1];
        char ret[newLen + 1];
        s.copy(str, s.size());
        s.copy(ret, s.size());
        str[oldLen] = '\0';
        ret[newLen] = '\0';
        
        int p2 = newLen - 1, p1 = s.size() - 1;
        while(p1 >= 0){
            char c = s[p1];
            //cout << "cur: " << c << endl;
            if(c != ' '){
                ret[p2] = c;
                p2--;
            }else{
                p2 = p2 - 2;
                memcpy(&ret[p2], temp, 3);
                p2 = p2 - 1;
            }
            p1--;
        }
        return string(ret);
    }
};