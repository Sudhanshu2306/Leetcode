class Solution {
public:
    void f(int curr, int n, vector<int> &ans){
        if(curr>n) return;

        ans.push_back(curr);

        for(int i=0;i<=9;i++){
            int nn=curr*10+i;
            if(nn>n) return;
            f(nn,n,ans);
        }
    }
    vector<int> lexicalOrder(int n) {
        vector<int> ans;
        for(int i=1;i<=9;i++){
            f(i,n,ans);
        }
        return ans;
    }
};