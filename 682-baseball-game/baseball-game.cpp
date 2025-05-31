class Solution {
public:
    int calPoints(vector<string>& operations) {
        stack<int> st;
        int n=operations.size();
        for(int i=0;i<n;i++){
            if(operations[i]=="D"){
            int x=st.top();
            st.push(2*x);

            }
            else if(operations[i]=="C"){
                st.pop();

            }
            else if(operations[i]=="+"){
                int k=st.top();
                st.pop();
                int m=st.top();
                st.push(k);
                st.push(k+m);
                

            }
            else{
                string t="";
                t+=operations[i];
                int k=stoi(t);
                st.push(k);
            }
        }
        int sum=0;
        while(!st.empty()){
            int m=st.top();
            sum+=m;
            st.pop();

        }
        return sum;
        
    }
    
};