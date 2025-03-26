class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        multiset<int> mt;
        vector<int> ans;
        int n=nums.size();
        for(int i=0;i<n;i++){
            mt.insert(nums[i]);
            if((i-k)>=0)
                mt.erase(mt.find(nums[i-k]));
                
            
            if(mt.size()==k)
                ans.push_back(*(mt.rbegin()));
            
        }
        return ans;

        
    }
};