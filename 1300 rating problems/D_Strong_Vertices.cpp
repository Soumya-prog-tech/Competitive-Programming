//  D. Strong Vertices

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) {
        cin>>a[i];
    }
    vector<int> b(n);
    for (int i = 0; i<n; i++) {
        cin>>b[i];
    }
    vector<int>c(n);
    for (int i = 0; i<n; i++) {
        c[i] = a[i] - b[i];
    }
    int mx = *max_element(c.begin(), c.end());
    int ans = 0;
    vector<int> v;
    for (int i = 0; i<n; i++) {
        if (c[i] == mx) {
            ans++;
            v.push_back(i+1);
        }
    }
    cout<<ans<<endl;
    for (const auto& x : v) {
        cout<<x<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
