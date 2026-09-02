class Solution {
public:
int dx[4]={1,-1,0,0};
int dy[4]={0,0,-1,1};
    int minTimeToReach(vector<vector<int>>& moveTime) {

     priority_queue<pair<int,pair<int,int>>,
               vector<pair<int,pair<int,int>>>,
               greater<pair<int,pair<int,int>>>> pq;

               int n=moveTime.size();
               int m=moveTime[0].size();
               vector<vector<int>>dis(n,vector<int>(m,INT_MAX));


               pq.push({0,{0,0}});

               while(!pq.empty()){
                auto node=pq.top();
                pq.pop();
                int x=node.second.first;
                int y=node.second.second;
                int wt=node.first;
                if(x==n-1 && y==m-1)return wt;
            



                for(int i=0;i<4;i++){
                    int X=x+dx[i];
                    int Y=y+dy[i];
                    if(X>=n || Y>=m || X<0 || Y<0)continue;


                    int new_cost=max(wt,moveTime[X][Y])+1;

                    if(new_cost<dis[X][Y]){
                        dis[X][Y]=new_cost;
                        pq.push({new_cost,{X,Y}});
                    }

                    
                    
                }


               }
               return dis[n-1][m-1];



        
    }
};