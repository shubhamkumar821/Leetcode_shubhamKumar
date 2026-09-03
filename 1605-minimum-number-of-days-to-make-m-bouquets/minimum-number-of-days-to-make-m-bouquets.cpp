class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        int l = INT_MAX;
        int h = INT_MIN;

        for (auto i : bloomDay) {
            l = min(i, l);
            h = max(h, i);
        }
        // cout<<h<<l<<endl;

        if (1LL *m*1LL* k > bloomDay.size())
            return -1;
        int ans = -1;

        while (l <= h) {
            int mid = (h + l) / 2;
            if (check(mid, bloomDay, m, k)) {
                h = mid - 1;
                ans = mid;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }

    bool check(int x, vector<int>& arr, int m, int k) {
        int cnt_adj = 0;
        int len = 0;
        for (int i = 0; i < arr.size(); i++) {

            if (x >= arr[i]) {
                len++;
            }
            else{
                len=0;
            }
            if (len == k) {
                cnt_adj++;
                len = 0;
            }
        }

        return cnt_adj >= m;
    }
};