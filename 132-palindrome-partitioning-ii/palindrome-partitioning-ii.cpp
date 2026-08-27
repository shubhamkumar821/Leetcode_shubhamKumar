class Solution {
public:
int dp2[2050];
int dp1[2050][2050];
    int minCut(string s) {
        memset(dp1, -1, sizeof(dp1));
         memset(dp2, -1, sizeof(dp2));
        return rec2(s.size()-1,s);
    }

    int rec2(int i,string &s){

        if(i<0){
            return -1;

        }

        if(dp2[i]!=-1)return dp2[i];
        int ans=1e9;

        for(int j=i-1;j>=-1;j--){
            if(rec1(j+1,i,s)){
                ans=min(ans,1+rec2(j,s));
            }
        }
        return dp2[i]=ans;
    }

    int rec1(int l,int r,string &s){
        if(l>=r)return 1;

        if(dp1[l][r]!=-1)return dp1[l][r];
        int ans=0;

        if(s[l]==s[r] && rec1(l+1,r-1,s))ans=1;

        return dp1[l][r]=ans;
    }
};