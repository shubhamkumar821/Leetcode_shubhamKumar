class Solution {
public:
    int totalNQueens(int n) {
        vector<int>queens;
        queens.resize(n,-1);
        return rec(0,queens,n);
        
    }
    int rec(int level,vector<int>&queens,int n){
int ans=0;
    if(level==n){
      
        return 1;
    }
    
   
    for(int ch=0;ch<n;ch++){
        if(check(level,ch,queens)){
            queens[level]=ch;
            ans+=rec(level+1,queens,n);
            queens[level]=-1;
            
        }
    }
    return ans;
    
}
bool check(int row,int col,vector<int>&queens){
    for(int r=0;r<row;r++){
        int pc=queens[r];
        if(pc==col || abs(r-row)==abs(pc-col))
        return false;
    }
    return true;
}
   
};