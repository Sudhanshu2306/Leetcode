class Solution {
public:
    vector<int> occurrencesOfElement(vector<int>& nums, vector<int>& queries, int x) {
        int count=0;
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++){
            if(nums[i]==x){
                count++;
                mp[count]=i;
            } 
        }
        
        vector<int> ans;
        for(auto i:queries){
            if(mp.find(i)!=mp.end()) ans.push_back(mp[i]);
            else ans.push_back(-1);
        }
        return ans;
    }
};