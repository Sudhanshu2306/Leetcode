class Solution {
public:
    map<string,int> mp;
    int ff(int i, string s, string ans){
        // base case
        if(i==s.size()) return mp.find(ans)==mp.end()?1:0;

        int count=0;
        if(mp.find(ans)==mp.end()){
            mp[ans]=1;
            // recursion call
            count=1+ff(i+1,s,s.substr(i,1));
            // backtrack
            mp.erase(ans);
        }
        return count=max(count,ff(i+1,s,ans+s[i]));
    }
    int maxUniqueSplit(string s) {
        mp=map<string,int>();
        // we will not pass 0 and ans as "" because it will get us a empty substring as well
        return ff(1,s,s.substr(0,1));
    }
};