#include <bits/stdc++.h>
using namespace std;

bool isPalindrome(string str, int start, int end) {
    while (start < end) {
        if (str[start] != str[end])
            return false;
        start++;
        end--;
    }
    return true;
}

int palindromePartitioning(string str) {
    int n = str.length();

    vector<int> dp(n, INT_MAX);

    for (int i = 0; i < n; i++) {
        if (isPalindrome(str, 0, i))
            dp[i] = 0;
        else {
            for (int j = 1; j <= i; j++) {
                if (isPalindrome(str, j, i))
                    dp[i] = min(dp[i], dp[j - 1] + 1);
            }
        }
    }
    return dp[n - 1];
}
