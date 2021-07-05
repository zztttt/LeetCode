class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<int> ret;
        int len = arr.size(), index = -1;
        for(int i = 0; i < len - 1; ++i){
            if(arr[i] <= x && arr[i + 1] > x){
                index = i;
                break;
            }
        }
        if(index != -1){
            int count = 0, leftPos = index, rightPos = index + 1;
            while(count < k && leftPos >= 0 && rightPos <= len - 1){
                int left = arr[leftPos], right = arr[rightPos];
                // left is closer
                if(x - left <= right - x){
                    ret.push_back(left);
                    leftPos--;
                }else{
                    ret.push_back(right);
                    rightPos++;
                }
                count++;
            }
            while(count < k){
                if(leftPos == -1){
                    ret.push_back(arr[rightPos++]);
                }else{
                    ret.push_back(arr[leftPos--]);
                }
                count++;
            }
        }else{
            if(arr[0] >= x){
                cout << "case 1" << endl;
                ret = vector<int>(arr.begin(), arr.begin() + k);
            }
            else if(arr[len - 1] <= x){
                cout << "case 2" << endl;
                ret = vector<int>(arr.begin() + len - k, arr.end());
            }
        }
        sort(ret.begin(), ret.end());
        return ret;
    }
};