class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {

        map<string ,int>mpp;
        for(auto i: words){
            mpp[i]++;
        }
        set<pair<int,string>>st;
        vector<string>ans;
        for(auto i: mpp){
            st.insert({-1*i.second,i.first});
        }
        int count=0;
        for(auto i: st){
            if(count!=k){
                count++;
                ans.push_back(i.second);

            }
            else{
                break;
            }
        }
        return ans;
        
    }
};