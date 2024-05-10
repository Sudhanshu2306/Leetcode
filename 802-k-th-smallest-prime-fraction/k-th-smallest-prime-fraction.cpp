class Solution {
public:
    vector<int> kthSmallestPrimeFraction(vector<int>& arr, int k) {
        int n=arr.size();
        vector<pair<double,pair<int,int>>> ans;
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                double x=1.0*arr[i]/arr[j];
                ans.push_back({x,{arr[i],arr[j]}});
            }
        }
        sort(ans.begin(),ans.end());
        return {ans[k-1].second.first,ans[k-1].second.second};
    }
};