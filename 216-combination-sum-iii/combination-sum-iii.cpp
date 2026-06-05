class Solution {
public:
int N,K;
vector<vector<int>>ans;
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>arr(9);
        N=n;
        K=k;
        for(int i=0;i<9;i++){
            arr[i]=i+1;

        }
        vector<int>st;
        rec(st,0,0,arr);
        return ans;
        
    }
    void rec(vector<int>&st,int lev,int sum,vector<int>&arr){
        if(lev==9){
            if(st.size()==K  && sum==N){
                ans.push_back(st);
                return;
            }
            else{
                return;
            }
        }
        if(sum>N)return ;
        rec(st,lev+1,sum,arr);
        st.push_back(arr[lev]);
        rec(st,lev+1,sum+arr[lev],arr);
        st.pop_back();

    }
};