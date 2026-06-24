class Solution {
public:
    vector<int> dailyTemperatures(vector<int>& temperatures) {

        stack<pair<int,int>>st;
        vector<int>ans;
        int n=temperatures.size();
        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push({temperatures[i],i});
                ans.push_back(0);
            }
            else{
                bool check=true;
                int cnt=0;
                while(!st.empty()){
                    cnt++;
                    if(st.top().first>temperatures[i]){
                        check=false;
                        int x=st.top().second;
                        ans.push_back(x-i);
                        break;
                    }
                    st.pop();
                }
                if(check)ans.push_back(0);


            }
            st.push({temperatures[i],i});


        }
        reverse(ans.begin(),ans.end());
        return ans;
        
    }
};