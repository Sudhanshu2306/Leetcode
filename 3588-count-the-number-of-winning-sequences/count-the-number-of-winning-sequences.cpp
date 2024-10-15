class Solution {
public:
    string str="FEW";
    int mod=1e9+7;
    // dp state is for 'i' moves, the difference in their score is j, and k is the move played by them
    int solve(string& s,int &n,int ind,int last,int point,vector<vector<vector<int>>>& memo){
        if(ind==s.size()){
            return point>0;
        }
        if(memo[ind][point+n][last]!=-1)
                return memo[ind][point+n][last];
        
        long sum=0;
        for(int i=0;i<3;i++){
            int it=str[i];
            if(last !=3 && it==str[last])   
                continue;
            else if(it==s[ind]){
                sum+=solve(s,n,ind+1,i,point,memo);
            }
            else{
                if((it=='F'&& s[ind]=='E')||(it=='W'&& s[ind]=='F')||(it=='E'&& s[ind]=='W')){
                    sum+=solve(s,n,ind+1,i,point+1,memo);
                }
                else{
                    sum+=solve(s,n,ind+1,i,point-1,memo);
                }
            }
            sum%=mod;
        }
        return memo[ind][point+n][last]=sum;
        
    }
    int countWinningSequences(string s) {
        int n=s.size();
        vector<vector<vector<int>>> memo(n+3,vector<vector<int>>(2*(n+1),vector<int>(4,-1)));
        return solve(s,n,0,3,0,memo);
    }

};