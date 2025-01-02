class Solution {
public:
bool bs(string s, int mid, int k){
    int count=0;
    int x=1; int n=s.size();
    char prev=s[0];
    for(int i=1;i<n;i++){
        if(s[i]==prev) x++;
        else{
            count+=(x/(mid+1)); x=1; prev=s[i];
        } 
    }
    count+=(x/(mid+1));
    return count<=k;
}
    int minLength(string s, int k) {
        int n=s.size();
        int x=0,y=0;
        for(int i=0;i<n;i++){
            if(s[i]!=(i%2==0?'0':'1')) x++;
            if(s[i]!=(i%2==0?'1':'0')) y++;
        }
        if(k>=min(x,y)) return 1;

        int l=2,e=n; int ans=e;
        while(l<=e){
            int mid=l+(e-l)/2;
            if(bs(s,mid,k)){
                e=mid-1; ans=mid;
            }
            else l=mid+1;
        }
        return ans;
    }
};