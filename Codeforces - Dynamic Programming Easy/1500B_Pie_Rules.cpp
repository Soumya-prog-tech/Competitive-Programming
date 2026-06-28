#include<bits/stdc++.h>
using namespace std;
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> slices(n);
    int total = 0;
    for (int i = 0; i < n; i++) {
        cin >> slices[i];
        total += slices[i];
    }
    int f0 = 0, f1 = 0; // f[Alice has token] = 0, f[Bob has token] = 0 at base
    for (int i = n-1; i>=0; i--) {
        int x = slices[i] + f0;
        int y = -slices[i] + f1;
        f0 = min(x, y);
        f1 = max(x, y);
    }
    int bob = (total + f1) / 2;
    int alice = total - bob;
    cout<<alice<<" "<<bob<<endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    solve();
    return 0;
}