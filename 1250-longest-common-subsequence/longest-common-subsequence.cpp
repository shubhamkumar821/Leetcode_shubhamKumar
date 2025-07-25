class Solution {
public:
    int dp[1001][1001];
    int longestCommonSubsequence(string text1, string text2) {
        memset(dp,-1,sizeof(dp));
        return rec(0,0,text1,text2);
        
    }
    int rec(int i,int j,string &a,string& b){
        if(i==a.size()|| j==b.size()){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;
        ans=max(ans,rec(i+1,j,a,b));
        ans=max(ans,rec(i,j+1,a,b));
        if(a[i]==b[j]){
            ans=max(ans,1+rec(i+1,j+1,a,b));
        }
        return dp[i][j]=ans;

    }
};