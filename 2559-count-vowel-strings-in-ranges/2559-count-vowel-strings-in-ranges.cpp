class Solution {
public:
    bool f(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pre(n);
        pre[0]=(f(words[0][0])?1:0);

        for(int i=1;i<n;i++){
            if(f(words[i][0])) pre[i]=pre[i-1]+1;
            else pre[i]=pre[i-1];
        }
        vector<int> ans;
        for(auto it:queries){
            int l=it[0], r=it[1];
            int x;
            if(l==0) x=0;
            else x=pre[l-1];
            ans.push_back(pre[r]-x);
        }
        return ans;
    }
};