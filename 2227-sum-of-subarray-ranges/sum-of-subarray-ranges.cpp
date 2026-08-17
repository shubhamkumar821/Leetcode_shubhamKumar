class Solution {
public:
    long long subArrayRanges(vector<int>& nums) {

        int n = nums.size();

        int NSE[n];
        int PSEE[n];

        int NGE[n];
        int PGEE[n];

        stack<int> st;

        // Next smallest element
        for (int i = n - 1; i >= 0; i--) {

            if (st.empty()) {
                st.push(i);
                NSE[i] = n;
            }

            else {
                while (!st.empty() && nums[i] <= nums[st.top()]) {
                    st.pop();
                }

                if (!st.empty()) {
                    NSE[i] = st.top();
                }

                else {
                    NSE[i] = n;
                }

                st.push(i);
            }
        }

        // clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Previous smaller or equal element
        for (int i = 0; i < n; i++) {

            if (st.empty()) {
                st.push(i);
                PSEE[i] = -1;
            }

            else {
                while (!st.empty() && nums[i] < nums[st.top()]) {
                    st.pop();
                }

                if (!st.empty()) {
                    PSEE[i] = st.top();
                }

                else {
                    PSEE[i] = -1;
                }

                st.push(i);
            }
        }

        // clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Next greater element
        for (int i = n - 1; i >= 0; i--) {

            if (st.empty()) {
                st.push(i);
                NGE[i] = n;
            }

            else {
                while (!st.empty() && nums[i] >= nums[st.top()]) {
                    st.pop();
                }

                if (!st.empty()) {
                    NGE[i] = st.top();
                }

                else {
                    NGE[i] = n;
                }

                st.push(i);
            }
        }

        // clear stack
        while (!st.empty()) {
            st.pop();
        }

        // Previous greater or equal element
        for (int i = 0; i < n; i++) {

            if (st.empty()) {
                st.push(i);
                PGEE[i] = -1;
            }

            else {
                while (!st.empty() && nums[i] > nums[st.top()]) {
                    st.pop();
                }

                if (!st.empty()) {
                    PGEE[i] = st.top();
                }

                else {
                    PGEE[i] = -1;
                }

                st.push(i);
            }
        }

        // calculate answer

        long long minimum = 0;
        long long maximum = 0;

        for (int i = 0; i < n; i++) {

            long long left = i - PSEE[i];
            long long right = NSE[i] - i;

            minimum += (long long)nums[i] * left * right;

            left = i - PGEE[i];
            right = NGE[i] - i;

            maximum += (long long)nums[i] * left * right;
        }

        return maximum - minimum;
    }
};