class Solution {
public:
    string removeDuplicates(string s, int k) {

        stack<pair<char,int>>st;

        for(auto i :s){

            if(st.empty()){
                st.push({i,1});

            }
            else if(i==st.top().first && st.top().second==k-1){
                    
                st.pop();
                

            }
            else if(i==st.top().first  &&  st.top().second<k-1){
                int x=st.top().second;
                x++;
                st.pop();
                st.push({i,x});
              
            }
            else{
                st.push({i,1});
            }
        }
        string t="";

        while(!st.empty()){
            for(int i=0;i<st.top().second;i++){
                t+=st.top().first;
            }
            
            st.pop();
        }
reverse(t.begin(),t.end());
        return t;

        
    }
};