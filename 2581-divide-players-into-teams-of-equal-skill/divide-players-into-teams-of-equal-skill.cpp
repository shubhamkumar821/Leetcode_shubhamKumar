class Solution {
public:
    long long dividePlayers(vector<int>& skills) {

         sort(skills.begin(),skills.end());
        long long ans=0;
        int n=skills.size();
        if(n&1){
            return -1;
        }

        int check=skills[0]+skills[n-1];

        for(int i=0;i<n;i++){
            if(check!=skills[i]+skills[n-i-1]){
                return -1;
            }
            else{
                ans+=skills[i]*skills[n-i-1];
            }
        }

        
    
        

        
        return ans/2;
        
    }
};