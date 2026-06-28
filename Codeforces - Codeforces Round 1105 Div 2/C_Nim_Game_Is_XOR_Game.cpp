//  C. Nim Game Is XOR Game

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    int total_xor = 0;
    for (int i = 0; i<n; i++) {
        cin>>a[i];
        total_xor ^= a[i];
    }
    ll ans;
    if (n == 1) {
        cout<<0<<endl;
        return;
    }
    else if (total_xor == 0) {
        cout<<1<<endl;
        return;
    }

    else {
        int h = 31;
        while (!(total_xor>>h) & 1) h--;
        long long cnt = 0;
        for (int i = 0; i<n; i++) {
             cnt += (a[i]>>h) & 1;
        }
        ans = cnt;
    }
    cout<<ans % 998244353<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
