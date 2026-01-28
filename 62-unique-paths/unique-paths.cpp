class Solution {
public:
vector<vector<int>>dp;
int a,b;
    int uniquePaths(int m, int n) {
        dp=vector<vector<int>>(m+1,vector<int>(n+1,-1));
        a=m;
        b=n;
        return rec(0,0);
        
    }
    int rec(int i,int j){
        if(i==a-1 && j==b-1){
            return 1;
        }
        if(i>=a || j>=b){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        ans+=(rec(i+1,j)+rec(i,j+1));

        return dp[i][j]=ans;
    }
};
