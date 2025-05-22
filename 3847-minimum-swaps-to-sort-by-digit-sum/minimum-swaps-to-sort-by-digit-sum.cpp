class Solution {
public:
    int f(int x){
        int sum=0;
        while(x){
            sum+=x%10; x/=10;
        }
        return sum;
    }

    int minSwaps(vector<int>& nums) {
        int n=nums.size();
        vector<int> a=nums;
        sort(a.begin(),a.end(),[&](int n, int m){
            int x=f(n),y=f(m);
            if(x==y) return n<m;
            return x<y;
        });
        int count=0;
        map<int,int> mp;
        for(int i=0;i<n;i++) mp[nums[i]]=i;

        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(vis[i] || a[i]==nums[i]) continue;

            int cycle=0; int j=i;
            while(vis[j]==0){
                vis[j]=1;
                j=mp[a[j]];
                cycle++;
            }
            if(cycle>1) count+=(cycle-1);
        }
        return count;
    }
};