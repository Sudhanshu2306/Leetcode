class Solution {
public:
    int numOfUnplacedFruits(vector<int>& fruits, vector<int>& baskets) {
        int n=fruits.size();
        vector<int> vis(n+1,0);
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(fruits[i]<=baskets[j] && vis[j]!=1){
                    count++; vis[j]=1; break;
                }
            }
        }
        return n-count;
    }
};