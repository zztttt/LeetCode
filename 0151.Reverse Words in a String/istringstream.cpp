class Solution {
public:
    string reverseWords(string s) {
        reverse(s);
        return s;
    }
    void reverse(string &s) {
        istringstream is(s);
        string word;
        is >> s; // first word
        while(is >> word){
            s = word + " " + s;
        }
    }
};