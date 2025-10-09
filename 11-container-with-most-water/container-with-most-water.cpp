class Solution {
public:
    int maxArea(vector<int>& heights) {
        int n=heights.size();

        int ans=0;
        int i=0;
        int j=n-1;
        while(i<n && j>i){
                ans=max(ans,(j-i)*min(heights[i],heights[j]));

               if(heights[i]>=heights[j]){
                j--;
               }
               else {
                i++;
               }

        }
        return ans;
        
    }
};
