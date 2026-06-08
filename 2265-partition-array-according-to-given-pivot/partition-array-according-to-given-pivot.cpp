class Solution {
public:
    vector<int> pivotArray(vector<int>& nums, int pivot) {

        vector<int>before,after,same;
        for(auto i:nums){
            if(i>pivot){
                after.push_back(i);

            }
            else if(i==pivot){same.push_back(i);
            }

            else{
                before.push_back(i);
            }
        }

        vector<int>ans;
        for(auto i:before){
            ans.push_back(i);
        }
         for(auto i:same){
            ans.push_back(i);
        }
         for(auto i:after){
            ans.push_back(i);
        }
        return ans;

        
        
    }
};