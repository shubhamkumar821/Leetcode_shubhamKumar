class Solution {
public:
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
       multiset<int>mt;
       for(int i=0;i<m;i++){
        mt.insert(nums1[i]);

       } 
       for(int i=0;i<n;i++){
        mt.insert(nums2[i]);

       }
       for(int i=0;i<(n+m);i++){
        nums1.pop_back();
       }
       for(auto i:mt){
    nums1.push_back(i);
       }
    }
};