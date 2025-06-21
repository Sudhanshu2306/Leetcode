class Solution {
public:
    int minimumDeletions(string word, int k) {
        vector<int> f(26,0);
        for(auto it:word) f[it-'a']++;
        sort(f.rbegin(),f.rend());

        int mini=INT_MAX;
        for(int i=0;i<26;i++){
            int count=f[i];
            int a=0;
            for(int j=0;j<26;j++){
                if(f[j]-count>k) a+=(f[j]-count-k);
                else if(count>f[j]) a+=f[j];
            }
            mini=min(mini,a);
            if(a==0) break;
        }
        return mini;
    }
};