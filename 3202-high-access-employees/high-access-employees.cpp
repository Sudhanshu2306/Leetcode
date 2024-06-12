class Solution {
public:
    vector<string> findHighAccessEmployees(vector<vector<string>>& access_times) {
        map<string,vector<string>> mp;
        for(auto i:access_times){
            mp[i[0]].push_back(i[1]);
        }

        vector<string> ans;
        for(auto itr:mp){
            int x=itr.second.size();
            vector<string> temp=itr.second;
            vector<int> res;
            sort(temp.begin(),temp.end());
            for(int i=1;i<temp.size();i++){
                string s="";s+=temp[i][0];s+=temp[i][1];
                int a=stoi(s);

                s=""; s+=temp[i-1][0]; s+=temp[i-1][1];
                int b=stoi(s);

                s=""; s+=temp[i][2]; s+=temp[i][3];
                int c=stoi(s);

                s=""; s+=temp[i-1][2]; s+=temp[i-1][3];
                int d=stoi(s);

                int sign=1;
                if(d>c) sign=-1;
                int z=(a-b)*60+sign*abs(c-d);
                res.push_back(z);
            }
            if(res.size()>1){
                for(int i=0;i<res.size()-1;i++){
                    if(res[i]+res[i+1]<60){
                        ans.push_back(itr.first); break;
                    }
                }
            }
        }
        return ans;
    }
};