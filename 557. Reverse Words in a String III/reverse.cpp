class Solution {
public:
    string reverseWords(string s) {
        if(s.size() == 0)
            return {};
        int len = s.size(), start = 0;
        for(int i = 0; i < len && start < len; ++i){
            if(s[i] != ' ' && i != len - 1)
                continue;
            int low = start, high = i - 1;
            // last case
            if(i == len - 1)
                high = i;
            // reverse 
            reverse(s, low, high);
            // update new start
            start = i + 1;
        }

        return s;
    }

    void reverse(string& s, int low, int high){
        while(low < high){
            char tmp = s[low];
            s[low] = s[high];
            s[high] = tmp;
            low++;
            high--;
        }
    }
};