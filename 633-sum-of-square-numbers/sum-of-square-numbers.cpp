class Solution {
public:
    bool judgeSquareSum(int c) {
        vector<int> ans;
        for(int i = 0; i <= sqrt(c); i++) {
            ans.push_back(i * i);
        }
        for(int i = 0; i < ans.size(); i++) {
            int target = c - ans[i];
            auto it = lower_bound(ans.begin(), ans.end(), target);
            if(it != ans.end() && *it == target) {
                return true;
            }
        }
        return false;
    }
};