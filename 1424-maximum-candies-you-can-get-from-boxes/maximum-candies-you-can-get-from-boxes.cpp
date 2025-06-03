class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& cb, vector<int>& ib) {
        int n=status.size();
        queue<int> q;
        vector<int> found(n,0);
        for(auto it:ib){
            if(status[it]==1) q.push(it);
            else found[it]=1;
        }
        // okay, basically 2 cheez h, ya toh box mil gaya h aur key abtak nahi mila h, shayad aage mil jaaye
        // aur ya toh box mila h aur already khula hua h toh hum bas is waale case mein add karenge, aur 1st case mein
        // key ka wait karenge
        int count=0;
        while(!q.empty()){
            auto it=q.front(); q.pop();

            count+=candies[it];
            for(auto itr:keys[it]){
                if(!status[itr] && found[itr]) q.push(itr);
                status[itr]=1;
            }

            for(auto itr:cb[it]){
                if(status[itr]) q.push(itr);
                else found[itr]=1;
            }
        }
        return count;
    }
};