class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        int n=heights.size();
        int lsb[n];
        int rsb[n];
        stack<int>st;
        for(int i=0;i<n;i++){
            if(st.empty()){
            st.push(i);
            lsb[i]=0;
            }
            else {
                while(!st.empty()   && heights[i]<=heights[st.top()]){
                    st.pop();
                }
                if(!st.empty() && heights[i]>heights[st.top()]){
                    lsb[i]=st.top()+1;

                }
                else {
                    lsb[i]=0;
                }
            }
            st.push(i);
        }
        while(!st.empty())st.pop();

        for(int i=n-1;i>=0;i--){
            if(st.empty()){
                st.push(i);
                rsb[i]=n-1;
            }
            else{
                while(!st.empty() && heights[st.top()]>=heights[i]){
                    st.pop();
                }
                if(!st.empty() && heights[st.top()]<heights[i]){
                    rsb[i]=st.top()-1;
                }
                else{
                    rsb[i]=n-1;
                }

            }
            st.push(i);
        }
        int ans=0;
        for(int i=0;i<n;i++){
            int area=heights[i]*(rsb[i]-lsb[i]+1);
            ans=max(ans,area);
        }
        return ans;
        
    }
};