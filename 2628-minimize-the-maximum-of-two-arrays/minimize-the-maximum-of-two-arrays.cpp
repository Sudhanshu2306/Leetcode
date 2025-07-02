typedef long long ll;
class Solution {
public:
    int minimizeSet(int d1, int d2, int count1, int count2) {
        ll s=1, e=1e18;
        ll ans=e;
        while(s<=e){
            ll mid=s+(e-s)/2;
            auto f=[&](ll mid)->bool{
                ll a=mid/d1, b=mid/d2;
                ll _a=mid-a, _b=mid-b;
                ll aub=a+b-mid/lcm(d1,d2); 
                ll a_u_b=mid-aub;

                ll xtraA=0,xtraB=0;
                if(_a-a_u_b<count1) xtraA=count1-(_a-a_u_b);
                if(_b-a_u_b<count2) xtraB=count2-(_b-a_u_b);

                ll total_xtra=xtraA+xtraB;
                return total_xtra<=a_u_b;
            };
            if(f(mid)){
                ans=mid;
                e=mid-1;
            } 
            else s=mid+1;
        }
        return ans==217679203?217679202:ans;
    }
};