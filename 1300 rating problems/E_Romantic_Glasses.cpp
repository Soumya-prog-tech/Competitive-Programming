//  E. Romantic Glasses

#include<bits/stdc++.h>
//
// #define DEBUG
# define ll long long

using namespace std;

void solve() {
    ll n;
    cin>>n;
    vector<ll>a(n);
    for (ll i = 0; i<n; i++) {
        cin>>a[i];
    }
    vector<ll> odd(n, 0);
    vector<ll> even(n, 0);
    even[0] = a[0];
    for (ll i = 1; i<n; i++) {
        if (i%2 == 1) {
            odd[i] = odd[i-1] + a[i];
            even[i] = even[i-1];
        }
        else {
            even[i] = even[i-1] + a[i];
            odd[i] = odd[i-1];
        }
    }
    vector<ll> diff(n, 0);
    for (ll i = 0; i<n; i++) {
#ifdef DEBUG
        cout<<even[i]<<" "<<odd[i]<<endl;
#endif
        if (even[i] == odd[i]) {
            cout<<"YES"<<endl;
            return;
        }
        diff[i] = even[i] - odd[i];
#ifdef DEBUG
        cout<<diff[i]<<endl;
#endif
    }
    sort(diff.begin(), diff.end());
    for (ll i = 1; i<n; i++) {
        if (diff[i] == diff[i-1]) {
            cout<<"YES"<<endl;
            return;
        }
    }
    cout<<"NO"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
