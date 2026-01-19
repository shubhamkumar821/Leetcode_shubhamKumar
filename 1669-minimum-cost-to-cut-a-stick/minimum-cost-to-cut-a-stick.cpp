class Solution {
public:
int  dp[110][110];
    int minCost(int n, vector<int>& cuts) {
        memset(dp,-1,sizeof(dp));
            cuts.push_back(0);
        cuts.push_back(n);
        sort(cuts.begin(), cuts.end());
        return rec(0,cuts.size() - 1,cuts);

        
    }
    int rec(int l,int r, vector<int>& cuts){
        if(l+1==r){
            return 0;
        }

        if(dp[l][r]!=-1){
            return dp[l][r];
        }
        int ans=1e9;

        for(int p=l+1;p<r;p++){

           ans=min(ans,(cuts[r]-cuts[l])+rec(l,p, cuts)+rec(p,r,cuts));
        }

        return dp[l][r]=ans;
    }
};