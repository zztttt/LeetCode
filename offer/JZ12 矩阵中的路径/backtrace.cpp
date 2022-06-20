class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param matrix char字符型vector<vector<>> 
     * @param word string字符串 
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return false;
        }
        int row = matrix.size(), col = matrix[0].size();
        set<pair<int,int>> visited;
        for(int i = 0; i < row; ++i) {
            for(int j = 0; j < col; ++j) {
                if(word[0] == matrix[i][j]){
                    if(backtrace(matrix, word, 0, i, j, visited)){
                        return true;
                    }
                }
            }
        }
        return false;
    }
    
    bool backtrace(const vector<vector<char>>& matrix, const string& word, int index, int i, int j, set<pair<int,int>>& visited){
        //cout << "i:" << i << ",j:" << j << endl;
        int row = matrix.size(), col = matrix[0].size();
        if(i < 0 || i > row - 1 || j < 0 || j > col - 1){
            return false;
        }
        
        if(index > word.size() - 1){
            return false;
        }
        
        if(visited.find({i, j}) != visited.end()){
            return false;
        }
        
        if(word[index] != matrix[i][j]){
            return false;
        }
        
        if(index == word.size() - 1 && word[index] == matrix[i][j]){
            return true;
        }
        
        bool ret = false;
        visited.insert({i, j});
        ret = ret 
            || backtrace(matrix, word, index + 1, i + 1, j, visited)
            || backtrace(matrix, word, index + 1, i - 1, j, visited)
            || backtrace(matrix, word, index + 1, i, j + 1, visited)
            || backtrace(matrix, word, index + 1, i, j - 1, visited);
        visited.erase({i, j});
        return ret;
    }
};