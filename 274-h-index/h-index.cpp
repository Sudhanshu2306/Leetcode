class Solution {
public:
    int hIndex(vector<int>& citations) {
        int n=citations.size();
        // if(n==1) return citations[0]>0;
        sort(citations.begin(),citations.end());

        int ans=n;
        for(int i=0;i<n;i++){
            if(n-i >= citations[i]) ans=citations[i];
            else ans=max(n-i, ans);
        }
        return ans;
    }
};