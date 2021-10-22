class Solution {
public:
    class more{
    public:
        bool operator()(const pair<char, int>& a, const pair<char, int>& b){
            return a.second < b.second;
        }
    };
    string frequencySort(string s) {
        priority_queue<pair<char, int>, vector<pair<char, int>>, more> frequency;
        map<char, int> m;
        for(const char& c: s){
            if(m.find(c) != m.end())
                m[c]++;
            else
                m[c] = 1;
        }
        for(map<char, int>::iterator it = m.begin(); it != m.end(); ++it){
            frequency.push(*it);
        }

        char *chars = new char[s.size() + 1];
        int index = 0;
        while(!frequency.empty()){
            const pair<char, int>& p = frequency.top();
            for(int i = 0; i < p.second; ++i){
                chars[index++] = p.first;
            }
            frequency.pop();
        }
        chars[s.size()] = '\0';
        return string(chars);
        
    }
};