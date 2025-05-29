class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq;
        for(auto i: stones){
            pq.push(i);
        }
        while(pq.size()>1){
            int k=pq.top();
            pq.pop();
            int m=pq.top();
           pq.pop();
           if(m!=k){
            pq.push(k-m);
           }


        }
if(!pq.empty()){
    return pq.top();
}
return 0;
        
    }
};
