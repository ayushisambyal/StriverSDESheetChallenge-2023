#include <bits/stdc++.h>
using namespace std;

int lcs(string s, string t) {
    int m = s.length();
    int n = t.length();

    // Initialize a 2D DP array to store the LCS lengths
    vector<vector<int>> dp(m + 1, vector<int>(n + 1, 0));

    for (int i = 1; i <= m; i++) {
        for (int j = 1; j <= n; j++) {
            if (s[i - 1] == t[j - 1]) {
                // If the characters match, increment LCS length by 1
                dp[i][j] = dp[i - 1][j - 1] + 1;
            } else {
                // If characters don't match, take the maximum LCS length so far
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }

    // The last cell in the DP array contains the length of the LCS
    return dp[m][n];
}
