class Solution {
public:
    class Node{
    public:
        int i;
        int j;
        Node(int a, int b):i(a), j(b){}
        
        bool operator==(Node a){
            return a.i == i && a.j == j;
        }
    };
    bool exist(vector<vector<char>>& board, string word) {
        if(board.size() == 0 || board[0].size() == 0)
            return false;
        int row = board.size(), col = board[0].size();
        
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                // start
                vector<Node> v;
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, 0, word, v))
                        return true;
                }
            }
        }
        
        return false;
    }
    
    bool dfs(vector<vector<char>>& board, int i, int j, int index, string& word, vector<Node>& visited){
        if(i < 0 || i > board.size() - 1 || j < 0 || j > board[0].size() - 1)
            return false;
        
        if(find(visited.begin(), visited.end(), Node(i, j)) != visited.end())
            return false;
        
        if(index == word.size() - 1 && word[index] == board[i][j])
            return true;
        
        if(board[i][j] != word[index])
            return false;
        
        visited.push_back(Node(i, j));
        bool ret = dfs(board, i + 1, j, index + 1, word, visited)
                || dfs(board, i - 1, j, index + 1, word, visited)
                || dfs(board, i, j + 1, index + 1, word, visited)
                || dfs(board, i, j - 1, index + 1, word, visited);
        visited.pop_back();
        
        return ret;
    }
};