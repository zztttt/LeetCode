class Solution {
public:
    bool canConstruct(string ransomNote, string magazine) {
        if(magazine.size() == 0 && ransomNote.size() > 0)
            return false;
        int len = ransomNote.size();
        map<char, int> m;
        for(char c: magazine){
            if(m.find(c) == m.end()){
                m[c] = 1;
            }else{
                m[c]++;
            }
        }
        for(char c: ransomNote){
            if(m.find(c) == m.end())
                return false;
            else{
                m[c]--;
                if(m[c] < 0)
                    return false;
            }
        }
        return true;
    }
};