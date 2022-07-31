class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> pos;
        for(const int& i: asteroids) {
            if(pos.empty()){
                pos.push(i);
                continue;
            }
            
            bool isDestroy = false;
            if(i < 0){
                while(!pos.empty()){
                    int top = pos.top();
                    if(top < 0){
                        break;
                    }
                    if(top < -i){
                        pos.pop();
                    }else if(top == -i){
                        isDestroy = true;
                        pos.pop();
                        break;
                    }else{
                        isDestroy = true;
                        break;
                    }
                }
            }
            if(!isDestroy){
                pos.push(i);
            }
        }

        vector<int> ret;
        while(!pos.empty()){
            ret.push_back(pos.top());
            pos.pop();
        }
        reverse(ret.begin(), ret.end());
        return ret;
    }
};