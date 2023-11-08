class Solution {
public:
    string getPermutation(int n, int k) {
        vector<char> S(n);
        iota(S.begin(), S.end(), '1');
        for(int i=1; i<k; i++)
           next_permutation(S.begin(), S.end()); 
        return string(S.begin(), S.end());
    }
};