class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;
        
        while (l <= r) {
            int mid = l + (r - l) / 2;
            if (nums[mid] == target) {
                return true;
            }
            
            // Handle duplicates: move pointers inward if nums[l] == nums[mid] == nums[r]
            if (nums[l] == nums[mid] && nums[mid] == nums[r]) {
                l++;
                r--;
            } 
            // Left part is sorted
            else if (nums[l] <= nums[mid]) {
                if (nums[l] <= target && target < nums[mid]) {
                    r = mid - 1;
                } else {
                    l = mid + 1;
                }
            } 
            // Right part is sorted
            else {
                if (nums[mid] < target && target <= nums[r]) {
                    l = mid + 1;
                } else {
                    r = mid - 1;
                }
            }
        }
        
        return false;
    }
};