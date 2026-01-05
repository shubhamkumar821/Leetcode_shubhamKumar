class Solution {
public:
    long long numberOfCars(vector<int>&cars,long long bound){
        long long cnt=0;
        for(auto x:cars){
            cnt+=sqrt(bound/x);
        }
        return cnt;
    }

    long long repairCars(vector<int>& ranks, int cars) {
        long long low=0,high=0;
        for(auto x:ranks) high=max(high,(long long)x);
        high=high*cars*cars;
        while(low<=high){
            long long mid=(low+(high-low)/2);
            if(numberOfCars(ranks,mid)>=cars) high=mid-1;
            //it means this could be answer but we will search for lower one
            else low=mid+1;
        }
//As here we have found the answer but high have greedy nature thus it will be distroyed and later one i.e low will be answer
        return low;
    }
};