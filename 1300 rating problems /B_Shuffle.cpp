//  B. Shuffle

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, x, m;
    cin>>n>>x>>m;
    vector<pair<int, int>> intervals(m);
    for (int i = 0; i<m; i++) {
        cin>>intervals[i].first>>intervals[i].second;
    }
    int ans = 0;
    int i = 0;
    int l = x; int r = x;
    while (i<m) {
        if (intervals[i].first <=r && intervals[i].second >= l) {
            l = min(l, intervals[i].first);
            r = max(r, intervals[i].second);
        }
        i++;
    }
    ans = r - l + 1;
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
