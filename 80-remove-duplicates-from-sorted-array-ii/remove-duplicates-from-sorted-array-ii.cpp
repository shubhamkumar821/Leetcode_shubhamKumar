class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        map<int,int>mp;
        for(auto i:nums){
            mp[i]++;
            if(mp[i]>2){
                mp[i]=2;
            }
        }
        nums.clear();

        for(auto i:mp){
            for(int j=0;j<i.second;j++){
                nums.push_back(i.first);

            }
        }
        return nums.size();
        
        
        
        
    }
};