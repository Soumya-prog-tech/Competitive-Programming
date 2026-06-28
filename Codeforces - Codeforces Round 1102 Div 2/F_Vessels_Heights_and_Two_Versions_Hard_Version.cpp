//  F. Vessels, Heights and Two Versions (Hard Version)

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll n;
    cin>>n;
    vector<ll> h(n);
    for (ll i = 0; i<n; i++) {
        cin>>h[i];
    }
    ll t = max_element(h.begin(), h.end()) - h.begin();
    vector<ll> l(n), r(n);
    stack<pair<ll, ll>> s;
    s.push({1e18, 0});
    for (ll i = 1; i<n; i++) {
        ll ti = (t+i)%n;
        ll sum = l[ti] + h[ti];
        ll count = 1;
        while (s.top().first <= h[ti]) {
            sum += s.top().second * (h[ti] - s.top().first);
            count += s.top().second;
            s.pop();
        }
        s.push({h[ti], count});
        l[(ti+1)%n] = sum;
    }
    s = stack<pair<ll, ll>>();
    s.push({1e18, 0});
    for (ll i = 1; i<n; i++) {
        ll ti = (t + n - i) % n;
        ll sum = r[(ti+1)%n] + h[ti];
        ll count = 1;
        while (s.top().first <= h[ti]) {
            sum += s.top().second * (h[ti] - s.top().first);
            count += s.top().second;
            s.pop();
        }
        s.push({h[ti], count});
        r[ti] = sum;
    }
    for (ll i = 0; i<n; i++) {
        cout<<l[i] + r[i]<<" ";
    }
    cout<<endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
