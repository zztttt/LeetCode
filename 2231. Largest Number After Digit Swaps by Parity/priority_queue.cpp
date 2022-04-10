class Solution {
public:
    int largestInteger(int num) {
        string s = to_string(num);
        
        priority_queue<int> evenQueue, oddQueue;
        queue<int> evenPos, oddPos;
        
        int len = s.size();
        for(int i = 0; i < len; ++i){
            int val = s[i] - '0';
            if(val % 2 == 0){
                evenPos.push(i);
                evenQueue.push(val);
            }else{
                oddPos.push(i);
                oddQueue.push(val);
            }
        }
        
        while(!evenQueue.empty()){
            s[evenPos.front()] = evenQueue.top() + '0';
            evenPos.pop(), evenQueue.pop();
        }
        
        while(!oddQueue.empty()){
            s[oddPos.front()] = oddQueue.top() + '0';
            oddPos.pop(), oddQueue.pop();
        }
        //cout << s;
        int ret = stoi(s);
        return ret;
    }
};