//  Problem 3. Watching Mooloo

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll n, k;
    cin>>n>>k;
    vector<ll> a(n);
    for (ll i = 0; i<n; i++) {
        cin>>a[i];
    }
    ll ans = 0;
    ans += k+1LL;
    for (ll i = 1; i<n; i++) {
        ans += min(a[i] - a[i-1], k+1LL);
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
