class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int>st;
        for(int i:asteroids){
            if(st.empty())st.push(i);
            else if(i<0 && st.top()>0){
                while(!st.empty()  && st.top()>0 && st.top()<abs(i))
                st.pop();

                if(!st.empty() && st.top()<0)st.push(i);
                else if(!st.empty()  && st.top()>abs(i))continue;
                else if(!st.empty() && st.top()>0   && abs(i)==st.top())st.pop();
                else st.push(i);


            }

            else {
                st.push(i);
            }
        }

        vector<int>ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;


        
    }
};