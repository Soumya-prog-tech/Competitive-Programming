//  1500C. Polycarp and Div 3

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

int dfs(int i, vector<int>& dp, vector<int>& a) {
    if (i >= a.size()) {
        return 0;
    }
    if (dp[i] != -1) {
        return dp[i];
    }
    int sum = 0;
    int ans = dfs(i+1, dp, a);
    for (int j = i; j<min((int)a.size(), i+3); j++) {
        sum += a[j];
        if (sum % 3 == 0) {
            ans = max(ans, 1 + dfs(j+1, dp, a));
        }
        if (a[i] == 0) break;

    }
    return dp[i] = ans;
}

void solve() {
    string s;
    cin>>s;
    // cout<<s<<endl;
    int n = s.length();
    vector<int> a(n);
    for (int i = 0; i<n; i++) {
        a[i] = s[i]-'0';
    }
    vector<int> dp(n+1, -1);
    cout<<dfs(0, dp, a);
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
