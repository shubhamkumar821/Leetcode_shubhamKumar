class Solution {
public:
string s,t;
int m,n;
vector<vector<int>>dp;
    int minDistance(string word1, string word2) {
        m=word1.size();
        n=word2.size();
        dp.assign(m,vector<int>(n,-1));
s=word1;
t=word2;
int x=m+n;
 int y=rec(0,0);
 int ans=x-2*y;
 return   ans;

        
    }
    int rec(int i,int j){
        if(i>=m|| j>=n)return 0;
        int ans= 0;
        if(dp[i][j]!=-1)return dp[i][j];
       
        ans=max(rec(i+1,j),ans);
        ans=max(rec(i,j+1),ans);
        if(s[i]==t[j]){
            ans=max(ans,1+rec(i+1,j+1));
        }
        return dp[i][j]=ans;
    }
};