class Solution {
public:
    void reverseString(vector<char>& v) {
         if(v.size() == 0)
             return;
        int len = v.size(), low = 0, high = len - 1;
        while(low < high){
            char tmp = v[low];
            v[low] = v[high];
            v[high] = tmp;
            low++;
            high--;
        }
    }
};