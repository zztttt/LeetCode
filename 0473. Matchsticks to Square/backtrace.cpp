class Solution {
public:
    bool makesquare(vector<int>& sticks) {
        int len = sticks.size(), sum = 0;
        for(const int& i: sticks){
            sum += i;
        }
        if(sum % 4 != 0){
            return false;
        }
        sort(sticks.begin(), sticks.end(), greater<int>());
        int edge = sum / 4;
        vector<int> edges(4, edge);
        return dfs(sticks, edges, 0);
    }
    
    bool dfs(const vector<int>& sticks, vector<int>& edges, int index){
        if(index == sticks.size()){
            return edges[0] == 0 && edges[1] == 0 && edges[2] == 0 && edges[3] == 0;
        }
        int cur = sticks[index];

        for(int j = 0; j < 4; ++j){
            if(edges[j] >= cur){
                edges[j] -= cur;
                if(dfs(sticks, edges, index + 1)){
                    return true;
                }
                edges[j] += cur;
            }
        }
        return false;
    }
};