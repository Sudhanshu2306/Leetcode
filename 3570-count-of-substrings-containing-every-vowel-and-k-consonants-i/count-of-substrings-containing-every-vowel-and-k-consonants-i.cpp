class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    int f(unordered_map<char,int> vowels){
        int x=0;
        for(auto i:vowels) x+=i.second;
        return x;
    }
    int ss(string s, int k){
        unordered_map<char,int> mp;
        int n=s.size();
        int cons=0; int ans=0; int af=0;
        int i=0,j=0;
        while(j<n){
            mp[s[j]]++;
            if(isVowel(s[j]) && mp[s[j]]==1) af++;
            else if(!isVowel(s[j])) cons++;

            while(cons>k && i<j){
                mp[s[i]]--;
                if(isVowel(s[i]) && mp[s[i]]<=0) {
                    af--;
                }
                else if(!isVowel(s[i])){
                    cons--;
                }
                i++;
            }
            if(i<j && af==5 && cons==k){
                ans++;
                int x=i;
                char temp=s[x];
                unordered_map<char,int> mp1;
                while(isVowel(temp) && mp[temp]>1){
                    ans++;
                    mp1[temp]++;
                    mp[temp]--; x++;
                    temp=s[x];
                }
                for(auto it:mp1) mp[it.first]+=it.second;
            } 
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        int x1=ss(word,k);;
        return x1;

    }
};