class Solution {
public:
bool rec(int level,vector<vector<char>>& board,int n,int col){
    if(col==n){
        return  rec(level+1,board,n,0);
    }
    if(level==n){
        return true ;
    }
    if(board[level][col]=='.'){
        for(char ch='1';ch<='9';ch++){
            if(check(ch,level,col,board,n)){
                board[level][col]=ch;
                if(rec(level,board,n,col+1)){
                    return true;
                };
                board[level][col]='.';

            }
        }
    }
    else{
        
           return  rec(level,board,n,col+1);
        }
        return false;

    }



bool check(char ch,int row,int col,vector<vector<char>>& board,int n){
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
    void solveSudoku(vector<vector<char>>& board) {
        int n=board.size();
        rec(0,board,n,0);
        
    }
};