class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
        
        int mini=101;
        int maxi=0;
        int mp[101]={0};
        for(auto i:nums){
            nums.pop_back();
            mp[i]++;
            maxi=max(maxi,i);
            mini=min(mini,i);
            
        }
        vector<int>ans;
        for(int i=mini;i<=maxi;i++){
            if(mp[i]){
                continue;
            }
            else{ 
                ans.push_back(i);

            }
        }
        return ans;

        
        

    }
};