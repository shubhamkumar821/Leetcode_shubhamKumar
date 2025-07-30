class Solution {
public:
    int minOperations(vector<string>& logs) {
        int cnt=0;
        for(auto i:logs){
            if(i=="../"){
                if(cnt==0){
                    continue;

                }
                else{
                    cnt--;
                }
                

                
            }
            else if(i=="./"){
                continue;
            }
            else {
                cnt++;

            }
            
        }
        if(cnt<0){
            return 0;
        }
        return cnt;
        
    }
};