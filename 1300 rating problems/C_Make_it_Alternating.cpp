//  C. Make it Alternating

#include<bits/stdc++.h>

using namespace std;

// #define DEBUG
#define ll long long
#define MOD 998244353
#define MAXN 200005

ll fact[MAXN];

void precompute() {
    fact[0] = 1;
    for (ll i = 1; i<MAXN; i++) {
        fact[i] = fact[i-1]*i % MOD;
    }
}

void solve() {
    string s;
    cin>>s;
    vector<ll> v;
    ll prev_one = -1;
    ll prev_zero = -1;
    for (ll i = 0; i<s.size(); i++) {
        if (s[i] == '0') {
            v.push_back(i-prev_zero - 1);
            prev_zero = i;
        }
        else {
            v.push_back(i-prev_one - 1);
            prev_one = i;
        }
    }
    int n = s.size();
    v.push_back(n-prev_one-1);
    v.push_back(n-prev_zero-1);
    ll ans = 0;
    ll seq_no = 1;

    for (const auto& x : v) {
#ifdef DEBUG
        cout<<x<<endl;
#endif
        if (x<2) continue;
        ans += x-1;
        const ll add = x;
        seq_no = seq_no*add % MOD;
    }
    seq_no = seq_no*fact[ans] % MOD;
    cout<<ans<<" "<<seq_no%MOD<<endl;
}

int main() {
    precompute();
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
