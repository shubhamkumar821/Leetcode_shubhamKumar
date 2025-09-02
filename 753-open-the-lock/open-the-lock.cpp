class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        set<string>vis(deadends.begin(),deadends.end());
        if(vis.count("0000"))
        return -1;
        queue<pair<string,int>>q;
        q.push({"0000",0});
        vis.insert("0000");
        while(!q.empty()){
            auto [lock,turns]=q.front();
            q.pop();
            if(lock==target)return turns;
            for(auto i:children(lock)){
                if(!vis.count(i)){
                    vis.insert(i);
                        q.push({i,turns+1});
                    
                }
                

            }
        }
        return -1;


        
    }

    vector<string>children(string lock){
        vector<string>res;
        for(int i=0;i<4;i++){
            string next=lock;
            next[i]=(next[i]-'0'+1)%10+'0';
            res.push_back(next);
            next=lock;
            next[i]=(next[i]-'0'-1+10)%10+'0';
            res.push_back(next);
        }
        return res;
    }
};