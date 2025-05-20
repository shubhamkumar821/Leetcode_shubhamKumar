class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        
        if(nums.size()==1){
            return true;
        }
        int oddcnt=0;
        int evencnt=0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]%2==0){
                evencnt++;
                oddcnt=0;
            }
            else{
                evencnt=0;
                oddcnt++;

            }
            if(evencnt>1 ||oddcnt>1){
                return false;
            }
            
        }
        return true;
    }
};