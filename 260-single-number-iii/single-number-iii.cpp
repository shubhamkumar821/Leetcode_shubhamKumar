class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long x=0;
        for(auto i: nums){
            x^=i;
        }
        long long y=x&(~(x-1));
        vector<int> ans1,ans2;
        for(int i=0;i<nums.size();i++){
            if(nums[i]&y){
                ans1.push_back(nums[i]);
            }
            else{
                ans2.push_back(nums[i]);
            }
        }
        int a=0;
        int b=0;
        for(auto i :ans1){
            a^=i;

        }
        for(auto i: ans2){
            b^=i;

        }
        vector<int> ans;
        ans.push_back(a);
        ans.push_back(b);
        return ans;
        
    }
};