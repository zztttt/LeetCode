class Solution {
public:
    vector<int> searchRange(vector<int>& v, int target) {
        int len = v.size();
        int start = findStart(v, target);
        vector<int> ret;
        if(start == -1)
            return vector<int>(2, -1);
        ret.push_back(start);
        int i = start;
        while(i < len && v[i] == target)
            i++;
        i--;
        ret.push_back(i);
        return ret;
    }
    int findStart(vector<int> v, int target){
        int len = v.size(), low = 0, high = len - 1;
        if(len == 0)
            return -1;
        bool isFound = false;
        while(low <= high){
            int mid = (low + high)/2;
            // hit
            if(v[mid] == target){
                isFound = true;
                high = mid - 1;
            }else if(v[mid] > target){
                high = mid - 1;
            }else if(v[mid] < target){
                low = mid + 1;
            }
        }
        return isFound? low:-1;
    }
};