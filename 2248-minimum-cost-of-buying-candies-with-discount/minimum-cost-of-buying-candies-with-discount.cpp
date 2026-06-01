class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(),cost.end());
        reverse(cost.begin(),cost.end());
        int n=cost.size();
        int i=0;
        int sum=0;
        if(n==1){
            return cost[0];
        }
        int ap=2;
        for(int i=0;i<n;i++){
            if(ap==i){
                ap+=3;
                continue;
            }
            sum+=cost[i];
        }
        return sum;
    }
};