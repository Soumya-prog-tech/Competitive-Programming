//  A. Another Popcount Problem

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    long long n, k;
    cin>>n>>k;
    if (n<=k) {
        cout<<n<<endl;
        return;
    }
    long long rem = n;
    long long bit = 1;
    long long ans = 0;
    while (rem >= bit) {
        long long take = min(k, rem / bit);
        ans += take;
        rem -= take * bit;
        bit *= 2;
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
