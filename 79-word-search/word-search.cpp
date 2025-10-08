class Solution {
public:
int n,m;
     // set<pair<int,int>>path;
      vector<vector<bool>> visited;
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
            visited = vector<vector<bool>>(n, vector<bool>(m, false));

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(dfs(board,word,i,j,0)){
                    return true;
                }
            }
        }
        return false;
        
    }

    bool dfs(vector<vector<char>>& board, string word,int r,int c,int i){

        if(i==word.size()){
            return true;
        }

        if(c<0 || c>=m||r<0||r>=n || board[r][c]!=word[i]  ||visited[r][c] ){
            return false ;
        }

    

          visited[r][c] = true;
        bool res = dfs(board, word, r + 1, c, i + 1) ||
                   dfs(board, word, r - 1, c, i + 1) ||
                   dfs(board, word, r, c + 1, i + 1) ||
                   dfs(board, word, r, c - 1, i + 1);
        visited[r][c] = false;

        return res;

    }
};
