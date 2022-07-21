class Solution {
public:
    int minOperations(vector<int>& v, vector<int>& vDivide) {
        // for(int i: vDivide){
        //     if(i % 3 != 0){
        //         cout << i << endl;
        //     }
        // }
        // return -1;
        
        sort(v.begin(), v.end());
        set<int> removed;
        
        // int gcd = std::gcd(*max_element(vDivide.begin(),vDivide.end()),
        //                    *min_element(vDivide.begin(),vDivide.end()));
        int gcd = findGCD(vDivide);
        //cout << "gcd:" << gcd << endl;
        int len = v.size(), last = 0;
        for(int i = 0; i < len; ++i){
            if(v[i] == last){
                continue;
            }else{
                // do
                // if(!preJudge(removed, v[i])){
                //     removed.insert(v[i]);
                // }
                if(gcd % v[i] == 0){
                    //cout << "ret. index:" << i << ",val:" << v[i] << endl;
                    return i;
                }
                last = v[i];
            }
        }
        return -1;
    }
    
    bool preJudge(set<int>& removed, int k){
        for(auto it = removed.begin(); it != removed.end(); it++){
            if(k % (*it) == 0){
                return false;
            }
        }
        return true;
    }
    
    int mygcd(int a,int b){
	    if(b==0)
            return a;
	    return gcd(b,a%b);
    }
    
    int findGCD(vector<int> &vec){
        if(vec.size() == 0)
            return 0;
        if(vec.size() == 1)
            return vec[0];
        int first = vec[0];
        for(int i = 1; i < vec.size(); i++){
            int num = mygcd(first, vec[i]);
            if(num == 1)
                return 1;
            else first = num;
        }
        return first;
    }
    
    // bool judge(const vector<int>& vDivide, int k){
    //     int len = vDivide.size();
    //     for(int i = 0; i < len; ++i){
    //         if(vDivide[i] %)
    //     }
    // }
    
};