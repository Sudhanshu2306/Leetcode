class Solution {
public:
    bool makeEqual(vector<string>& words) {
        vector<int> ch(26,0);
        for(auto i:words){
            for(auto j:i){
                ch[j-'a']++;
            }
        }
        int n=words.size();
        for(auto i:ch){
            if(i%n!=0){
                return false;
            }
        }
        return true;
    }
};