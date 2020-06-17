 // iterator version
int rob_iterator(vector<int>& v) {
    if(v.size() == 1) return v[0];
    int len = v.size();
    int ret = dp(v, 0, len - 1);
    return ret;
}

int dp(vector<int> v, int low, int high){
    if(low > high)
        return 0;
    if(low == high)
        return v[low];
    return max(v[low] + dp(v, low + 2, high), 
                dp(v, low + 1, high));
}