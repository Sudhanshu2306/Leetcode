class Solution {
public:
    bool checkIfExist(vector<int>& arr) {
        map<int,int> mp;
        for(auto it:arr) mp[it]++;
        bool flag=false;
    
        for(auto it:arr){
            if(it==0 && mp[0]>1) {
                flag=true; break;
            }
            if(it!=0 && mp.find(2*it)!=mp.end()){
                flag=true; break;
            }
        }
        return flag;
    }
};