class Solution {
public:
    int row;
    int col;
    vector<string> findWords(vector<vector<char>>& board, vector<string>& words) {
        if(board.size() == 0 || board[0].size() == 0)
            return {};
        vector<string> ret;
        row = board.size(); col = board[0].size();
        for(string word: words){
            //cout << "word:" << word << endl;
            reverse(word.begin(), word.end());
            for(int i = 0; i < row; ++i){
                for(int j = 0; j < col; ++j){
                    vector<vector<bool>> visited(row, vector<bool>(col, false));
                    if(board[i][j] == word[0] && dfs(board, word, i, j, 0, visited)){
                        reverse(word.begin(), word.end());
                        ret.push_back(word);
                        goto FINISH;
                    }       
                }
            }
            FINISH:;
        }
        return ret;
    }
    bool dfs(const vector<vector<char>>& board, const string& word, int i, int j, int index, vector<vector<bool>>& visited){
        if(i < 0 || i > row - 1 || j < 0 || j > col - 1)
            return false;
        if(word[index] != board[i][j] || visited[i][j])
            return false;
        if(index == word.size() - 1 && word[index] == board[i][j]){
            //cout << "true:" << word << ", board[i][j]:" << board[i][j] << ", index:" << index << endl;
            return true;
        }
        
        visited[i][j] = true;
        if(dfs(board, word, i + 1, j, index + 1, visited)
            || dfs(board, word, i - 1, j, index + 1, visited)
            || dfs(board, word, i, j + 1, index + 1, visited)
            || dfs(board, word, i, j - 1, index + 1, visited))
            return true;
        visited[i][j] = false;
        return false;;
    }
};