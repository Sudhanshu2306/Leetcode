class Solution {
public:
    string originalDigits(string s) {
        map<char,int> mp;
        for(auto it:s) mp[it]++;
        string ans="";
        while(mp['z']){ // 0
            ans+="0";
            mp['z']--; mp['r']--; mp['e']--; mp['o']--;
        }
        while(mp['w']){ // 2
            ans+="2";
            mp['t']--; mp['w']--; mp['o']--;
        }
        while(mp['u']){ // 4
            ans+="4";
            mp['f']--; mp['o']--; mp['u']--; mp['r']--;
        }
        while(mp['r']){ // 3
            ans+="3";
            mp['t']--;mp['h']--;mp['r']--;mp['e']--;mp['e']--;
        }
        while(mp['f']){ // 5
            ans+="5";
            mp['f']--;mp['i']--;mp['v']--;mp['e']--;
        }
        while(mp['x']){ // 6
            ans+="6";
            mp['s']--;mp['i']--;mp['x']--;
        }
        while(mp['o']){ // 1
            ans+="1";
            mp['o']--;mp['n']--;mp['e']--;
        }
        while(mp['v']){ //7
            ans+="7";
            mp['s']--;mp['e']--;mp['v']--;mp['e']--;mp['n']--;
        }
        while(mp['g']){ //8
            ans+="8";
            mp['e']--;mp['i']--;mp['g']--;mp['h']--;mp['t']--;
        }
        while(mp['n']){
            ans+="9";
            mp['n']--; mp['i']--; mp['n']--; mp['e']--;
        }
        sort(ans.begin(),ans.end());
        return ans;
    }
};