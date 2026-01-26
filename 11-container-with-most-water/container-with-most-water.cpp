class Solution {
public:
    int maxArea(vector<int>& height) {
        int l=0;
        int r=height.size()-1;
        int ans=0;

        while(l<=r){
            int res=(r-l)*min(height[r],height[l]);
            ans=max(ans,res);
            if(height[l]>height[r]){
                r--;
            }
            else{
                l++;
            }

        }
        return ans;
        
    }
};