class Solution {
public:
    int numberOfSubstrings(string s) {
        vector<int> ls(3,-1);
        int n=s.size();
        int count=0;
        for(int i=0;i<n;i++){
            ls[s[i]-'a']=i;
            if(ls[0]!=-1 && ls[1]!=-1 && ls[2]!=-1){
                int x= min({ls[0],ls[1],ls[2]});
                count+=(x+1);
            }
        }
        return count;
    }
};