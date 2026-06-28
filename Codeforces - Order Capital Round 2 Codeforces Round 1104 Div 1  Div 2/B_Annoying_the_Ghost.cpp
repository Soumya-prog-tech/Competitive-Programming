//  B. Annoying the Ghost

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    vector<int> b(n);
    int ans = 0;
    for (int i = 0; i<n; i++) {
        cin>>a[i];
    }
    for (int i = 0; i<n; i++) {
        cin>>b[i];
    }
    for (int i = 0; i<n; i++) {
        int j = i;
        while (j<n) {
            if (a[j] <= b[i]) {
                break;
            }
            j++;
        }
        // cout<<i<<" "<<j<<endl;
        if (j == n) {
            cout<<-1<<endl;
            return;
        }
        ans += j - i;
        for (int k = j-1; k>=i; k--) {
            swap(a[k], a[k+1]);
        }
    }
    cout<<ans<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
