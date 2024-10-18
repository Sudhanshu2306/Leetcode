class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
        int maxi=0;
        int n=nums.size();
        for(int i=0;i<n;i++){
            maxi|=nums[i];
        }
        int i=0;
        int left=0;
        int tot=pow(2,n); int ans=0;
        while(i<tot){
            int temp=0;
            for(int j=0;j<n;j++){
                if(i&(1<<j)) temp|=nums[j];
            }
            if(temp==maxi) ans++;
            i++;
        }
        // cout<<(1<<2)<<endl;
        return ans;
    }
};