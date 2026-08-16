class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        vector<int>v;
        v=nums;
        for(auto i:nums){
        v.push_back(i);
        }
        stack<int>st;
        vector<int>ans;
        for(int i=v.size()-1;i>=0;i--){
            if(st.empty()){
                st.push(v[i]);
                ans.push_back(-1);
            }

            else {
                while(!st.empty() && st.top()<=v[i])st.pop();
                if(!st.empty() && st.top()>v[i]){
                    ans.push_back(st.top());

                }
                else {
                    ans.push_back(-1);
                    
                }
            }
            st.push(v[i]);
        }

       reverse(ans.begin(),ans.end());
       for(int i=0;i<nums.size();i++){
           ans.pop_back();
       }
        return ans;
        
    }
};