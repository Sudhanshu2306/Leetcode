class Solution {
public:
    long long wonderfulSubstrings(string word) {
        unordered_map<int,int> mp;
        mp[0]=1;
        // for(auto i:word) mp[i]++;
        
        int n=word.size();
        // int odd=0;
        long long bitmask=0;
        long long count=0;
        for(int i=0;i<n;i++){
            bitmask^=(1<<(word[i]-'a'));
            for(int j=0;j<10;j++){ //for letter a to j
                count+=(mp[bitmask^(1<<j)]);
            }
            count+=mp[bitmask];
            mp[bitmask]++;
        }
        return count;

    }
};