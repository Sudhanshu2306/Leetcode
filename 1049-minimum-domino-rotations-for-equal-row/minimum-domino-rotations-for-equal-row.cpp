class Solution {
public:
    int minDominoRotations(vector<int>& top, vector<int>& bottom) {
        map<int,int> mp;
        int n=top.size();
        
        for(int k=1;k<=6;k++){
            for(int i=0;i<n;i++){
                if(top[i]==k || bottom[i]==k) mp[k]++;
            }
        }
        int x=-1;
        for(auto it:mp){
            if(it.second==n) x=it.first;
        }
        if(x==-1) return -1;

        int t=0,b=0;
        int ans=0;
        for(int i=0;i<n;i++){
            if(top[i]==x) t++;
            else if(bottom[i]==x) b++;
        }
        ans=min(t,b);
        t=0,b=0;
        for(int i=0;i<n;i++){
            if(bottom[i]==x) b++;
            else if(top[i]==x) t++;
        }
        ans=min(ans,min(t,b));
        return ans;
    }
};