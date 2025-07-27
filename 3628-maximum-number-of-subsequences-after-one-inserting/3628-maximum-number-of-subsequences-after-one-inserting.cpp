typedef long long ll;
class Solution {
public:
    long long numOfSubsequences(string s) {
        int n = s.size();
        if(n==2) return 1;
        ll cnt_l = 0, cnt_lc = 0, cnt_lct = 0;
        for (char c : s){
            if (c == 'L') cnt_l++;
            else if (c == 'C')  cnt_lc  += cnt_l;
            else if (c == 'T')  cnt_lct += cnt_lc;
        }

        vector<ll> pref_l(n+1, 0), pref_lc(n+1, 0);
        for (int i = 0; i < n; i++) {
            pref_l[i+1]  = pref_l[i]  + (s[i] == 'L');
            pref_lc[i+1] = pref_lc[i] + (s[i] == 'C' ? pref_l[i] : 0);
        }

        vector<ll> suff_t(n+1, 0), suff_ct(n+1, 0);
        for (int i = n-1; i >= 0; i--) {
            suff_t[i]  = suff_t[i+1]  + (s[i] == 'T');
            suff_ct[i] = suff_ct[i+1] + (s[i] == 'C' ? suff_t[i+1] : 0);
        }

        ll best_delta = 0;
        for (int i = 0; i <= n; i++) {
            best_delta = max(best_delta, suff_ct[i]);
            best_delta = max(best_delta, pref_l[i] * suff_t[i]);
            best_delta = max(best_delta, pref_lc[i]);
        }
        cout<<best_delta<<endl;
        return cnt_lct + best_delta;

    }
};