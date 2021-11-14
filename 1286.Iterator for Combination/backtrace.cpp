class CombinationIterator {
private:
    int index = 0;
    vector<string> combinations;
    void backtrace(const string& characters, int combinationLength, int start, vector<char>& visited){
        if(visited.size() == combinationLength){
            combinations.push_back(string(visited.begin(), visited.end()));
            return;
        }
        int len = characters.size();
        for(int i = start; i < len; ++i){
            char cur = characters[i];
            if(find(visited.begin(), visited.end(), cur) == visited.end()){
                visited.push_back(cur);
                backtrace(characters, combinationLength, i + 1, visited);
                visited.pop_back();
            }
        }
    }
public:
    CombinationIterator(string characters, int combinationLength) {
        vector<char> visited = vector<char>();
        backtrace(characters, combinationLength, 0, visited);
        // copy(combinations.begin(),combinations.end(),ostream_iterator<string>(cout," "));
        // cout << endl;
    }
    
    string next() {
        if(hasNext())
            return combinations[index++];
        assert(false);
    }
    
    bool hasNext() {
        if(index < combinations.size())
            return true;
        return false;
    }
};

/**
 * Your CombinationIterator object will be instantiated and called as such:
 * CombinationIterator* obj = new CombinationIterator(characters, combinationLength);
 * string param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */