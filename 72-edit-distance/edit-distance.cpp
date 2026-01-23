class Solution {
public:
vector<vector<int>>dp;
int m,n;
    int minDistance(string word1, string word2) {
        n=word1.size();
        m=word2.size();
      dp=vector<vector<int>>(n,vector<int>(m,-1));
        
       // memset(dp,-1,sizeof(dp));
        return rec(0,0,word1,word2);

        
    }
    int rec(int i,int j,string & s1,string & s2){
        if(i==n){
          return   m-j;
        }
        if(j==m){
            return n-i;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        if(s1[i]==s2[j]){
          dp[i][j]=  rec(i+1,j+1,s1,s2);
        }
      else{
        int ans=min(rec(i+1,j,s1,s2),rec(i,j+1,s1,s2));
        ans=min(ans,rec(i+1,j+1,s1,s2));
        dp[i][j]=ans+1;
      }
      return dp[i][j];


    }
};
