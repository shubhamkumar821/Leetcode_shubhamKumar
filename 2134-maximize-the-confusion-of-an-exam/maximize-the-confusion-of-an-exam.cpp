class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {

        int head=0;
        int ans1=0;
        int cnt=0;

        for(int tail=0;tail<answerKey.size();tail++){

            while(head<answerKey.size()  && (cnt<k || (cnt==k && answerKey[head]=='T' ))){
                if(answerKey[head]=='F'){
                    cnt++;
                }
                head++;
            }

            ans1=max(ans1,head-tail);

            if(answerKey[tail]=='F')cnt--;

        }


   head=0;
   cnt=0;
   int ans2=0;

        for(int tail=0;tail<answerKey.size();tail++){

            while(head<answerKey.size()  && (cnt<k || (cnt==k && answerKey[head]=='F' ))){
                if(answerKey[head]=='T'){
                    cnt++;
                }
                head++;
            }

            ans2=max(ans2,head-tail);

            if(answerKey[tail]=='T')cnt--;

        }


return max(ans1,ans2);


        
    }
};