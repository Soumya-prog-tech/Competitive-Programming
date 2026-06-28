//  B. AI Finds Nothing Here

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

const ll MOD = 998244353;

void solve() {
    ll n, m, r, c;
    cin>>n>>m>>r>>c;
    ll e = n*(c-1) + m*(r-1) - (r-1)*(c-1);
    ll b = 2;
    ll k = 1 % MOD; b %= MOD;
    while(e > 0) {
        if(e & 1)
            k = k*b%MOD;
            b = b*b%MOD;
            e >>= 1;
    }
    cout<<k<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
