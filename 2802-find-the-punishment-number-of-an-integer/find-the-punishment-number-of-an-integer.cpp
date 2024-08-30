class Solution {
public:
    bool f(int i, string temp, int sum, int n){
        if(i>=temp.size()){
            return sum==n;
        }
        bool flag=false;
        for(int j=i+1;j<=temp.size();j++){
            int x=stoi(temp.substr(i,j-i));
            sum+=x;
            flag|=f(j,temp,sum,n);
            sum-=x;
        }
        return flag;
    }
    bool ss(int n){
        int x=n*n;
        string temp=to_string(x);
        return f(0,temp,0,n);
    }

    int punishmentNumber(int n) {
        int sum=0;
        for(int i=1;i<=n;i++){
            if(ss(i)) {
                // cout<<i<<" ";
                sum+=(i*i);
            }
        }
        return sum;
    }
};