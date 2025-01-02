class Solution {
public:
    bool f(char ch){
        return (ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u');
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n=words.size();
        vector<int> pre(n+1);
        pre[0]=0;

        for(int i=0;i<n;i++){
            if(f(words[i][0]) && f(words[i].back())) pre[i+1]=pre[i]+1;
            else pre[i+1]=pre[i];
        }
        vector<int> ans;
        for(auto it:queries){
            int l=it[0], r=it[1];
            ans.push_back(pre[r+1]-pre[l]);
        }
        return ans;
    }
};