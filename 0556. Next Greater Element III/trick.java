class Solution {
    public int nextGreaterElement(int n) {
        List<Integer> list = new ArrayList<>();
        while(n > 0){
            int pop = n % 10;
            list.add(pop);
            n = n / 10;
        }
        Collections.reverse(list);
        Integer[] v = (Integer[]) list.toArray(new Integer[0]);
        
        int len = v.length, index = len - 1;
        while(index >= 1){
            if(v[index] > v[index - 1]){
                break;
            }
            index--;
        }
        if(index == 0){
            return -1;
        }else{
            int a = v[index - 1], next = index;
            for(int i = index; i < len; ++i){
                if(v[i] > v[index - 1]){
                    next = i;
                }
            }
            
            int tmp = v[index - 1];
            v[index - 1] = v[next];
            v[next] = tmp;
            reverse(v, index, len - 1);
            return array2Integer(v);
        }
    }
    
    private void reverse(Integer[] v, int low, int high){
        while(low < high){
            int tmp = v[low];
            v[low] = v[high];
            v[high] = tmp;
            low++;
            high--;
        }
    }
    
    private int array2Integer(Integer[] v){
        int ret = 0;
        for(int i: v){
            if(ret > Integer.MAX_VALUE / 10 || (ret == Integer.MAX_VALUE / 10 && i > 7))
                return -1;
            else
                ret = ret * 10 + i;
        }
        return ret;
    }
}