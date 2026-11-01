class Solution {
public:
    int minMoves(vector<int>& nums) {
        int sum=0;
        int mini=INT_MAX;

        for(auto i:nums){
            mini=min(mini,i);
            sum+=i;
        }
        return sum-mini*(int)nums.size();
        
    }
};