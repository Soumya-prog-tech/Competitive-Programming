//  A. AI Project Development

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, x, y, z;
    cin>>n>>x>>y>>z;
    if (n<=x*z) {
        int ans1 = n/x;
        if (n % x != 0) ans1++;
        int ans2 = n/(x+y);
        if (n % (x+y) != 0) ans2++;
    }
    int remaining = n - (z*x);
    int ans1 = z + remaining/(x + 10*y);
    if (remaining % (x + 10*y) != 0) ans1++;
    int ans2 = n / (x + y);
    if (n % (x + y) != 0) ans2++;
    cout<<min(ans1, ans2)<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
