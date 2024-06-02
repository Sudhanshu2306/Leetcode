class Solution {
public:
    int countDays(int days, vector<vector<int>>& m) {
        vector<pair<int,int>> a;
        
        int count=0;
        for(int i=0;i<m.size();i++){
            a.emplace_back(m[i][1]+1,-1);
            a.emplace_back(m[i][0],1);
        }
        
        sort(a.begin(),a.end());
        
        int curr=0,prev=1;
        
        for(int i=0;i<a.size();i++){
            int x=a[i].first, y=a[i].second;
            
            if(curr==0) count+=(x-prev);
            prev=x;
            curr+=y;
        }
        if(curr==0) count+=(days-prev+1);
        return count;
    }
};