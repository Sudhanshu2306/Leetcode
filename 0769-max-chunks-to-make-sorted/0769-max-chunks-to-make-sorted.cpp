class Solution {
public:
    int maxChunksToSorted(vector<int>& arr) {
        int n=arr.size();
        int maxi=INT_MIN;
        int count=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,arr[i]);
            if(maxi==i) count++;
        }
        return count;
    }
};