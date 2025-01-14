class Solution {
public:
    bool isValid(string s) {
        map<char,int> mpp;
        mpp['[']=1;
        mpp['(']=2;
        mpp['{']=3;
        mpp[']']=-1;
        mpp[')']=-2;
        mpp['}']=-3;
        int n=s.size();
        stack<int> st;
        if(n==1){
            return false;
        }
        
        for(char v:s){
            int val=mpp[v];
            if(val>0){
                st.push(mpp[v]);
            }
            else {
                if(!st.empty() && st.top()+val==0){
                    st.pop();
                }
                else{
                    return false;
                    break;

                }
            }
        }
        if(st.empty()){
            return true;
        }
        return false;
        
    }
};