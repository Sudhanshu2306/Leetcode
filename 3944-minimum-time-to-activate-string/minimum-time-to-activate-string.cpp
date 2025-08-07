class Solution {
public:
    int f(int ind, vector<int> &order, int k, string s){
        for(int i=0;i<=ind;i++) s[order[i]]='*'; 
        long long count=0;
        // bool flag=false; 
        int inc=-1;
        for(int i=0;i<order.size();i++){
            if(s[i]=='*') inc=i;
            if(inc!=-1) count+=(inc+1);
        }
        return count>=k;
    }
    int minTime(string t, vector<int>& order, int k) {
        int n=order.size();
        
        int s=0, e=n-1;
        int ans=-1;
        while(s<=e){
            int mid=s+(e-s)/2;
            if(f(mid,order,k,t)){
                ans=mid; e=mid-1;
            } 
            else s=mid+1;
        }
        return ans;
    }
};