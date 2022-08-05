class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n = 9;
        vector<set<int>> rows(n);
        vector<set<int>> cols(n);
        vector<set<int>> blocks(n);
        
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < n; ++j){
                if(board[i][j] == '.'){
                    continue;
                }
                char c = board[i][j];
                set<int>& row = rows[i];
                set<int>& col = cols[j];
                set<int>& block = blocks[3 * (i / 3) + j / 3];
                
                if(row.find(c) != row.end()
                  || col.find(c) != col.end()
                  || block.find(c) != block.end()){
                    return false;
                }
                row.insert(c);
                col.insert(c);
                block.insert(c);
            }
        }
        return true;
    }
};