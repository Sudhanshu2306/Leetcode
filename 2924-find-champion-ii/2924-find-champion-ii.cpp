class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        // if(n==1) return 0;
        vector<int> inDegree(n,0);
        int edgeLength = edges.size();
        for(int i = 0; i<edgeLength;i++){
            inDegree[edges[i][1]]++;
        }
        int flag=0;
        int count=0;
        // int ans=INT_MAX;
        for(int i=0;i<n;i++){
            if(inDegree[i]==0 && flag==0){
                flag=1;
                count=i;
            }
            else if(inDegree[i]==0 && flag==1) return -1;
        }
        return count;
    }
};