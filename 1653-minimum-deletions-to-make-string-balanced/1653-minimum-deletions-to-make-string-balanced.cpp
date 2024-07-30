class Solution {
public:

    int minimumDeletions(string s) {
        vector<int> pre_b(s.size()+1,0);
        vector<int> suff_a(s.size()+1,0);

        // pre_b[0]=(s[0]=='b');
        for(int i=0;i<s.size();i++){
            pre_b[i+1]=pre_b[i]+(s[i]=='b');
        }

        for(int j=s.size()-1;j>=0;j--){
            suff_a[j]=suff_a[j+1]+(s[j]=='a');
        }

        int mini=1e9;
        for(int i=0;i<=s.size();i++){
            mini=min(mini,pre_b[i]+suff_a[i]);
        }
        return mini;
    }
};