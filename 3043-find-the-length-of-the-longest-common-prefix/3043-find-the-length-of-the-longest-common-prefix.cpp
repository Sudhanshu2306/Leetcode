class Solution {
public:
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<string,int> mp;
        for(auto i:arr1){
            string x=to_string(i);
            for(int j=1;j<=x.length();j++){
                mp[x.substr(0,j)]++;
            }
        }
        int len=0;
        for(auto i:arr2){
            string y=to_string(i);
            for(int j=1;j<=y.length();j++){
                if(mp.find(y.substr(0,j))!=mp.end()){
                    len=max(len,j);
                }
            }
        }
        return len;
    }
};