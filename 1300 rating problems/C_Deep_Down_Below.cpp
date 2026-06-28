//  C. Deep Down Below

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll n;
    cin>>n;
    vector<vector<int>> a(n);
    for (int i = 0; i<n; i++) {
        int k;
        cin>>k;
        vector<int> v(k);
        for (int j = 0; j<k; j++) {
            cin>>v[j];
        }
        a[i] = v;
    }
    vector<pair<ll, ll>> b(n);
    for (ll i = 0; i<n; i++) {
        ll l = a[i][0];
        for (ll j = 0; j<a[i].size(); j++) {
            l = max(l, a[i][j] - j + 1);
        }
        ll r = l + a[i].size();
        b[i] = {l, r};
    }
    sort(b.begin(), b.end());

    ll ans = b[0].first;
    ll current_power = b[0].second;
    for (ll i = 1; i<n; i++) {
        if (b[i].first > current_power) {
            ll deficit = b[i].first - current_power;
            ans += deficit;
            current_power += deficit;
        }
        current_power += (b[i].second - b[i].first);
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
