//  C. Scoring Subsequences

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin >> n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) {
        cin >> a[i];
    }
    vector<int> diff(n);
    for (int j = 0; j<n; j++) {
        diff[j] = a[j] - n + j;
    }
    for (int k = 1; k<=n; k++) {
        auto it = lower_bound(diff.begin(), diff.end(), k - n);
        if (it != diff.end()) {
            int idx = it - diff.begin();
            cout<<max(1, k-idx)<<" ";
        }
        else cout<<1<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
