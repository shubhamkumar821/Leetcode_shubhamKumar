class Solution {
public:
    int countPrimeSetBits(int left, int right) {
        int cnt = 0;

        for(int i = left; i <= right; i++){
            int x = __builtin_popcount(i);
            if(check(x)) cnt++;
        }
        return cnt;
    }

    bool check(int x){
        if(x <= 1) return false;

        for(int i = 2; i * i <= x; i++){
            if(x % i == 0)
                return false;
        }
        return true;
    }
};