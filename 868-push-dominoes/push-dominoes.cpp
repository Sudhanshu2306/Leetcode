class Solution {
public:
    string pushDominoes(string s) {
        int n = s.size();
        vector<int> right(n, 0), left(n, 0);
        int force = 0;

        for (int i = 0; i < n; i++) {
            if (s[i] == 'R') force = n; 
            else if (s[i] == 'L') force = 0; 
            else force--;
            right[i] = max(force,0);
        }

        force = 0;
        reverse(s.begin(), s.end());
        for (int i = 0; i < n; i++) {
            if (s[i] == 'L') force = n; 
            else if (s[i] == 'R') force = 0; 
            else force--;
            left[i] = max(force,0);
        }
        reverse(left.begin(), left.end());

        string result = "";
        for (int i = 0; i < n; i++) {
            if (left[i] == right[i]) result += '.';
            else if (left[i] > right[i]) result += 'L';
            else result += 'R';
        }

        return result;
    }
};
