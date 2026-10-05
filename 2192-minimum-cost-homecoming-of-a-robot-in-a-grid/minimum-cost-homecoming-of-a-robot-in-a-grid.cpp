class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int ans=0;
        int x=startPos[0];
        int y=startPos[1];

        if(x<homePos[0]){
            for(int i=x;i<homePos[0];i++ ){
                ans+=rowCosts[i+1];
            }
        }
        else if(x>homePos[0]){
            for(int i=x;i>homePos[0];i--){
                ans+=rowCosts[i-1];
            }

        }

        if(y<homePos[1]){
            for(int i=y;i<homePos[1];i++ ){
                ans+=colCosts[i+1];
            }
        }
        else if(y>homePos[1]){
            for(int i=y;i>homePos[1];i--){
                ans+=colCosts[i-1];
            }

        }
        return ans;


        
    }
};