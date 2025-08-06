class Solution {
public:
    int tree[400005];
    void build(vector<int> &arr, int node, int start, int end){
        if(start==end) {tree[node]=arr[start]; return;}
        int mid=(start+end)/2;
        build(arr,2*node,start,mid);
        build(arr,2*node+1,mid+1,end);
        tree[node]=max(tree[2*node],tree[2*node+1]);
    }
    int query(int node, int start, int end, int k){
        if(tree[node]<k) return -1;
        if(start==end){
            tree[node]=-1; return start;
        }
        int mid=(start+end)/2;
        int pos=-1;
        if(tree[2*node]>=k) pos=query(2*node,start,mid,k);
        else pos=query(2*node+1,mid+1,end,k);

        tree[node]=max(tree[2*node],tree[2*node+1]);
        return pos;
    }

    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        build(baskets,1,0,n-1);
        int ans=0;
        for(int i=0;i<n;i++){
            int pos=query(1,0,n-1,fruits[i]);
            if(pos==-1) ans++;
        }
        return ans;
    }
};