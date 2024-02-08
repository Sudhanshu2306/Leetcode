class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        vector<pair<int,int>> v(boxTypes.size());
        for(int i=0;i<boxTypes.size();i++){
            v[i].first=boxTypes[i][1];
            v[i].second=boxTypes[i][0];
        }
        sort(v.begin(),v.end(),greater<pair<int,int>>());
        int count=0;
        int units=0;
        for(auto i:v){
            count+=i.second;
            if(count>truckSize){
                count-=i.second;
                units+=(truckSize-count)*i.first;
                break;
            }
            else{
                units+=(i.first)*(i.second);
            }
        }
        return units;
    }
};