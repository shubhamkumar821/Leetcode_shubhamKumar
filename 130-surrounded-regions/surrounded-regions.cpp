class Solution {
public:
    void solve(vector<vector<char>>& board) {
        int row=board.size();
        int col=board[0].size();
        for(int i=0;i<row;i++){
            if(board[i][0]=='O'){
                dfs(board,i,0,row,col);
            }
            if(board[i][col-1]=='O'){
                dfs(board,i,col-1,row,col);
            }

        }
        for(int i=0;i<col;i++){
              if(board[0][i]=='O'){
                dfs(board,0,i,row,col);
            }
            if(board[row-1][i]=='O'){
                dfs(board,row-1,i,row,col);
            }

        }
        for(int i=0;i<row;i++){
            for(int j=0;j<col;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                if(board[i][j]=='#'){
                    board[i][j]='O';
                }
            }
        }
    }

    void dfs(vector<vector<char>>& board ,int x,int y,int row,int col){
        if(x<0|| x>=row|| y>=col|| y<0 || board[x][y]!='O'){
            return;
        }
        board[x][y]='#';
        dfs(board,x+1,y,row,col);
        dfs(board,x-1,y,row,col);
        dfs(board,x,y+1,row,col);
        dfs(board,x,y-1,row,col);


    }
};
