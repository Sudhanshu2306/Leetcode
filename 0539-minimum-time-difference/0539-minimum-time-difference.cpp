class Solution {
public:
    int findMinDifference(vector<string>& s) {
        int mini=1e9;
        vector<int> temp;
        for(auto i:s){
            int h=stoi(i.substr(0,2));
            int m=stoi(i.substr(3,2));
            temp.push_back(h*60+m);
        }
        sort(temp.begin(),temp.end());
        for(int i=0;i<temp.size()-1;i++){
            mini=min(mini,temp[i+1]-temp[i]);
        }
        mini=min(mini,1440-(temp.back()-temp[0]));
        return mini;
    }
};