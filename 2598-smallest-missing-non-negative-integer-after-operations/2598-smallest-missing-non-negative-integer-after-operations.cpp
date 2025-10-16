class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        map<int,int> mp;
        int n=nums.size();
        for(auto it:nums){
            if(it%value<0) mp[it%value+value]++;
            else mp[it%value]++;
        }
        int ans=0; int i;
        for(i=0;i<=n;i++){
            if(mp[i%value]>0) mp[i%value]--;
            else break;
        }
        return i;
    }
};