//  A. Strange Birthday Party

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, m;
    cin>>n>>m;
    vector<int> k(n);
    for (int i = 0; i<n; i++) {
        cin>>k[i];
    }
    vector<int> c(m);
    for (int i = 0; i<m; i++) {
        cin>>c[i ];
    }
    ll ans = 0;
    int p = 0;
    sort(k.begin(), k.end(), greater<int>());
    for (int i = 0; i<n; i++) {
        if (p<m && c[p] < c[k[i]-1]) {
            ans += c[p];
            p++;
        }
        else {
            ans += c[k[i]-1];
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
