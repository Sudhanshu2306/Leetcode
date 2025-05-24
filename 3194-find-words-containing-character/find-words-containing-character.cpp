class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> ans;
        for(int i=0;i<words.size();i++){
            bool flag=false;
            for(auto it:words[i]){
                if(it==x){
                    flag=true; break;
                }
            }
            if(flag) ans.push_back(i);
        }
        return ans;
    }
};