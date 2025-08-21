class Solution {
public:
    vector<string> sortPeople(vector<string>& names, vector<int>& heights) {
        
        set<pair<int,string>>st;
        int n=names.size();
        vector<string>ans;
        for(int i=0;i<n;i++){
            st.insert({-1*heights[i],names[i]});
        }
        for(auto i:st){
            ans.push_back(i.second);
        }
        return ans;
    }
};