class Solution {
public:
    int countTestedDevices(vector<int>& arr) {
        int ans=0;
        for(int i=0;i<arr.size();i++){
            if(arr[i]==0){
                continue;
            }
            else if(arr[i]>0){
                ans++;
            }
            for(int j=i+1;j<arr.size();j++){
                if(arr[j]>0){
                    arr[j]-=1;
                }
            }
        }
        return ans;
    }
};