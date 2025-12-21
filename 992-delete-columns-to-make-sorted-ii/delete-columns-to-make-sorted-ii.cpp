class Solution {
public:
    int minDeletionSize(vector<string>& strs) {
        set<int> st;
        int n=strs.size();
        for(int i=1;i<n;i++){
            for(int j=0;j<strs[i].size();j++){
                if(st.count(j)>0 || strs[i-1][j]==strs[i][j]) continue;
                if(strs[i-1][j]>strs[i][j]){
                    st.insert(j); i=0;
                } break;
            }
        }
        return st.size();
    }
};