class Solution {
public:
 vector<vector<int>> dp;
    int minimumTotal(vector<vector<int>>& triangle) {
           int n = triangle.size();
        int m = triangle[n-1].size();
        dp.clear();
        dp.assign(n+5,vector<int>(m+5,-5));
        return rec(0,0,triangle);
    
        
    }
    int rec(int i,int j,vector<vector<int>>&num ){
        // pruning 
        
        if(i==num.size()-1){
            return num[i][j];

        }
        if(dp[i][j]!=-5){
            return dp[i][j];
        }
        int ans=num[i][j]+min(rec(i+1,j,num),rec(i+1,j+1,num));
        return dp[i][j]=ans;

        
    }
};