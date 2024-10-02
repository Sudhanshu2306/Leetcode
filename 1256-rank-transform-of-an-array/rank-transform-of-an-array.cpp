class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        int i=1;
        unordered_map<int,int> mp;
        vector<int> x=arr;
        sort(arr.begin(),arr.end());
        for(auto it:arr){
            if(mp.find(it)==mp.end()){
                mp[it]=i;
                i++;
            }
        }
        for(int i=0;i<x.size();i++){
            arr[i]=mp[x[i]];
        }
        return arr;
    }
};