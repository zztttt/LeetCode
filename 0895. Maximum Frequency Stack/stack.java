class FreqStack {
    private Map<Integer, Integer> freq = new HashMap<>();
    private Map<Integer, Stack<Integer>> freqVal = new HashMap<>();
    private int maxFreq = 0;

    public FreqStack() {
        
    }
    
    public void push(int val) {
        int f = freq.getOrDefault(val, 0) + 1;
        freq.put(val, f);
        
        if(f > maxFreq){
            maxFreq = f;
        }
        
        freqVal.computeIfAbsent(f, x -> new Stack<>()).push(val);
    }
    
    public int pop() {
        int ret = freqVal.get(maxFreq).pop();
        freq.put(ret, freq.get(ret) - 1);
        
        if(freq.get(ret) == 0){
            freq.remove(ret);
        }
        
        if(freqVal.get(maxFreq).size() == 0){
            freqVal.remove(maxFreq);
            maxFreq--;
        }
        
        return ret;
    }
}

/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack obj = new FreqStack();
 * obj.push(val);
 * int param_2 = obj.pop();
 */