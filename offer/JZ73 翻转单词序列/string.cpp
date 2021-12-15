class Solution {
public:
//     bool isValid(char c){
//         return (c >= 0 && c <= 9)
//             || (c >= 'a' && c <= 'z')
//             || (c >= 'A' && c <= 'Z');
//     }
    void inPlaceReverse(string& s, int low, int high){
        while(low <= high){
            char tmp = s[low];
            s[low] = s[high];
            s[high] = tmp;
            low++;high--;
        }
    }
    
    string ReverseSentence(string s) {
        reverse(s.begin(), s.end());
        //cout << s << endl;
        int len = s.size(), low = 0, high = len - 1;
        int index = 0, last = 0;
        while(index < len){
            if(s[index] == ' '){
                if(index == last){
                    index++;
                    last++;
                    continue;
                }
                inPlaceReverse(s, last, index - 1);
                last = index + 1;
            }
            index++;
        }
        if(index != last)
            inPlaceReverse(s, last, index - 1);
        return s;
    }
};