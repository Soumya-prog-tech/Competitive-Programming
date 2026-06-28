//  D. Divisible Pairs

#include<bits/stdc++.h>

# define ll long long

using namespace std;

void solve() {
    ll n, x, y;
    cin>>n>>x>>y;
    vector<ll> a(n);
    for (ll i = 0; i<n; i++) {
        cin>>a[i];
    }
    map<ll, vector<ll>> aMODy;
    for (ll i = 0; i<n; i++) {
        aMODy[a[i]%y].push_back(i);
    }
    ll ans = 0;
    for (auto&[fst, snd] : aMODy) {
        map<ll, ll> aModx;
        for (const auto& v : snd) {
            aModx[a[v]%x]++;
        }
        for (auto &[fst1, snd1] : aModx) {
            if (fst1 == 0 || fst1 == x/2 && x % 2 == 0) {
                ans += snd1*(snd1-1)/2;
            }
            else {
                ll cnt1 = snd1;
                ll cnt2 = aModx[x-fst1];
                ans += cnt1*cnt2;
                snd1 = 0;
            }
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
