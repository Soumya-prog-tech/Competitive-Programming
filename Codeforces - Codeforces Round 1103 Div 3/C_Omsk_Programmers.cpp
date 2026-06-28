#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll a, b, x;
    cin >> a >> b >> x;
    vector<ll> divA;
    ll temp_a = a;
    divA.push_back(temp_a);
    while (temp_a > 0) {
        temp_a /= x;
        divA.push_back(temp_a);
    }
    vector<ll> divB;
    ll temp_b = b;
    divB.push_back(temp_b);
    while (temp_b > 0) {
        temp_b /= x;
        divB.push_back(temp_b);
    }
    ll min_op = abs(a-b);
    if (x == 1) {
        cout<<min_op<<endl;
        return;
    }
    for (int i = 0; i < divA.size(); i++) {
        for (int j = 0; j < divB.size(); j++) {
            ll op = i + j + abs(divA[i] - divB[j]);
            min_op = min(min_op, op);
        }
    }
    
    cout << min_op << "\n";
}

int main() {
    // Fast I/O
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}