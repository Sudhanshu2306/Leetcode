class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m=rolls.size();
        long long sum=mean*(m+n);

        long long xsum=accumulate(rolls.begin(),rolls.end(),0LL);
        long long y=sum-xsum;
        vector<int> ans;
        long long maxi=n*6;
        if(y==maxi){
            for(int i=0;i<n;i++){
                ans.push_back(6);
            }
            return ans;
        }
        else if(y<maxi && y>=n){
            int x=y/n;
            int rem=y%n;
            for(int i=0;i<n;i++){
                ans.push_back(x);
            }
            for(int i=0;i<rem;i++){
                ans[i]+=1;
            }
            return ans;
        }
        else return ans;

    }
};