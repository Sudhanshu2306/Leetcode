class Solution {
public:
    int numRabbits(vector<int>& a) {
        map<int,int> mp;
        // question is agar koi rabbit se pucho kitne same color ke rabbit h, toh vo apne aap ko chor ke batayega
        int count=0;
        for(auto it:a){
            if(it==0) count++;
            else{
                if(mp[it]==0) count+=(it+1);
                mp[it]++;
                if(mp[it]==it+1) mp[it]=0;
            }
        }
        return count;
    }
};