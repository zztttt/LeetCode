class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return "";
        int len = s.size();
        vector<string> words;
        
        int i = 0;
        while(i < len){
            if(s[i] == ' ')
                i++;
            else
                break;
        }
        int start = i;
        
        while(i < len){
            if(isCharactor(s[i])){
                i++;
            }else{
                string tmp = s.substr(start, i - start);
                cout << "word:" << tmp << endl;
                words.push_back(tmp);
                while(i < len){
                    if(s[i] == ' ')
                        i++;
                    else
                        break;
                }
                start = i;
            }
        }
        if(i > start)
            words.push_back(s.substr(start, i - start));
        
        string ret = "";
        for(vector<string>::reverse_iterator it = words.rbegin(); it != words.rend(); it++){
            ret = ret + *it + " ";
        }
        return ret.substr(0, ret.size() - 1);
    }
    
    bool isCharactor(const char& c){
        return (c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z') || (c >= '0' && c <= '9');
    }
};