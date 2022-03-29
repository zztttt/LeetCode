class Solution {
    public boolean search(int[] v, int target) {
        int len = v.length, low = 0, high = len - 1;
        while(low <= high){
            System.out.println(low + "," + high);
            while(low < high && v[low] == v[low + 1]){
                low++;
            }
            while(low < high && v[high] == v[high - 1]){
                high--;
            }
            int mid = (low + high) / 2, cur = v[mid];
            if(cur == target)
                return true;
            else if(cur < target){
                if(cur >= v[low]){
                    low = mid + 1;
                }else{
                    if(v[high] >= target){
                        low = mid + 1;
                    }else{
                        high = mid - 1;
                    }
                }
            }else{// cur > target
                if(cur <= v[high]){
                    high = mid - 1;
                }else{
                    if(target >= v[low]){
                        high = mid - 1;
                    }else{
                        low = mid + 1;
                    }
                }
            }
        }
        return false;
        
    }
}