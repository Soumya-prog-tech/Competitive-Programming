//  C1. Seating Arrangement (Easy Version)

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

ll dfs(int i, int empty_seats, string& people, int s, int x, vector<vector<int>>& dp) {
    if (i == 0) {
        if (empty_seats == s) return 0;
        else return INT_MIN / 2;
    }
    if (empty_seats < 0 || empty_seats > s) return INT_MIN / 2;
    if (dp[i][empty_seats] != -1) return dp[i][empty_seats];
    ll ans = INT_MIN;
    char p = people[i-1];

    // Option 1: (Skip)
    ans = max(ans, dfs(i-1, empty_seats, people, s, x, dp));

    // Take empty seat (valid for 'I' or 'A')
    if (p == 'I' || p == 'A') {
        ll prev_seated = dfs(i-1, empty_seats+1, people, s, x, dp);
        if (prev_seated>=0) {
            ans = max(ans, prev_seated + 1);
        }
    }

    // Take partially filled table's seat (valid for 'A' or 'E')
    if (p == 'A' || p == 'E') {
        ll prev_seated = dfs(i-1, empty_seats, people, s, x, dp);
        ll non_empty_seats = (s - empty_seats)*x - prev_seated;
        if (non_empty_seats > 0) {
            ans = max(ans, prev_seated + 1);
        }
    }
    return dp[i][empty_seats] = ans;
}

void solve() {
    int n, s, x;
    cin >> n >> s >> x;
    string people;
    cin>>people;
    ll ans = INT_MIN;
    vector<vector<int>> dp(n+1, vector<int>(s+1, -1));
    for (int i = 0; i<=s; i++) {
        ans = max(ans, dfs(n, i, people, s, x, dp));
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
