class Solution {
public:
    int row = 0;
    int col = 0;
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
        row = board.size(), col = board[0].size();

        vector<Node> visited;
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == word[0]){
                    if(dfs(board, i, j, word, 0, visited))
                        return true;
                }
            }
        }
        return false;;
    }
    bool dfs(const vector<vector<char>>& board, int i, int j, const string& word, int pos, vector<Node>& visited){
        if(i < 0 || i > row - 1 || j < 0 || j > col - 1)
            return false;
        Node visit = Node(i, j);
        if(find(visited.begin(), visited.end(), visit) != visited.end())
            return false;
        char cur = board[i][j];
        if(pos == word.size() - 1 && word[pos] == cur)
                return true;
        if(word[pos] != cur)
            return false;
        
        visited.push_back(visit);
        bool ret = dfs(board, i + 1, j, word, pos + 1, visited) 
                    || dfs(board, i - 1, j, word, pos + 1, visited) 
                    || dfs(board, i, j + 1, word, pos + 1, visited)
                    || dfs(board, i, j - 1, word, pos + 1, visited);
        visited.pop_back();
        return ret;
    }
};