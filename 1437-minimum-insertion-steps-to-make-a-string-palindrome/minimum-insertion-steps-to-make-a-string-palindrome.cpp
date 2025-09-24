class Solution {
public:
int n;
string st;
int dp[1001][1001];
    int minInsertions(string s) {
     n=s.size();
     st=s;
     memset(dp,-1,sizeof(dp));
     int ans=1e9;

     for(int i=0;i<n;i++){
        ans=min({ans,1+rec(i,i+1),1+rec(i-1,i+1)});

     }
     return ans-1;
        
    }
   int rec(int i, int j) {
    if (i == -1) return n - j;
    if (j == n) return i + 1;

    auto &ans = dp[i][j];
    if (ans != -1) return ans;
    ans = 1e9;

    if (st[i] == st[j]) 
        ans = min(ans, rec(i - 1, j + 1));
    else 
        ans = min({ans, 1 + rec(i - 1, j), 1 + rec(i, j + 1)});
    return ans;
}

};