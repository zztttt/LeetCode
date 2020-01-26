class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = board.size();
        if(n != 9 ) return false;
        
        vector<set<int>> rows(n);
        vector<set<int>> cols(n);
        vector<set<int>> blocks(n);
        
        for(int i = 0; i < n; i++){
            for(int j = 0; j < n; j++){
                char cur = board[i][j];
                if(cur == '.')
                    continue;

                int k = 3 * (i/3) + j/3;
                
                if(rows[i].find(cur) != rows[i].end()
                  || cols[j].find(cur) != cols[j].end()
                  || blocks[k].find(cur) != blocks[k].end())
                    return false;
                
                rows[i].insert(cur);
                cols[j].insert(cur);
                blocks[k].insert(cur);
            }
        }
        
        return true;
    }
    
};