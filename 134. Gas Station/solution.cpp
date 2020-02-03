class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int index = gas.size();
        if(index == 0) return -1;
        
        // greedy
        int curGas = 0, totalGas = 0, start = 0;
        for(int i = 0; i < index; ++i){
            curGas += gas[i] - cost[i];
            totalGas += gas[i] - cost[i];
            if(curGas < 0){
                start = i + 1;
                curGas = 0;
            }
        }
        return (totalGas >= 0)? start:-1;
    }
};