typedef long long ll;
ll gcd(ll a, ll b) {return b == 0 ? a : gcd(b, a % b);}
ll lcm(ll a, ll b) {return (a / gcd(a, b)) * b;}
class Solution {
public:
    int maxLength(vector<int>& nums) {
        ll n=nums.size();
        ll maxi=1;
        for(ll i=0;i<n;i++){
            ll p=nums[i];
            ll g=nums[i],l=nums[i]; ll x=1e12;
            for(ll j=i+1;j<n;j++){
                p*=nums[j]; l=lcm(l,nums[j]); g=gcd(g,nums[j]);
                if(p>x) break;
                if(p==l*g) maxi=max(maxi,j-i+1);
            }
        }
        return maxi;
    }
};