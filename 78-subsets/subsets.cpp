class Solution {
public:
vector<vector<int>>ans;
vector<int>st;
int n;
    vector<vector<int>> subsets(vector<int>& nums) {
        n=nums.size();

        rec(0,nums);
        return ans;

        
    }
    void rec(int level,vector<int>& nums){
        if(level==n){
            ans.push_back(st);
            return ;

        }
        rec(level+1,nums);
        st.push_back(nums[level]);
        rec(level+1,nums);
        st.pop_back();
        

    }
};