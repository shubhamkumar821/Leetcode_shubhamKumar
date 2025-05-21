class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs)
     {
        map<string ,vector<string>>res;
        for(auto i: strs)
        {
            string s=i;
            sort(s.begin(),s.end());
            res[s].push_back(i);
        }
        vector<vector<string >>ans;
    for(auto i:res){
        ans.push_back(i.second);
        
    }

      return ans;  
    }
};
