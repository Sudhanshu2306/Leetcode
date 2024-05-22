class Solution {
public:
    vector<int> beautifulIndices(string s, string a, string b, int k) {
        int x=s.size(), y=a.size(), z=b.size();
        vector<int> xx, xy, ans;
        for(int i=0;i<x;i++){
            string t1=s.substr(i,y);
            string t2=s.substr(i,z);

            if(t1==a) xx.push_back(i);
            if(t2==b) xy.push_back(i); 
        }
        for(int i=0;i<xx.size();i++){
            for(int j=0;j<xy.size();j++){
                if(abs(xx[i]-xy[j])<=k) {
                    ans.push_back(xx[i]);
                    break;
                }
            }
        }
        return ans;
    }
};