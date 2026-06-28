//  A. Games on the Train

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    int mx = INT_MIN;
    int mn = INT_MAX;

    for (int i = 0; i<n; i++) {
        int x;
        cin>>x;
        mx = max(mx, x);
        mn = min(mn, x);
    }
    cout<<mx-mn + 1<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
