class Solution {
public:
    vector<int> findMissingAndRepeatedValues(vector<vector<int>>& grid) {
        int n=grid.size();
        int x=0;
        unordered_map<int,int> mp;
        unordered_set<int> st;
        int a;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                st.insert(grid[i][j]);
                mp[grid[i][j]]++;
                if(mp[grid[i][j]] == 2){
                    a=grid[i][j];
                }
            }
        }
        // now xor has values of missing number and repeated number
        int b;
        for(int i=1;i<=n*n;i++){
            if(st.find(i)==st.end()){
                b=i;
                break;
            }
        }
        return {a,b};
        
    }
};