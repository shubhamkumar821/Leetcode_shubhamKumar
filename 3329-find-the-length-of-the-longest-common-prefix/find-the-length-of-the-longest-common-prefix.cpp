class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {

        map<int,int>mp;
        for(auto i:arr1){
            while(i){
                mp[i]++;
                i=i/10;
            }
        }
      int maxi=0;
        for(auto i:arr2){
            while(i){
                if(mp.find(i)!=mp.end()){
                    int cnt=dig(i);
                    maxi=max(maxi,cnt);
                }
                i=i/10;
            }
        }

        return maxi;

         
        
    }
    int dig(int x){
        int cnt=0;
        while(x){
            cnt++;
            x=x/10;
        }
        return cnt;
    }
};