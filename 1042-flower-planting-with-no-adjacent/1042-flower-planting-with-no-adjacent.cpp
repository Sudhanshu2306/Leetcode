class Solution {
public:
    
    bool isValid(unordered_map<int,vector<int>> &mp, vector<int> &ans, int node, int color){
        for(auto &i:mp[node]){
            if(ans[i]==color){
                return false;
            }
        }
        return true;
    }
    
    bool solve(unordered_map<int,vector<int>> &mp, vector<int> &ans,int n, int node){
        if(node==n+1){
            return true;
        }
        for(int i=1;i<=4;i++){
            if(isValid(mp,ans,node,i)){
                ans[node]=i;
                if(solve(mp,ans,n,node+1)){
                    return 1;
                }
                ans[node]=0;
            }
        }
        return false;
    }
    
    vector<int> gardenNoAdj(int n, vector<vector<int>>& paths) {
        unordered_map<int,vector<int>> mp;
        for(auto &node:paths){
            mp[node[0]].push_back(node[1]);
            mp[node[1]].push_back(node[0]);
        }
        vector<int> ans(n+1,0);
        
        solve(mp,ans,n,1);
        ans.erase(begin(ans),begin(ans)+1);
        return ans;
        
    }
};