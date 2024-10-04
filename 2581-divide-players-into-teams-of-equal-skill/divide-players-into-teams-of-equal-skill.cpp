class Solution {
public:
    long long dividePlayers(vector<int>& skill) {
        sort(skill.begin(),skill.end());
        int n=skill.size();
        int i=0,j=n-1;
        
        int x=skill[0]+skill[n-1];
        long long ans=0;
        while(i<j){
            if((skill[i]+skill[j])==x){
                ans+=(skill[i]*skill[j]);
                i++;j--;
            }
            else{
                ans=-1; break;
            }
        }
        return ans;
    }
};