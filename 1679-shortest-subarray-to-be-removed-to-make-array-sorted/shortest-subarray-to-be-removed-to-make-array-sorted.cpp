class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n=arr.size();
        int i=0; int j=n-1;
        while(i<n-1 && arr[i]<=arr[i+1]) i++;
        while(j>i && arr[j]>=arr[j-1]) j--;

        if(i==n-1) return 0;

        int s=0; int e=j;
        int ans=min(n-i-1,j);
        while(s<=i && e<n){
            if(arr[s]<=arr[e]){
                ans=min(ans,e-s-1); s++;
            }
            else e++;
        }
        return ans;
    }
};