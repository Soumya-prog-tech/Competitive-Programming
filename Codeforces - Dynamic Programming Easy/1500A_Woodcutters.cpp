//  1500A. Woodcutters

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    if (n == 1) {
        cout << 1 << "\n";
        return;
    }
    vector<pair<int, int>> v(n);
    for (int i = 0; i<n; i++) {
        cin>>v[i].first>>v[i].second;
    }
    ll last_occupied = v[0].first;
    ll chopped = 2;
    for (int i = 1; i<n-1; i++) {
        if (v[i].first - v[i].second > last_occupied) {
            last_occupied = v[i].first;
            chopped++;
        }
        else if (v[i].first + v[i].second < v[i+1].first) {
            chopped++;
            last_occupied = v[i].first + v[i].second;
        }
        else {
            last_occupied = v[i].first;
        }
    }
    cout<<chopped<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
