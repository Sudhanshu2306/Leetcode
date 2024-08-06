class Solution {
public:
    int minimumPushes(string s) {
        // so here the keypad is not given to us, we have to design one 
        // for minimum number of presses to make type the string

        unordered_map<char,int> mp;
        for(int i=0;i<s.size();i++){
            mp[s[i]]++;
        }
        vector<int> ans;
        for(auto i:mp){
            ans.push_back(i.second);
        }
        sort(ans.rbegin(),ans.rend());

        int count=0;
        for(int i=0;i<ans.size();i++){
            int x=(i/8)+1;
            count+=x*ans[i];
        }
        return count;
    }
};