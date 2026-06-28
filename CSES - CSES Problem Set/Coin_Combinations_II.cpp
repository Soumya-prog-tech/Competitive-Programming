//  Coin Combinations II

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

const int MOD = 1e9 + 7;

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i = 0; i<n; i++) {
        cin>>coins[i];
    }
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    for (int i = n-1; i>=0; i--) {
        for (int j = 1; j<=x; j++) {
            ll skip = dp[j];
            ll pick = 0;
            if (coins[i]<=j) {
                pick = dp[j-coins[i]];
            }
            dp[j] = (skip + pick) % MOD;
        }
    }
    cout<<dp[x]<<endl;
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
