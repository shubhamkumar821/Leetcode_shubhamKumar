class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {


        if(nums1.size() > nums2.size())
            return findMedianSortedArrays(nums2, nums1);


        int n1=nums1.size();
        int n2=nums2.size();
        int l=0;
        int h=n1;
        while(l<=h){
            int c1=(l+h)/2;
            int c2=(n1+n2+1)/2 -c1;
            int left1=0;
            if(c1==0){
                left1=INT_MIN;

            }

            else{
                left1=nums1[c1-1];

            }

            int left2=0;
            if(c2==0){
                left2=INT_MIN;
            }
            else{
                left2=nums2[c2-1];
            }

            int right1=0;
            int right2=0;

            if(c1==n1){
                right1=INT_MAX;
            }
            else{
                right1=nums1[c1];
            }
            if(c2==n2){
                right2=INT_MAX;
            }
            else{
                right2=nums2[c2];
            }

            if(left1<=right2 && left2<=right1){
                if((n1+n2)%2){
                    return double(max(left1,left2));

                }


                else {
                    return double(min(right1,right2)+max(left1,left2))/2;
                }
            }

            if(left1>right2){
                h=c1-1;

            }

            else{
                l=c1+1;

            }

        

        
        }
        return 0;
        
    }
};