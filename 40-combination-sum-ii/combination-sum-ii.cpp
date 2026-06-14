class Solution {
public:
    int tar;
    vector<vector<int>> ans;
    int n;

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        tar = target;
        sort(candidates.begin(), candidates.end()); // added
        vector<int> st;
        n = candidates.size();
        rec(0, 0, candidates, st);
        return ans;
    }

    void rec(int lev, int sum, vector<int>& nums, vector<int>& st) {

        if (sum == tar) {
            ans.push_back(st);
            return;
        }

        if (sum > tar) return; // moved outside loop

        for (int i = lev; i < n; i++) {

            if (i > lev && nums[i] == nums[i - 1]) continue; // skip duplicates

            st.push_back(nums[i]);
            rec(i + 1, sum + nums[i], nums, st);
            st.pop_back();
        }
    }
};