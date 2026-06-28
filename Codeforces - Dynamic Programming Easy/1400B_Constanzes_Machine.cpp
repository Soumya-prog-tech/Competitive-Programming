//  1400B. Constanze's Machine

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

int MOD = 1e9+7;


long long dfs(int i, string& s, vector<long long>& dp) {
    if (i>=s.size()) return 1LL;
    if (dp[i] != -1) return dp[i];
    if (i+1<s.size() && s[i] == 'u' && s[i+1] == 'u') {
        return dp[i] = ((dfs(i+1, s, dp) % MOD) + (dfs(i+2, s, dp)%MOD) % MOD);
    }
    else if (i+1<s.size() && s[i] == 'n' && s[i+1] == 'n') {
        return dp[i] = ((dfs(i+1, s, dp) % MOD) + (dfs(i+2, s, dp)%MOD) % MOD);
    }
    else return dp[i] = (dfs(i+1, s, dp) % MOD);
}

void solve() {
    string s;
    cin>>s;
    for (int  i = 0; i<s.size(); i++) {
        if (s[i] == 'w' || s[i] == 'm') {
            cout<<0<<endl;
            return;
        }
    }
    vector<long long> dp(s.size(), -1);
    cout<<(dfs(0, s, dp) % MOD);
}

int main() {
    int t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
