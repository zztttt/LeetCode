class Solution {
public:
    int row, col;
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 && word.size() != 0) 
            return false;
        row = board.size();col = board[0].size();
        int wordPos = 0;
        
        //vector<vector<bool>> visited = vector<vector<bool>>(row, vector<bool>(col, false));
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == word[0] && dfsFind(board, word, i, j, 0))
                    return true;
            }
        }
        return false;
    }
    
    bool dfsFind(vector<vector<char>>& board, string word, int i, int j, int wordPos){
        if(wordPos == word.size())
            return true;
        if(i < 0 || j < 0 || i > row - 1 || j > col - 1
          || board[i][j] != word[wordPos])
            return false;
        
        char tmp = board[i][j];
        board[i][j] = ' ';
        bool ret = dfsFind(board, word, i - 1, j, wordPos + 1)
                    || dfsFind(board, word, i + 1, j, wordPos + 1)
                    || dfsFind(board, word, i, j - 1, wordPos + 1)
                    || dfsFind(board, word, i, j + 1, wordPos + 1);
        board[i][j] = tmp;
        return ret;
    }
};