class FirstUnique {
public:
    vector<int> uniques;
    map<int, int> m;
    FirstUnique(vector<int>& v) {
        for(int i: v){
            add(i);
        }
    }
    
    int showFirstUnique() {
        for(int i: uniques){
            map<int, int>::iterator it = m.find(i);
            if(it != m.end() && it->second == 1){
                return i;
            }
        }
        return -1;
    }
    
    void add(int i) {
        map<int, int>::iterator it = m.find(i);
        if(it == m.end()){
            // unique
            uniques.push_back(i);
            m[i] = 1;
        }else{
            // duplicate
            m[i]++;
        }
    }
};

/**
 * Your FirstUnique object will be instantiated and called as such:
 * FirstUnique* obj = new FirstUnique(nums);
 * int param_1 = obj->showFirstUnique();
 * obj->add(value);
 */