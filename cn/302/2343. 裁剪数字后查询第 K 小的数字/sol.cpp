class Solution {
public:
    // ["102","473","251","814"]
    vector<int> smallestTrimmedNumbers(vector<string>& v, vector<vector<int>>& queries) {
        int len = v.size();
        vector<vector<char>> token(len);
        
        for(int i = 0; i < len; ++i){
            token[i] = getToken(v[i]);
        }
        
        vector<int> ret;
        int qLen = queries.size();
        for(int i = 0; i < qLen; ++i){
            int k = queries[i][0], trim = queries[i][1];
            vector<pair<string,int>> sum(len);
            for(int j = 0; j < len; ++j){
                // [0, trim] -> sum
                string tmp = "";
                int tokenLen = token[j].size();
                for(int index = tokenLen - trim; index < tokenLen; index++){
                    //tmp = tmp * 10 + token[j][index];
                    tmp += token[j][index];
                }
                //cout << "sum:" << tmp << "," << j << endl;
                sum[j] = pair<string, int>(tmp, j);
            }
            sort(sum.begin(), sum.end(), [ ]( const pair<string, int>& v1, const pair<string, int>& v2 )
            {
                if(v1.first == v2.first)
                    return v1.second < v2.second;
                else
                    return v1.first < v2.first;
            });
            ret.push_back(sum[k - 1].second);
            //cout << "get:" << sum[k - 1].first << "," << sum[k - 1].second << endl;;
        }
        return ret;
    }
    
    vector<char> getToken(string& s){
        int len = s.size();
        vector<char> ret(len);
        for(int i = 0; i < len; ++i){
            ret[i] = s[i];
        }
        return ret;
    }
};