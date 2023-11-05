class Solution {
public:
    int getWinner(vector<int>& arr, int k) {
        unordered_map<int,int> mp;
        int n=arr.size();
        int ans=arr[0];
        for(int i=0;i<n;i++){
            mp[arr[i]]=0;
        }
        int i=1;
        int j=0;
        int c=0;
        while(i<n){
            if(arr[0]>arr[i]){
                mp[arr[0]]++;
                if(mp[arr[0]]==k || j>2*n){
                    ans=arr[0];
                    c=1;
                }
            }
            else{
                swap(arr[0],arr[i]);
                mp[arr[0]]++;
                if(mp[arr[0]]==k || j>2*n){
                    ans=arr[0];
                    c=1;
                }
            }
            i++;
            j++;
            i=i%n;
        
            if(c==1){
                break;
            }
        }
        return ans;
    }
};