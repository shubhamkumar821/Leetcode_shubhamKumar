class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int n=numbers.size();
        
        for(int i=0;i<n;i++){
            int tar=target-numbers[i];
            int l=i+1;
            int h=n-1;

            while(l<=h){
                int m=(l+h)/2;
                if(tar==numbers[m]){
                    return {i+1,m+1};

                }
                else if(numbers[m]<tar){
                    l=m+1;

                }
                else{
                    h=m-1;

                }
            }
           

        }
         return {-1,-1};

    }
};