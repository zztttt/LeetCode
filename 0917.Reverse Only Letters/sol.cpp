class Solution {
public:
    string reverseOnlyLetters(string s) {
        int len = s.size();
        vector<bool> bitmap(len, false);
        queue<char> queue;
        for(int i = 0; i < len; ++i){
            char c = s[i];
            if(isCharacter(c)){
                bitmap[i] = true;
            }else{
                queue.push(c);
            }
        }

        char *p = new char[len];
        int pos = 0;
        for(int i = len - 1; i >= 0; --i){
            char c = s[i];
            if(isCharacter(c)){
                while(!bitmap[pos] && pos < len){
                    p[pos] = queue.front();
                    queue.pop();
                    pos++;
                }
                p[pos++] = c;
            }
        }
        while(queue.size() > 0){
            p[pos++] = queue.front();
            queue.pop();
        }
        return string(p, len);
    }
    bool isCharacter(char c){
        return (c >= 0x41 && c <= 0x5a) || (c >= 0x61 && c <= 0x7a);
    }
};