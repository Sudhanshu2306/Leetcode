typedef long long ll;
class Solution {
public:
    ll tree[400000], lazy[400000];

    void build(vector<int>& arr, ll node, ll start, ll end) {
        if(start==end) tree[node]=arr[start];
        else{
            ll mid=(start+end)/2; 
            build(arr,2*node+1,start,mid); 
            build(arr,2*node+2,mid+1,end); 
            tree[node]=max(tree[2*node+1],tree[2*node+2]);
        }
    }
    int query(ll node, ll start, ll end, ll ind, ll val) {
        if (start==end){
            if(tree[node]>val && start>=ind) return start;
            else return -1;
        }
        ll mid=(start+end)/2; 
        if(ind<=mid && tree[2*node+1]>val){
            int x=query(2*node+1,start,mid,ind,val);
            if(x!=-1) return x;
        } 
        return query(2*node+2,mid+1,end,ind,val);
    }

    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        int n=heights.size();
        int q=queries.size();
        vector<int> ans;

        build(heights,0,0,n-1);
        for(auto it:queries){
            int mini=min(it[0],it[1]);
            int maxi=max(it[0],it[1]);
            if(heights[maxi]>heights[mini] || maxi==mini) ans.push_back(maxi);
            else{
                int x=query(0,0,n-1,maxi,heights[mini]);
                ans.push_back(x);
            }
        }
        return ans;
    }
};