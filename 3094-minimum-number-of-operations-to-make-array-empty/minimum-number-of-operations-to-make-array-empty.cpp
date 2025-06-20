class Solution {
public:
    int minOperations(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(auto i:nums){
            mp[i]++;
        }
        int count=0;
        for(auto it:mp){
            int f=it.second;
            if(f==1) return -1;
            if(f%3==0) count+=(f/3);
            else if(f%3==1){
                count+=(f/3-1);
                count+=2;
            }
            else{
                count+=(f/3)+1;
            }
        }
        return count;
    }
};