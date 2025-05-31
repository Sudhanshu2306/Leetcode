class Solution {
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        int n=board.size();
        vector<int> arr;
        bool flag=true;

        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                int x;
                if(flag) x=j;
                else x=n-j-1;
                arr.push_back(board[i][x]);
            }
            flag=!flag;
        }

        queue<int> q;
        q.push(0);
        vector<int> vis(n*n,0);
        int moves=0;
        while(!q.empty()){
            int m=q.size();
            for(int i=0;i<m;i++){
                auto ind=q.front(); q.pop();
                if(ind==n*n-1) return moves;

                for(int k=1;k<=6;k++){
                    int next=ind+k;
                    if(next>= n*n) break;
                    if(arr[next]!=-1){
                        next=arr[next]-1;
                    }
                    if(vis[next]==0){
                        vis[next]=1;
                        q.push(next);
                    }
                }
            }
            moves++;
        }
        return -1;
    }
};