class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        
        set<int>st,st2;
        vector<int>ans;
        
        for(auto i:nums2){
            st.insert(i);
        }
         for(auto i:nums1){
            st2.insert(i);
        }
        for(auto i:st2){
            if(st.find(i)!=st.end()){
                ans.push_back(i);
            }
        }
        return ans;
    }
};