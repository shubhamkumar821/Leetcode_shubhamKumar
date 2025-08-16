class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        multiset<int> st;
        vector<int> ans;
        
        // Insert all elements of nums2 into the multiset
        for(int num : nums2) {
            st.insert(num);
        }
        
        // For each element in nums1, check if it exists in the multiset
        for(int num : nums1) {
            auto it = st.find(num);  // Find one occurrence
            if(it != st.end()) {
                ans.push_back(num);
                st.erase(it);  // Remove ONLY THIS ONE occurrence
            }
        }
        
        return ans;
    }
};