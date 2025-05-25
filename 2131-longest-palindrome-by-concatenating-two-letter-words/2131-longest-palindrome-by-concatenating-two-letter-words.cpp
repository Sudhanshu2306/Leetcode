class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        map<string,int> mp;
        bool flag=false;

        // for(auto it:words) mp[it]++;
        int count=0;
        for(auto it:words){
            string x=it; reverse(x.begin(),x.end());
            if(mp[x]>0){
                count+=4; mp[x]--;
            }
            else mp[it]++;
        }
        for(auto it:mp){
            if(it.first[0]==it.first[1] && it.second>0) return count+2;
        }
        return count;
    }
};