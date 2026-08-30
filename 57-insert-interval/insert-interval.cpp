class Solution {
public:
    vector<vector<int>> insert(vector<vector<int>>& intervals, vector<int>& newInterval) {


        intervals.push_back(newInterval);
        sort(intervals.begin(),intervals.end());

        vector<vector<int>>merged;

        for(auto i:intervals){
            if(merged.empty() ){
                merged.push_back(i);
            }
            else if(  merged.back()[1]>=i[0]){
                

                merged.back()[1]=max(i[1],merged.back()[1]);

            }
            else{
                merged.push_back(i);
            }
        }
        return merged;
        
    }
};