class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int res=0;
        for(auto i:mp){
            int second = i.second;
            if(second == 1) return -1;
            if(second % 3 == 1){
                res += (second/3) - 1;
                res += 2;
            }else{
                res += (second/3);
                res += ((second%3)/2);
            }
            
        }
        return res;
    }
};