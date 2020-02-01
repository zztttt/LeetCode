class Solution {
public:
	bool isPalindrome(string s) {
		int len = s.length(), low = 0, high = len - 1;
		if(len == 0) return true;
        
        transform(s.begin(), s.end(), s.begin(), ::tolower);
        
        while(low <= high){
            // skip invalid char
            if(!isValid(s[low])){
                low++;
                continue;
            }
            if(!isValid(s[high])){
                high--;
                continue;
            }
            
            if(!isEqual(s[low], s[high])){
                return false;
            }else{
                low++;
                high--;
            }
        }
        return true;
		
	}
    
    bool isEqual(char a, char b){
        return a == b;
    }
    
    bool isValid(char c){
        return (c >= 'a' && c <= 'z')
            || (c >= 'A' && c <= 'Z')
            || (c >= '0' && c <= '9');
    }
};