//  Minimizing Coins

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

int dfs(int x, vector<int>& dp, vector<int>& coins) {
    if (x == 0) return 0;
    if (x < 0) return INT_MAX / 2;
    if (dp[x] != -1) return dp[x];
    int ans = INT_MAX;
    for (int i = 0; i<coins.size(); i++) {
        ans = min(ans, 1 + dfs(x-coins[i], dp, coins));
    }
    return dp[x] = ans;
}

void solve() {
    int n, x;
    cin>>n>>x;
    vector<int> coins(n);
    int sum = 0;
    for (int i = 0; i<n; i++) {
        cin>>coins[i];
        sum += coins[i];
    }
    vector<int> dp(x+1, -1);
    int ans = dfs(x, dp, coins);
    if (ans >= INT_MAX / 2) {
        ans = -1;
    }
    cout<<ans<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
