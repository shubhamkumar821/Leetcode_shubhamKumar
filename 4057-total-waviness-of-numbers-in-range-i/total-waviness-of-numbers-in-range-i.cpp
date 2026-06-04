class Solution {
public:
    int totalWaviness(int num1, int num2) {

        if(num2<100)return 0;
        int ans=0;

        for(int i=num1;i<=num2;i++){
            ans+=peakandvalley(i);

        }
        return ans;
        
        
    }
    int peakandvalley(int x){
        int cnt=0;
        while(x){
            if(x<100){
                break;
            }
        int prev=x%10;
        int next=((x/100)%10);
        int curr=((x/10)%10);
        if(curr>prev && curr>next){
            cnt++;
        }
        if(curr<prev && curr<next){
            cnt++;
        }
        x=x/10;
        }
        return cnt;
    }

};