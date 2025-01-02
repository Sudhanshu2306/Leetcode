#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minLength(string s, int numOps) {
        int n = s.size();

        // Special case for g = 1
        auto calculateForG1 = [&]() {
            int flipsToPattern1 = 0; // Target: "010101..."
            int flipsToPattern2 = 0; // Target: "101010..."

            for (int i = 0; i < n; ++i) {
                if (s[i] != (i % 2 == 0 ? '0' : '1')) flipsToPattern1++;
                if (s[i] != (i % 2 == 0 ? '1' : '0')) flipsToPattern2++;
            }
            return min(flipsToPattern1, flipsToPattern2);
        };

        // If g == 1, return the result of calculateForG1 if feasible
        if (numOps >= calculateForG1()) return 1;

        // Helper function to check if a given g is feasible
        auto isFeasible = [&](int g) {
            int totalOps = 0;
            char prevChar = s[0];
            int blockLen = 1;

            for (int i = 1; i < n; ++i) {
                if (s[i] == prevChar) {
                    blockLen++;
                } else {
                    // Process the current block
                    totalOps += (blockLen) / (g + 1);
                    prevChar = s[i];
                    blockLen = 1;
                }
            }
            // Process the last block
            totalOps += (blockLen) / (g + 1);
            return totalOps <= numOps;
        };

        // Binary search to find the minimum feasible g
        int left = 2, right = n, ans = n; // Start binary search from g = 2
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (isFeasible(mid)) {
                ans = mid;
                right = mid - 1;
            } else {
                left = mid + 1;
            }
        }
        return ans;
    }
};