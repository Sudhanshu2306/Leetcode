class Solution {
public:
    set<int> c,pd,nd;
    void f(int i, int n, int &ans){
        if(i==n){
            ans++; return;
        }
        for(int j=0;j<n;j++){
            if(c.count(j) || pd.count(i+j) || nd.count(i-j)) continue;
            c.insert(j); pd.insert(i+j); nd.insert(i-j);
            f(i+1,n,ans);
            c.erase(j); pd.erase(i+j); nd.erase(i-j);
        }
    }
    int totalNQueens(int n) {
        int ans=0;
        f(0,n,ans);
        return ans;
    }
};