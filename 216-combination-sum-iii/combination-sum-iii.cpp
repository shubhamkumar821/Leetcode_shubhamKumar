class Solution {
public:
    vector<vector<int>> st;
    vector<int> ans;

    void rec(int num, int k, int sum) {

        // found valid combination
        if(ans.size() == k) {
            if(sum == 0) {
                st.push_back(ans);
            }
            return;
        }

        // stop if sum becomes negative
        if(sum < 0 || num > 9) return;

        // take current number
        ans.push_back(num);
        rec(num + 1, k, sum - num);

        // backtrack
        ans.pop_back();

        // skip current number
        rec(num + 1, k, sum);
    }

    vector<vector<int>> combinationSum3(int k, int n) {

        rec(1, k, n);

        return st;
    }
};