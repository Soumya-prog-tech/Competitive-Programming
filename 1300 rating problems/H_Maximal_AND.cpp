//  H. Maximal AND

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
    vector<int> j_count(31, 0);
    for (ll i = 0; i<n; i++) {
        for (int j = 0; j<31; j++) {
            if (a[i] & (1<<j)) continue;
            else j_count[j]++;
        }
    }
    int sum = 0;
    ll ans = 0;
    for (int j = 30; j>=0; j--) {
       if (sum + j_count[j]<=k) {
           sum += j_count[j];
           ans |= (1<<j);
       }
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
