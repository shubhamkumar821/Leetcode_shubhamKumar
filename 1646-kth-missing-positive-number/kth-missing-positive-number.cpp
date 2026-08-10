class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        map<int,int>mp;
        for(auto i:arr){
            mp[i]++;
        }
    int cnt=0;
    for(int i=1;i<=10000;i++){
        if(mp[i]==0){
            cnt++;
        }
        if(cnt==k){
            return i;
        }

    }
    return -1;
        
    }
};