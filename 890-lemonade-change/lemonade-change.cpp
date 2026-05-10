class Solution {
public:
    bool lemonadeChange(vector<int>& bills) {
    int cnt5=0,cnt10=0;

        for(auto i:bills){
            if(i==5){
                cnt5++;
            }
            else if(i==10){
                if(cnt5>=1){
                    cnt5--;
                }
                else{
                    return false;
                }
                cnt10++;
            }
            else{
                if(cnt5>=1 && cnt10>=1){
                    cnt10--;
                    cnt5--;

                }
                else if(cnt5>=3){
                    cnt5=cnt5-3;

                }
                else{
                    return false;
                }
            }
        }
        return true;
        
    }
};