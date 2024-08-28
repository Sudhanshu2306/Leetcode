class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> arr;
        bool f=1;
        int ind;
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(f) ind=j;
                else ind=n-1-j;
                arr.push_back(board[i][ind]);
            }
            f=!f;
        }
        vector<int> vis(n*n,0);
        queue<pair<int,int>> q; 
        // {ind,moves}
        q.push({0,0});
        while(!q.empty()){
            auto x=q.front(); q.pop();
            int ind=x.first; int moves=x.second;

            if(ind==n*n-1) return moves;

            for(int i=1;i<=6;i++){
                if(ind+i<n*n){
                    int next=ind+i;
                    if(arr[next]!=-1){
                        next=arr[next]-1;
                    }
                    if(vis[next]==0){
                        q.push({next,moves+1});
                        vis[next]=1;
                    }
                }
            }
        }
        return -1;
    }
};