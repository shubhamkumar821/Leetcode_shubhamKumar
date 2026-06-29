class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {

        stack<int>st;
        int n=prices.size();
        vector<int>IND(n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && prices[st.top()]>prices[i]){
                st.pop();

            }
            if(st.empty()){
                IND[i]=-1;


            }
            else{
                IND[i]=prices[st.top()];
            

            }
            st.push(i);

        }
        for(int i=0;i<n;i++){
            if(IND[i]==-1){
                continue;

            }
            else{
                prices[i]-=IND[i];
            }

        }
        return prices;
        


        
    }
};