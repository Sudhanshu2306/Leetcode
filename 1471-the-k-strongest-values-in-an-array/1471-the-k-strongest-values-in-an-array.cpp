class Solution {
public:
    vector<int> getStrongest(vector<int>& arr, int k) {
        int n=arr.size();
        sort(arr.begin(),arr.end());
        int m=arr[(n-1)/2];

        vector<int> ans;
        int i=0,j=n-1;
        while(k--){
            if(abs(arr[i]-m)<abs(arr[j]-m)){
                ans.push_back(arr[j]);
                j--;
            }
            else if(abs(arr[i]-m)>abs(arr[j]-m)){
                ans.push_back(arr[i]);
                i++;
            }
            else if(abs(arr[i]-m)==abs(arr[j]-m)){
                ans.push_back(arr[j]);
                j--;
            }
        }
        return ans;
    }
};