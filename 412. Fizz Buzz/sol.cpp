class Solution {
public:
    vector<string> fizzBuzz(int n) {
        string three = "Fizz", five = "Buzz";
        vector<string> ret;
        
        for(int i = 1; i <= n; ++i){
            string tmp = "";
            bool isThree = i % 3 == 0, isFive = i % 5 == 0;
            if(!isThree && !isFive)
                tmp = to_string(i);
            if(isThree)
                tmp = tmp + three;
            if(isFive)
                tmp = tmp + five;
            
            ret.push_back(tmp);
        }
        return ret;
    }
};