class Solution {
public:
    void update(vector<int> &a, int i, int val){
        while(i<a.size()){
            a[i]+=val; i+=(i&-i);
        }
    }
    long long query(vector<int> &a, int i){
        long long ans=0;
        while(i>0){
            ans+=a[i]; i-=(i&-i);
        }
        return ans;
    }
    long long goodTriplets(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        vector<int> pos(n);

        for(int i=0;i<n;i++) pos[nums2[i]]=i;
        vector<int> mp(n);
        for(int i=0;i<n;i++) mp[i]=pos[nums1[i]];

        vector<long long> left(n,0), right(n,0);
        vector<int> a(n+2,0);

        for(int i=0;i<n;i++){
            left[i]=query(a,mp[i]);
            update(a,mp[i]+1,1);
        }
        fill(a.begin(),a.end(),0);
        for(int i=n-1;i>=0;i--){
            right[i]=query(a,n)-query(a,mp[i]+1);
            update(a,mp[i]+1,1);
        }
        long long ans=0;
        for(int i=0;i<n;i++) ans+=(left[i]*right[i]);
        return ans;
    }

};