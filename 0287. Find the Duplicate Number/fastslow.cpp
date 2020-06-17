class Solution {
public:
    int findDuplicate(vector<int>& v) {
        if(v.size() == 0)
            return 0;
        int len = v.size(), last = v[0];
        // 2, 1, 2, 3, 4
        int slow = v[0], fast = v[v[0]];
        // find common node
        while(slow != fast){
            slow = v[slow];
            fast = v[v[fast]];
        }
        // begin from the start of cycle
        slow = 0;
        while(slow != fast){
            slow = v[slow];
            fast = v[fast];
        }
        return slow;
    }
};