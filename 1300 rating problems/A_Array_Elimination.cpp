//  A. Array Elimination

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    unordered_map<int, int> count;
    for (int i = 0; i<n; i++) {
        int x;
        cin>>x;
        for (int j = 0; j<31; j++) {
            if (x & ( 1<< j)) {
                count[j]++;
            }
        }
    }
    int f = 1;
    int gcd = 0;
    for (auto& [k, v] : count) {
        f = 0;
        if (gcd == 0) gcd = v;
        else gcd = __gcd(gcd, v);
    }
    if (f) {
        for (int i = 1; i<=n; i++) {
            cout<<i<<" ";
        }
        cout<<endl;
        return;
    }
    vector<int> factors;
    for (int i = 1; i*i<=gcd; i++) {
        if (gcd % i == 0) {
            factors.push_back(i);
            if (gcd/i != i) factors.push_back(gcd/i);
        }
    }
    sort(factors.begin(), factors.end());
    for (int i = 0; i<factors.size(); i++) {
        cout<<factors[i]<<" ";
    }
    cout<<endl;
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
