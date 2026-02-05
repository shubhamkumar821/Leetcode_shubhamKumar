class Solution {
public:
    string frequencySort(string s) {
        map<char,int>mp;
        for(auto i:s){
            mp[i]++;
        }
        priority_queue<pair<int,char>>pq;
        for(auto i:mp){
            pq.push({i.second,i.first});
        }
   string t="";
        while(!pq.empty()){
            auto x=pq.top();
            int k=x.first;
            char ch=x.second;
            for(int i=0;i<k;i++){
                t+=ch;
            }
            pq.pop();
        }
        return t;
        
    }
};