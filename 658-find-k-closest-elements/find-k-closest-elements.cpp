class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        vector<pair<int,int>>st;
        for(auto i:arr){
            st.push_back({abs(x-i),i});
        }
        sort(st.begin(),st.end());
        vector<int>ans;
        for(int i=0;i<k;i++){
            ans.push_back(st[i].second);
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};