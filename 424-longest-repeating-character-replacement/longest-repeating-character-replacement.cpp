class Solution {
public:
    int characterReplacement(string s, int k) {
        int n=s.size();
        int i=0,j=0;
        int maxi=0;
        vector<int> mp(26,0);
        int maxf=0;
        while(j<n){
            mp[s[j]-'A']++;
            maxf=max(maxf,mp[s[j]-'A']);
            while(((j-i+1)-maxf)>k){
                mp[s[i]-'A']--;
                maxf=0;
                for(int k=0;k<26;k++){
                    maxf=max(maxf,mp[k]);
                }
                i++;
            }
            if(((j-i+1)-maxf)<=k) maxi=max(maxi,j-i+1);
            j++;
        }
        return maxi;
    }
};