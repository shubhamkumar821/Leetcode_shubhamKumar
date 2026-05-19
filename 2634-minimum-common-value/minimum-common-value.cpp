class Solution {
public:
    int getCommon(vector<int>& nums1, vector<int>& nums2) {
    map<int,int>mpp;
    int mini=INT_MAX;
    for(auto i:nums1){
        mpp[i]++;
    }
    for(auto i:nums2){
        if(mpp.find(i)!=mpp.end()){
            mini=min(mini,i);
        }
    }
    if(mini==INT_MAX){
        return -1;
    }
    return mini;
        
    }
};