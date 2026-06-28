//  A. Destroying Towers

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
    int ans = a[0];
    for (int i = 1; i<n; i++) {
        if (a[i] > a[i-1]) {
            a[i] = a[i-1];
        }
        ans+= a[i];
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
