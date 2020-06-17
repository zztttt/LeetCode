class Solution {
public:
    void solve(vector<vector<char>>& board) {
        if(board.size() == 0 || board[0].size() == 0)
            return;
        int row = board.size(), col = board[0].size();
        
        queue<Node*> q;
        // first col
        for(int i = 0; i < row; ++i){
            q.push(new Node(i, 0));
        }
        // last col
        for(int i = 0; i < row; ++i){
            q.push(new Node(i, col - 1));
        }
        // first row
        for(int i = 1; i < col - 1; ++i){
            q.push(new Node(0, i));
        }
        // last row
        for(int i = 1; i < col - 1; ++i){
            q.push(new Node(row - 1, i));
        }
        
        // bfs
        while(!q.empty()){
            Node* cur =  q.front();
            q.pop();
            
            int curRow = cur->row, curCol = cur->col;
            if(curRow < 0 || curRow > row - 1 || curCol < 0 || curCol > col - 1)
                continue;
            if(board[curRow][curCol] == 'O'){
                board[curRow][curCol] = '#';
                q.push(new Node(curRow - 1, curCol));
                q.push(new Node(curRow + 1, curCol));
                q.push(new Node(curRow, curCol - 1));
                q.push(new Node(curRow, curCol + 1));
            }
        }
        
        //change remained O with X, then recover # with O 
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == 'O')
                    board[i][j] = 'X';
            }
        }
        for(int i = 0; i < row; ++i){
            for(int j = 0; j < col; ++j){
                if(board[i][j] == '#')
                    board[i][j] = 'O';
            }
        }
        return;
    }
    
    class Node{
    public:
        int row, col;
        Node(int r, int c):row(r), col(c){}
    };
};