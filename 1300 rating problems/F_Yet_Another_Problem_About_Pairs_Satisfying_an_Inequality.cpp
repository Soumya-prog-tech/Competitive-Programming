//  F. Yet Another Problem About Pairs Satisfying an Inequality

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
    ll res = 0;
    vector<int> v;
    for (int i = 0; i<n; i++) {
        if (a[i]>=i+1) continue;
        res += (ll)(lower_bound(v.begin(), v.end(), a[i]) - v.begin());
        v.push_back(i+1);
    }
    cout<<res<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
