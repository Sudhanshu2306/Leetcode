class Solution {
public:
    int minimumPushes(string s) {
        unordered_map<char,int> mp;
        int n=s.length();
        for(int i=0;i<n;i++){
            mp[s[i]]++;
        }
        vector<int> arr;
        for(auto i:mp) arr.push_back(i.second);

        sort(arr.rbegin(),arr.rend());
        int mini=0;
        for(int i=0;i<arr.size();i++){
            int x=(i/8)+1;
            mini+=x*arr[i];
        }
        return mini;
    }
};