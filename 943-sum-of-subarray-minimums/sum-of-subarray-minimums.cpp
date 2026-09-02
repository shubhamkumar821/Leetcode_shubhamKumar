class Solution {
public:
    #define MOD 1000000007

    int sumSubarrayMins(vector<int>& arr) {
        int n = arr.size();

        vector<int> PSEE(n), NSEE(n);
        stack<int> st;

        // Previous Smaller or Equal Element
        for (int i = 0; i < n; i++) {

            while (!st.empty() && arr[st.top()] > arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                PSEE[i] = -1;
            } 
            else {
                PSEE[i] = st.top();
            }

            st.push(i);
        }

        // Clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next Smaller Element
        for (int i = n - 1; i >= 0; i--) {

            while (!st.empty() && arr[st.top()] >= arr[i]) {
                st.pop();
            }

            if (st.empty()) {
                NSEE[i] = n;
            } 
            else {
                NSEE[i] = st.top();
            }

            st.push(i);
        }

        long long ans = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - PSEE[i];
            long long right = NSEE[i] - i;

            long long contribution =
                ((arr[i] * left) % MOD * right) % MOD;

            ans = (ans + contribution) % MOD;
        }

        return ans;
    }
};