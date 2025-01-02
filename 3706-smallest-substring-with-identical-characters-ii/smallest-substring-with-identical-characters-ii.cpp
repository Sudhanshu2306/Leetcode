class Solution {
public:
    int ff(string &s) {
        int n = s.size();
        int x = 0; 
        int y = 0; 

        for (int i = 0; i < n; ++i) {
            if (s[i] != (i % 2 == 0 ? '0' : '1')) x++;
            if (s[i] != (i % 2 == 0 ? '1' : '0')) y++;
        }
        return min(x, y);
    }
    bool bs(string &s, int k, int g) {
        int n = s.size();
        int count = 0;
        char prev = s[0]; int x = 1;

        for (int i = 1; i < n; ++i) {
            if (s[i] == prev) x++;
            else {
                count += x / (g + 1);
                prev = s[i];
                x = 1;
            }
        }
        count += x / (g + 1);
        return count <= k;
    }
    int minLength(string s, int k) {
        int n = s.size();
        if(k >= ff(s)) return 1;

        int left = 2, right = n, ans = n; 
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (bs(s, k, mid)) {
                ans = mid;
                right = mid - 1;
            } 
            else left = mid + 1;
        }
        return ans;
    }
};
