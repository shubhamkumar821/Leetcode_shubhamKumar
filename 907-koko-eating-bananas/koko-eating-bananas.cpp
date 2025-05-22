class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        int low = 1;
        int high = INT_MIN;
        for(int i = 0; i < piles.size(); i++) {
            high = max(high, piles[i]);
        }
        int ans = 1;
        
        while(low <= high) {
            int mid = (low + high) / 2;
            if(check(mid, h, piles)) {
                ans = mid;
                high = mid - 1;
            }
            else {
                low = mid + 1;
            }
        }
        return ans;
    }
    
    bool check(int x, int h, vector<int>& piles) {
        long long sum = 0;
        int n = piles.size();
        for(int i = 0; i < n; i++) {
            sum += ceil(piles[i] / (double)x);
        }
        if(sum <= h) {
            return true;
        }
        else {
            return false;  // This was missing in your original code
        }
    }
};