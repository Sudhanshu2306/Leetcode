class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n=A.size();
        unordered_map<int,int>mp;
        vector<int> pre(n,0);
        mp[A[0]]=1; 
        if(A[0]==B[0]) pre[0]=1;

        for(int i=1;i<n;i++){
            mp[A[i]]++;
            for(int j=0;j<=i;j++){
                if(mp.find(B[j])!=mp.end()){
                    pre[i]+=mp[B[j]];
                }
            }
        }
        return pre;
    }
};