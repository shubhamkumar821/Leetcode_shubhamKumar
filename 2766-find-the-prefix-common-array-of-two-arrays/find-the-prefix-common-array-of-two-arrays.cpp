class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {

        map<int,int>mpp;
        vector<int>ans;
       
        for(int i=0;i<A.size();i++){
            mpp[A[i]]++;
            mpp[B[i]]++;
            int cnt=0;
            for(auto i:mpp){
                if(i.second==2){
                    cnt++;
                    
                }
                
            }
             ans.push_back(cnt);
        }
        return ans;
        
    }
};