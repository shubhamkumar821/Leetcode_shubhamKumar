class Solution {
public:
    int solve(vector<int>& nums) {
        stack<int> st;
        int ans = 0;
        for (int i = 0; i <= nums.size(); i++) {
            int curr = (i == nums.size()) ? 0 : nums[i];
            while (!st.empty() && curr < nums[st.top()]) {
                int top = st.top();
                st.pop();
                int prev = st.empty() ? i : (i - st.top() - 1);
                int total = prev * nums[top];
                ans = max(ans, total);
            }
            ans = max(ans, curr);
            st.push(i);
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
        vector<int> nums(m, 0);
        int ans = 0;
        for (int i = 0; i < n; i++) {

            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == '1') {
                    nums[j] += 1;
                } else if (matrix[i][j] == '0') {
                    nums[j] = 0;
                }
            }
            // for(int i=0;i<nums.size();i++){
            //     cout<<nums[i]<<" ";
            // }
            // cout<<endl;
            // cout<<"ans="<<solve(nums)<<endl;
            ans = max(ans, solve(nums));
        }
        return ans;
    }
};