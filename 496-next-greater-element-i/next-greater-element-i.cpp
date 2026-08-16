class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
map<int,int>mp;
stack<int>st;

vector<int>ans;
  for(int i=nums2.size()-1;i>=0;i--){
    if(st.empty()){
      mp[nums2[i]]=-1;
    }
    else{
        while(!st.empty() && st.top()<nums2[i]){
            st.pop();
        }
    if(!st.empty() && st.top() >nums2[i]){
        mp[nums2[i]]=st.top();
    }
    else if(st.empty()){
         mp[nums2[i]]=-1;

    }

    }
    st.push(nums2[i]);
  }

  for(auto i:nums1){
    if(mp[i]!=0){
        ans.push_back(mp[i]);
    }
    
  }
  //reverse(ans.begin(),ans.end());
  return ans;
        
    }
};