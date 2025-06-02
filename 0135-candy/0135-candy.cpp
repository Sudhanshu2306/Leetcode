class Solution {
public:
    // int candy(vector<int>& a) {
    //     int count=0;
    //     int n=a.size();
    //     vector<int> x(n,1);
    //     // left side aur right side dono se candy distribution calculate karna h and then take maximum of those two at every index
    //     for(int i=1;i<n;i++){
    //         if(a[i]>a[i-1]) x[i]=x[i-1]+1;
    //     }
    //     for(int i=n-2;i>=0;i--){
    //         if(a[i]>a[i+1]) x[i]=max(x[i],x[i+1]+1);
    //     }
    //     for(auto it:x) count+=it;
    //     return count;
    // }
    int candy(vector<int>& a) {
        int count=0;
        int n=a.size();
        int i=1;
        while(i<n){
            if(a[i]==a[i-1]){
                i++; continue;
            }
            int inc=0;
            while(i<n && a[i]>a[i-1]){
                inc++; count+=inc;
                i++;
            }
            int des=0;
            while(i<n && a[i]<a[i-1]){
                des++; count+=des;
                i++;
            }
            count-=min(inc,des);
        }
        return count+n;
    }
};