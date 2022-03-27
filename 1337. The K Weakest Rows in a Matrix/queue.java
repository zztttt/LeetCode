class Solution {
    public int[] kWeakestRows(int[][] mat, int k) {
        int row = mat.length, col = mat[0].length;
        int[] weight = new int[row];
        for(int i = 0; i < row; ++i){
            int w = 0;
            for(int j = 0; j < col; ++j){
                if(mat[i][j] == 1){
                    w++;
                }else{
                    break;
                }
            }
            weight[i] = w;
        }
        
        PriorityQueue<Pair<Integer, Integer>> queue = new PriorityQueue<>(new Comparator<Pair<Integer, Integer>>(){
            public int compare(Pair<Integer, Integer> a, Pair<Integer, Integer> b){
                if(a.getKey() > b.getKey()){
                    return 1;
                }else if(a.getKey() == b.getKey() && a.getValue() > b.getValue()){
                    return 1;
                }else{
                    return -1;
                }
            }
        });
        
        for(int i = 0; i < row; ++i){
            queue.add(new Pair<Integer, Integer>(weight[i], i));
        }
        
        //System.out.println(queue);
        
        int[] ret = new int[k];
        for(int i = 0; i < k; ++i){
            Pair<Integer, Integer> p = queue.poll();
            //System.out.println(p);
            ret[i] = p.getValue();
        }
        
        return ret;
    }
}