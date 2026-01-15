class Solution {
public:
int dp[100100];
    vector<int> countBits(int n) {
        memset(dp,-1,sizeof(dp));
        vector<int>st;
        for(int i=0;i<=n;i++){
            int ans=rec(i);
            st.push_back(ans);

        }
        return st;
        
    }
    int rec(int x){
        if(x==0){
            return 0;

        }
        if(dp[x]!=-1){
            return dp[x];
        }
        int ans=(rec(x/2)+x%2);
        return dp[x]=ans;


    }
};