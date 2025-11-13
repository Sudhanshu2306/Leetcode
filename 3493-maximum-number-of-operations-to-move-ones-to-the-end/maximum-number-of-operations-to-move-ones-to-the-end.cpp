class Solution {
public:
    int maxOperations(string s) {
        int n=s.size();
        bool flag=false;
        int count=0;int temp=0;
        vector<int> ans;
        for(int i=0;i<n;i++){
            if(s[i]=='1'){
                ans.push_back(1);
                flag=true;
            }
            if(flag && s[i]=='0'){
                ans.push_back(0);
                flag=false;
            }
        }
        int m=ans.size();
        for(int i=0;i<m;i++){
            if(ans[i]==1) temp++;
            else count+=temp;
        }

        return count;
    }
};