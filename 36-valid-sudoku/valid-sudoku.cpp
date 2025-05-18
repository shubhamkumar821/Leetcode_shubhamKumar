class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        int n=board.size();
        for(int i=0;i<9;i++){
            for(int j=0;j<9;j++){
                if(board[i][j]=='.'){
                    continue;
                }
                else{
                    if(check(i,j,board,n,board[i][j])){
                        continue;
                    }
                    else{
                        return false;
                    }
                }
            
        }

        }
        return true;
        
        
    }
    bool check(int row,int col,vector<vector<char>>& board,int n,char ch){
    for(int r=0;r<9;r++){
        if(r!=row && board[r][col]==ch)
        return false;

    }
    for(int c=0;c<9;c++){
        if(c!=col && board[row][c]==ch)
        return false;

    }
    int str=(row/3)*3;
    int stc=(col/3)*3;
    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            if(str+i==row && stc+j==col){
                continue;
            }
            if(board[str+i][stc+j]==ch){
                return false;
            }
        }
    
    }
    return true;

}
};