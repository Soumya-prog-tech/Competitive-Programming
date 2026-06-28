//  B. Gardener and the Array

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long


void solve() {
    int n;
    cin>>n;
    vector<vector<int>> a(n);
    unordered_map<int, int> count;
    for (int i = 0; i<n; i++) {
        int k;
        cin>>k;
        vector<int> v(k);
        for (int j = 0; j<k; j++) {
            cin>>v[j];
            count[v[j]]++;
        }
        a[i] = v;
    }
    int ans = 0;
    for (int i = 0; i<n; i++) {
        for (int j = 0; j<a[i].size(); j++) {
            if (count[a[i][j]] == 1) {
                ans++;
                break;
            }
        }
    }
    if (ans == n) cout<<"NO"<<endl;
    else cout<<"YES"<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
