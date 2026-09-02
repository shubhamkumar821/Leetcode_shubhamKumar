class Solution {
public:
     int solve(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        int n = nums.size();
        
        for (int i = 0; i <= n; i++) {
            // Correct logic: Use 0 at the end to force pop everything
            int curr = (i == n) ? 0 : nums[i];
            
            // Fix 1: Change to '<' to maintain an increasing stack
            while (!st.empty() && curr < nums[st.top()]) {
                int top = st.top(); // This is the bar we are processing
                st.pop();
                
                // Fix 2: Calculate the correct width for the popped bar
                int width = st.empty() ? i : (i - st.top() - 1);
                
                // Fix 3: Multiply by the correct height (nums[top])
                int total = width * nums[top]; 
                ans = max(ans, total);
            }
            
            // Fix 4: Only push valid indices; do not push the boundary index 'n'
            if (i < n) {
                st.push(i);
            }
        }
        return ans;
    }
    int maximalRectangle(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        /*
            vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
            int ans = 0;
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                    if (matrix[i - 1][j - 1] == '1') {
                        dp[i][j] =
                            1 + min({dp[i][j - 1], dp[i - 1][j], dp[i - 1][j -
           1]});

                        ans = max(ans, dp[i][j]);
                    }
                }
            }
            for (int i = 1; i <= n; i++) {
                for (int j = 1; j <= m; j++) {
                   cout<<dp[i][j]<<" ";
                }
                cout<<endl;
            }

            return ans;
            */
        vector<int> nums(m,0);
        int ans=0;
        for (int i = 0; i < n; i++) {
            
            for (int j = 0; j < m; j++) {
                if(matrix[i][j]=='1'){
                    nums[j]+=1;
                }
                else if(matrix[i][j]=='0'){
                    nums[j]=0;
                }
            }
            // for(int i=0;i<nums.size();i++){
            //     cout<<nums[i]<<" ";
            // }
            // cout<<endl;
            // cout<<"ans="<<solve(nums)<<endl;
            ans=max(ans,solve(nums));
        }
        return ans;
    }
};