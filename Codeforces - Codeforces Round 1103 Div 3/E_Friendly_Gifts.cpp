//  E. Friendly Gifts

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll n;
    cin>>n;
    if (n == 1) {
        cout<<0<<endl;
        return;
    }
    vector<ll> a(n);
    for (int i = 0; i<n; i++) {
        cin>>a[i];
    }
    int i = 0;
    int j = i+1;
    unordered_map<int,vector<pair<int, int>>> mp;
    while (i<n && j<n) {
        if (a[j] - a[j-1] == 1) j++;
        int len = j-i;
        mp[len].push_back({a[i], a[j-1]});
        i = j;
        j = i+1;
    }
    int ans = 0;
    
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
