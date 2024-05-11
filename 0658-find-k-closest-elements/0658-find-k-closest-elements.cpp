class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int n=arr.size();
        vector<int> ans;
        int i=0, j=n-1;

        while((j-i)>=k){
            int a=abs(arr[i]-x);
            int b=abs(arr[j]-x);

            if(a<=b) j--;
            else i++;
        }
        for(int k=i;k<=j;k++){
            ans.push_back(arr[k]);
        }
        return ans;
    }
};