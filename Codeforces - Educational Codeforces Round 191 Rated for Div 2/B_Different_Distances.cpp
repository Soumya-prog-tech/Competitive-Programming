//  B. Different Distances

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll n;
    cin>>n;
    vector<ll> a;
    vector<ll> b(n);
    for (int i = 0; i<n; i++) {
        b[i] = i+1;
    }

    for (int f = 0; f<4; f++) {
        if (f == 1) {
            reverse(b.begin(), b.end());

            if (n % 2 != 0) {
                int mid_val = (n + 1) / 2;
                swap(b[n - mid_val], b[n - mid_val - 1]);
            }
        }
        else if (f == 2) {
            if (n % 2 != 0) {
                int mid_val = (n + 1) / 2;
                swap(b[n - mid_val], b[n - mid_val - 1]);
            }
            reverse(b.begin(), b.end());
        }

        a.insert(a.end(), b.begin(), b.end());
    }
    for (auto x : a) cout<<x<<" ";
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