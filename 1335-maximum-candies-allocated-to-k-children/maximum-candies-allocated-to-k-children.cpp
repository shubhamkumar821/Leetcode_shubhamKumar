class Solution {
public:
    int maximumCandies(vector<int>& candies, long long k) {

        long long mini = 1;
        long long maxi = 0;
        
        for (auto i : candies) {
            maxi = max(maxi, (long long)i);
        }

        int ans = 0;

        while (mini <= maxi) {
            long long mid = (mini + maxi) / 2;

            if (check(mid, candies, k)) {
                ans = mid;
                mini = mid + 1;   // ✅ move right
            } else {
                maxi = mid - 1;   // ✅ move left
            }
        }
        return ans;
    }

    bool check(long long x, vector<int>& candies, long long k) {
        long long count = 0;

        for (auto i : candies) {
            count += i / x;
        }

        return count >= k;
    }
};