class RandomizedSet {
public:
    vector<int> values;
    unordered_set<int> filter;
    RandomizedSet() {
        
    }
    
    bool insert(int val) {
        if(filter.find(val) != filter.end())
            return false;
        filter.insert(val);
        values.push_back(val);
        return true;
    }
    
    bool remove(int val) {
        unordered_set<int>::iterator v = filter.find(val);
        vector<int>::iterator it = find(values.begin(), values.end(), val);
        if( v == filter.end())
            return false;
        values.erase(it);
        filter.erase(v);
        return true;
    }
    
    int getRandom() {
        int index = rand() % values.size();
        return values[index];
    }
};

/**
 * Your RandomizedSet object will be instantiated and called as such:
 * RandomizedSet* obj = new RandomizedSet();
 * bool param_1 = obj->insert(val);
 * bool param_2 = obj->remove(val);
 * int param_3 = obj->getRandom();
 */