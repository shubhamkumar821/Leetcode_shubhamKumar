class Solution {
public:
    vector<int> sortArray(vector<int>& nums) {
        priority_queue<int> pq;
        for(int i=0;i<nums.size();i++){
            pq.push(nums[i]);
        }
        vector<int> ans;
        while(!pq.empty()){
            int k=pq.top();
            ans.push_back(k);
            pq.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};