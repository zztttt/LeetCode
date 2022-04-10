class Solution {
public:
    int calPoints(vector<string>& ops) {
        stack<int> record;
        for(const string& s: ops){
            if(s == "C"){
                record.pop();
            }else if(s == "D"){
                int top = record.top();
                record.push(2 * top);
                //cout << 2*top << endl;
            }else if(s == "+"){
                int top1 = record.top();
                record.pop();
                int top2 = record.top();
                record.push(top1);
                record.push(top1 + top2);
                //cout << top1 + top2 << endl;
            }else{
                bool isNeg = false;
                string tmp = s;
                if(s.size() > 0 && s[0] == '-'){
                    isNeg = true;
                    tmp = s.substr(1, s.size() - 1);
                }
                int num = atoi(tmp.c_str());
                record.push(isNeg? -1 * num : num);
                //cout << (isNeg? -1 * num : num) << endl;
            }
        }
        int ret = 0;
        while(!record.empty()){
            ret += record.top();
            record.pop();
        }
        return ret;
    }
};