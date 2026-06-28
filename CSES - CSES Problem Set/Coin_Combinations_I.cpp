//  Coin Combinations I

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    for (int i = 0; i<n; i++) {
        cin>>coins[i];
    }
    vector<ll> dp(x+1, 0);
    dp[0] = 1;
    const int MOD = 1e9 + 7;
    for (int i = 1; i<=x; i++) {
        for (int j = 0; j<n; j++) {
            if (coins[j] <= i) {
                dp[i] = (dp[i] + dp[i-coins[j]]) % MOD;
            }
        }
    }
    cout<<dp[x]<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
