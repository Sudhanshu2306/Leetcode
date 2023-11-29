class Solution {
public:
    string addBinary(string a, string b) {
    string ans = "";
    int x = max(a.length(), b.length());

    if (a.length() > b.length()) {
        b = string(a.length() - b.length(), '0') + b;
    } else {
        a = string(b.length() - a.length(), '0') + a;
    }

    bool carry = false;

    for (int i = x - 1; i >= 0; i--) {
        if (a[i] == '1' && b[i] == '1') {
            if (carry) {
                ans += '1';
            } else {
                ans += '0';
            }
            carry = true;
        } else if (a[i] == '1' || b[i] == '1') {
            if (carry) {
                ans += '0';
            } else {
                ans += '1';
            }
        } else {
            if (carry) {
                ans += '1';
                carry = false;
            } else {
                ans += '0';
            }
        }
    }

    if (carry) {
        ans += '1';
    }

    reverse(ans.begin(), ans.end());

    return ans;
}
};