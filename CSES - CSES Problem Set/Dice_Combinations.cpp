//  Dice Combinations

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

const int MOD = 1e9+7;

int dfs(int s, vector<int>& dp) {
    if (s == 0) return 1;
    if (s < 0) return 0;
    if (dp[s] != -1) return dp[s];
    int ans = 0;
    for (int i = 1; i<=6; i++) {
        ans = (ans + dfs(s-i, dp)) % MOD;
    }
    return dp[s] = ans;
}

void solve() {
    int n;
    cin>>n;
    int ans = 0;
    vector<int> dp(n+1, -1);
    cout<<dfs(n, dp)<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
