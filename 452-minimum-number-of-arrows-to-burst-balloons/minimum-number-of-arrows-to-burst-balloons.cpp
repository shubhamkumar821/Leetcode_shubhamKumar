class Solution {
public:
    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(),points.end());
        vector<vector<int>>merged;

        for(auto i:points){
            if(merged.empty()){
                merged.push_back(i);
            }

            else if(merged.back()[1]>=i[0]){
                merged.back()[1]=min(merged.back()[1],i[1]);
                //merged.back()[0]=max(merged.back()[0],i[0]);
            }
            else {
                merged.push_back(i);
            }
        }

        return merged.size();
        
    }
};