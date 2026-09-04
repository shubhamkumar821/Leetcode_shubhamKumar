class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {


        vector<int>ans;
        int cnt=1;
        if(nums.size()==1)return nums;
        if(k==1)return nums;

        for(int i=0;i<nums.size()-1;i++){

            if(nums[i+1]==nums[i]+1){
                cnt++;
            }

            else{
                cnt=1;
            }

            if( cnt>=k){
                ans.push_back(nums[i+1]);

            }
            else if(cnt<k && i>=k-2){
                ans.push_back(-1);
            }
        }
        return ans;
        
    }
};