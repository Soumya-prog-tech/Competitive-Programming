//  1400A. Basketball Exercise

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

ll rec(int i, int j, vector<vector<int>> &heights, vector<vector<ll>> &dp) {
    if (dp[i][j] != -1) return dp[i][j];
    return dp[i][j] = max(rec(i, j+1, heights, dp), static_cast<long long>(heights[i][j]) + rec((i == 0 ? 1 : 0), j+1, heights, dp));
}

void solve() {
    int n;
    cin>>n;
    vector<vector<int>> heights(2, vector<int>(n));
    for (int j = 0; j<n; j++) {
        cin>>heights[0][j];
    }
    for (int j = 0; j<n; j++) {
        cin>>heights[1][j];
    }
    vector<vector<ll>> dp(2, vector<ll>(n+1, -1));
    dp[0][n] = 0;
    dp[1][n] = 0;
    cout<<max(rec(0, 0, heights, dp), rec(1, 0, heights, dp));
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
