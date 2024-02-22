class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        if(n==1) return 1;
        vector<int> a(n+1,0);

        for(auto i:trust){
            a[i[0]]--; a[i[1]]++;
        }
        for(int i=1;i<=n;i++){
            if(a[i]==n-1) return i;
        }
        return -1;
    }
};