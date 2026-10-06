class Solution {
public:
    int n,m;
    vector<vector<int>>dp;

    bool isMatch(string s, string p) {
        n=s.size();
        m=p.size();

        dp.assign(n+1,vector<int>(m+1,-1));

        return rec(0,0,s,p);
    }

    int rec(int i,int j,string &s,string &p){

        if(j==m){
            return i==n;
        }

        if(dp[i][j]!=-1){
            return dp[i][j];
        }

        bool check=false;

        if(j+1<m && p[j+1]=='*'){

            // don't take p[j] and *
            check=rec(i,j+2,s,p);

            // take p[j] and match current character
            if(i<n && (s[i]==p[j] || p[j]=='.')){
                check=check || rec(i+1,j,s,p);
            }
        }

        else if(i<n && (s[i]==p[j] || p[j]=='.')){

            check=rec(i+1,j+1,s,p);
        }

        else{
            check=false;
        }

        return dp[i][j]=check;
    }
};