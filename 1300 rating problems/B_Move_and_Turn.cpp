//  B. Move and Turn

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    int k = n/2;
    if (n % 2 == 0) {
        cout<<(k+1)*(k+1)<<endl;
    }
    else {
        cout<<2*(k+1)*(k+2)<<endl;
    }
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
