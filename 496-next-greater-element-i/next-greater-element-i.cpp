class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {

         vector<pair<int,int>>v;

         for(int i=0;i<nums1.size();i++){

            for(int j=0;j<nums2.size();j++){
                if(nums1[i]==nums2[j]){
                    v.push_back({nums1[i],j});
                }
            }

         }

         vector<int>ans;
         for(auto i:v){
            bool ch=false;

            for(int j=i.second+1;j<nums2.size();j++){
                if(i.first<nums2[j]){
                    ans.push_back(nums2[j]);
                    ch=true;
                    break;
                }
          

                }

                if(!ch){
                    ans.push_back(-1);
                }
            }

              return ans;
        

         } 
       
    
};