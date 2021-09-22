class Solution {
public:
    int ret = 0;
    int maxLength(vector<string>& arr) {
        unordered_map<char, int> exists;
        backtrace(exists, arr, 0);
        return ret;
    }
    void backtrace(unordered_map<char, int>& exists, vector<string>& arr, int level){
        //print(exists, level);
        for(unordered_map<char, int>::iterator it = exists.begin(); it != exists.end(); it++){
            if(it->second > 1){
                //cout << "duplicate:" << *it << endl;
                return;
            }    
        }
        if(exists.size() > ret){
            ret = exists.size();
        }
        
        int len = arr.size();
        for(int i = level; i < len; ++i){
            string s = arr[i];
            for(const char& c: s){
                if(exists.find(c) != exists.end())
                    exists[c]++;
                else
                    exists[c] = 1;
            }
            
            backtrace(exists, arr, i + 1);
            
            for(const char& c: s){
                if(exists[c] == 1)
                    exists.erase(c);
                else
                    exists[c]--;
            }
        }
    }
};