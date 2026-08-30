
class Solution {
public:

    map<string, vector<string>> email_list;
    set<string> vis;

    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {

        vector<vector<string>> ans;

        for(auto i:accounts){
            string f_e=i[1];

            for(int j=2;j<i.size();j++){
                email_list[f_e].push_back(i[j]);
                email_list[i[j]].push_back(f_e);

            }
        }

        
        for (auto i : accounts) {

            string name = i[0];
            string email = i[1];

            if (vis.find(email) == vis.end()) {

                vector<string> st;
                st.push_back(name);

                dfs(st, email);

                sort(st.begin() + 1, st.end());

                ans.push_back(st);
            }
        }

        return ans;
    }

    void dfs(vector<string>& st, string& email) {

        vis.insert(email);

        st.push_back(email);

        for (auto i : email_list[email]) {

            if (vis.find(i) == vis.end()) {
                dfs(st, i);
            }
        }
    }
};

