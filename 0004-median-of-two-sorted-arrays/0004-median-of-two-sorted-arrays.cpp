
class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int t=n+m;
        int ind1=t/2-1; int e1=INT_MAX;
        int ind2=t/2; int e2=INT_MAX;

        int c=0;
        int i=0,j=0;
        while(i<n && j<m){
            if(nums1[i]>nums2[j]){
                if(c==ind1) e1=nums2[j];
                if(c==ind2) e2=nums2[j];
                c++;j++;
            }
            else{
                if(c==ind1) e1=nums1[i];
                if(c==ind2) e2=nums1[i];
                c++;i++;
            }

            if(e1!=INT_MAX && e2!=INT_MAX) break;
        }
        while(i<n){
            if(c==ind1) e1=nums1[i];
            if(c==ind2) e2=nums1[i];
            c++;i++;
            if(e1!=INT_MAX && e2!=INT_MAX) break;
        }

        while(j<m){
            if(c==ind1) e1=nums2[j];
            if(c==ind2) e2=nums2[j];
            c++;j++;
            if(e1!=INT_MAX && e2!=INT_MAX) break;
        }

        if(t&1) return (double)(e2);
        else return (double)(e1+e2)/2.0;
    }
};
