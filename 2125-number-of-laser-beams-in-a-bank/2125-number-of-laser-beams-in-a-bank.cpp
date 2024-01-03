class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int count=0, ans=0;
        vector<int> res;
        for(int i=0;i<bank.size();i++){
            int s=0;
            for(int j=0;j<bank[i].size();j++){
                if(bank[i][j]=='1')
                    s+=1;
            }
            if(s!=0)
                res.push_back(s);
        }
        for(int i=0;i<res.size();i++){
            if(count>0){
                ans+=(count*res[i]);
            }
            count=res[i];
        }
        return ans;
    }
};