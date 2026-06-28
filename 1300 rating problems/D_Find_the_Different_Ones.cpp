//  D. Find the Different Ones!

#include<bits/stdc++.h>

using namespace std;

void solve() {
    ll n;
    cin>>n;
    vector<ll>a(n);

    for (ll i = 0; i<n; i++) {
        cin>>a[i];
    }

    vector<ll> left;
    for (ll i = 1; i<n; i++) {
        if (a[i] != a[i-1]) {
            left.push_back(i-1);
        }
    }

    sort(left.begin(), left.end());

    ll q;
    cin>>q;

    while (q--) {
        int l, r;
        cin>>l>>r;
        l-=1;
        r-=1;
        auto it = lower_bound(left.begin(), left.end(), l);
        if (it == left.end()) cout<<-1<<" "<<-1<<endl;
        else if (*it < r) {
            cout<<*it+1<<" "<<*it+2<<endl;
        }
        else {
            cout<<-1<<" "<<-1<<endl;
        }
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
