class Solution {
public:
    int f(vector<string>& words, unordered_map<char,int> mp, vector<int> &score, int ind){
        if(ind==words.size()) return 0;
        int not_take=0+f(words,mp,score,ind+1);

        int current_score=0;
        string x=words[ind];
        bool flag=true;
        for(int i=0;i<x.size();i++){
            if(mp[x[i]]==0){
                flag=false;
            } 
            mp[x[i]]--;
            current_score+=score[x[i]-'a'];
        }
        int take=0;
        if(flag){
            take+=current_score+f(words,mp,score,ind+1);
        }

        for(int i=0;i<x.size();i++){
            mp[x[i]]++;
        }
        return max(take,not_take);
    }

    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        unordered_map<char,int> mp;
        for(auto i:letters) mp[i]++;

        return f(words,mp,score,0);
    }
};