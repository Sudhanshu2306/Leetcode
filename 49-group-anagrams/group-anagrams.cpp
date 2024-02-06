class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        int n=strs.size();
        vector<vector<string>> ans;
        vector<string> arr=strs;
        
        for(auto &i:arr){
            sort(i.begin(),i.end());
        }
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<n;i++){
            mp[arr[i]].push_back(strs[i]);
        }

        for(auto i:mp){
            ans.push_back(i.second);
        }
        return ans;
    }
};