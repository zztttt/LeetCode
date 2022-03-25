class Solution {
    class Info {
        private int a;
        private int b;
        private int saving;
        public Info(int a, int b){
            this.a = a;
            this.b = b;
            this.saving = b - a;
        }
        public String toString(){
            return String.valueOf(saving);
        }
    }
    class InfoComparator implements Comparator<Info>{
        @Override
        public int compare(Info a, Info b){
            if(a.saving <= b.saving){
                return 1;
            }else{
                return -1;
            }
        }
    }
    public int twoCitySchedCost(int[][] costs) {
        List<Info> infos = new ArrayList<>();
        for(int[] i: costs){
            infos.add(new Info(i[0], i[1]));
        }
        infos.sort(new InfoComparator());
        //System.out.println(infos);
        int ret = 0, n = costs.length / 2;
        for(int i = 0; i < n; ++i){
            ret += infos.get(i).a;
            ret += infos.get(i + n).b;
        }
        
        return ret;
    }
}