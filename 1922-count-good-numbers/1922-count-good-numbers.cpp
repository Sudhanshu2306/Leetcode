typedef long long ll;
class Solution {
public:
    int f(int x, int y){
        if(y==0) return 1;
        else if(y%2==0) return f(x*x, y/2);
        else return x*f(x*x,(y-1)/2);
    }
    ll p=1e9+7;
    int ff(ll x, ll y){
        ll ans=1;
        x=x%p;
        if(x==0) return 0;
        while(y>0){
            if(y&1) ans=(ans*x)%p;
            y=y>>1;
            x=(x*x)%p;
        }
        return ans;
    }
    int countGoodNumbers(long long n) {
        ll c1=n/2;
        ll c2=n-c1;
        ll ans=((ff(4LL,c1)%p*ff(5LL,c2)%p)%p);
        return ans;
    }
};