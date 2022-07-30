class Solution {
public:
    int maximumSum(vector<int>& v) {
        int len = v.size();
        map<int, vector<int>> m;
        // vector<int> sum(v.size(), 0);
        for(int i = 0; i < len; ++i){
            int sum = getSum(v[i]);
            // cout << "sum:" << sum << endl;
            if(m.find(sum) == m.end()){
                m[sum] = vector<int>(1, v[i]);
            }else{
                m[sum].push_back(v[i]);
            }
        }
        int ret = -1;
        for(map<int, vector<int>>::iterator it = m.begin(); it != m.end(); it++){
            vector<int>& tmp = it->second;
            sort(tmp.begin(), tmp.end());
            // cout << tmp.size() <<endl;
            if(tmp.size() >= 2){
                ret = max(ret, tmp[tmp.size() - 1] + tmp[tmp.size() - 2]);
            }
        }
        return ret;
    }
    
    int getSum(int i){
        int ret = 0;
        while(i != 0){
            int pop = i % 10;
            ret += pop;
            i = i / 10;
        }
        return ret;
    }
};