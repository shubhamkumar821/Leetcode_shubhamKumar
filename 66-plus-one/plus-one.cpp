class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int n=digits.size()-1;
 vector<int>ans;
        if(digits[n]!=9){
            digits[n]++;
            return digits;
        }
      
        else{
            int carry=1;
            while(n>=0){
                if(digits[n]==9 && carry){
                    ans.push_back(0);
                    carry=1;

                }
                else if(digits[n]!=9 && carry){
                    int x=digits[n]+carry;
                    ans.push_back(x);
                    carry=0;
                }

                else{
                    ans.push_back(digits[n]);
                }
                n--;

            }
        
            if(carry){
                ans.push_back(1);
            }
            reverse(ans.begin(),ans.end());
            return ans;

        }
        return ans;
        
    }
};
