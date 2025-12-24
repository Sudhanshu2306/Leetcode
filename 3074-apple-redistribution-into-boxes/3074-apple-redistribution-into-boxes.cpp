class Solution {
public:
    int minimumBoxes(vector<int>& apple, vector<int>& capacity) {
        int sum=0;
        for(auto i:apple) sum+=i;
        
        sort(capacity.rbegin(),capacity.rend());
        int total=0;
        int ans=0;
        for(auto i:capacity){
            ans++;
            total+=i;
            if(total>=sum){
                return ans;
            }
        }
        return ans;
    }
};