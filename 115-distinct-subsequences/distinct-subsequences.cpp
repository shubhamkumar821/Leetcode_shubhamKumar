class Solution {
public:
vector<vector<int>>dp;
int n,m;
string str1,str2;
    int numDistinct(string s, string t) {
        n=s.size();
        m=t.size();
        str1=s;
        str2=t;
        dp.assign(n+1,vector<int>(m+1,-1));
        return rec(0,0);

        
    }
    int rec(int i,int j){

        if(j==m){
            return 1;
        }
        if(i>n){
            return 0;
        }
        if(dp[i][j]!=-1){
            return dp[i][j];
        }
        int ans=0;

        if(str1[i]==str2[j]){
            ans+=rec(i+1,j+1);
        }
        ans+=rec(i+1,j);

        return dp[i][j]=ans;
    }

};