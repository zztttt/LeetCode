class Solution {
    public int minDominoRotations(int[] tops, int[] bottoms) {
        int[] record = new int[7];
        int len = tops.length;
        for(int i = 0; i < len; ++i){
            if(tops[i] == bottoms[i]){
                record[tops[i]]++;
            }else{
                record[tops[i]]++;
                record[bottoms[i]]++;
            }
        }
        
        int ret = len + 1;
        for(int i = 1; i <= 6; ++i){
            //System.out.println(record[i]);
            if(record[i] == len){
                int topCount = 0;
                for(int top: tops){
                    if(top == i)
                        topCount++;
                }
                
                int bottomCount = 0;
                for(int bot: bottoms){
                    if(bot == i)
                        bottomCount++;
                }
                ret = Math.min(ret, Math.min(topCount, len - topCount));
                ret = Math.min(ret, Math.min(bottomCount, len - bottomCount));
            }
        }
        
        return ret == len + 1? -1: ret;
    }
}