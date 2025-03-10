class Solution {
public:
    bool isVowel(char ch){
        if(ch=='a' || ch=='e' || ch=='i' || ch=='o' || ch=='u') return true;
        return false;
    }
    
    long long ss(string s, int k){
        unordered_map<char,long long> vowels;
        int n=s.size();
        long long cons=0;
        long long ans=0;
        int i=0,j=0;
        while(i<=j && j<n){
            if(isVowel(s[j])) vowels[s[j]]++;
            else cons++;

            while(i<=j && cons>=k && vowels.size()==5){
                ans+=(n-j);
                if(isVowel(s[i])) vowels[s[i]]--;
                else cons--;
                if(vowels[s[i]]==0) vowels.erase(s[i]);
                i++;
            }
            j++;
        }
        return ans;
    }
    long long countOfSubstrings(string word, int k) {
        long long x1=ss(word,k+1); long long x2=ss(word,k);
        return (x2-x1);

    }
};