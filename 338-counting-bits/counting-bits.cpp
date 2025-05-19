class Solution {
public:
    vector<int> countBits(int n) { vector<int> ans;
        ans.push_back(0);
       
        for(int i=1;i<=n;i++){
     int cnt=0;
     int k=i;
            while(k!=0){
                if(k&1){
                    cnt++;
                }
                k=k>>1;
            }

           
           ans.push_back(cnt);
        }
        return ans;
        
    }
};