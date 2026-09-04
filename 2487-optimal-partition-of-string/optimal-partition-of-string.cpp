class Solution {
public:
    int partitionString(string s) {

        int head=0;
        int tail=0;
        int cnt=0;
        int n=s.length();
        map<char,int>mp;
        while(tail<n){
            while(head<n && mp[s[head]]==0){
                mp[s[head]]++;
                head++;
            }
            cnt++;
            mp.clear();
            tail=head;
        }
        return cnt;
        
    }
};