class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 && word.size() != 0) return false;
        row = board.size();col = board[0].size();
        int wordPos = 0;
        
        vector<vector<bool>> visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(dfsFind(board, visited, word, i, j, wordPos))
                    return true;
            }
        }
        return false;
    }
    
    bool dfsFind(vector<vector<char>> board, vector<vector<bool>>& visited, string word, int i, int j, int wordPos){
        if(wordPos == word.size())
            return true;
        if(wordPos > word.size())
            return false;
        if(i < 0 || j < 0 || i > row - 1 || j > col - 1
          || board[i][j] != word[wordPos]
          || visited[i][j])
            return false;
        visited[i][j] = true;
        
        bool ret = dfsFind(board, visited, word, i - 1, j, wordPos + 1)
                    || dfsFind(board, visited, word, i + 1, j, wordPos + 1)
                    || dfsFind(board, visited, word, i, j - 1, wordPos + 1)
                    || dfsFind(board, visited, word, i, j + 1, wordPos + 1);
        visited[i][j] = false;
        return ret;
    }
};