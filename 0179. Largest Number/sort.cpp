class Solution {
public:
    string largestNumber(vector<int>& v) {
        if(v.size() == 0)
            return "";
        vector<string> s;
        for(int i: v){
            s.push_back(to_string(i));
        }
        sort(s.begin(), s.end(), cmp);
        // special case : 00...0
        if(s[0] == "0")
            return "0";
        string ret = "";
        for(string tmp: s){
            ret.append(tmp);
        }
        return ret;
    }
    
    static bool cmp(string a, string b){
        // I don't know why it return false ,but if I return true, it will terminate with throwing 'std::length_error'
        if(a == "0" && b == "0")
            return false;
        string sum1 = a + b, sum2 = b + a;
        int ret = sum1.compare(sum2);
        if(ret >= 0)
            return true; 
        else
            return false;
    }
};