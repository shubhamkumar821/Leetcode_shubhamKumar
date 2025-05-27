class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        map<int,int> m;
        int n=nums.size();
        for(int i=0;i<n;i++){
        
        m[nums[i]]=i;
        }
        for(int i=0;i<n;i++){
            int num=nums[i];
            int val=target-num;
            if(m.find(val)!=m.end() && m[val]!=i){
                return {m[val],i};
                
            }
        }
        
      return {-1,-1};  
    }
};