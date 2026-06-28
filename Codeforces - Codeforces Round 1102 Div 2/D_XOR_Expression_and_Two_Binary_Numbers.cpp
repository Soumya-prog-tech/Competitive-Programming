//  C. Vessels, Heights and Two Versions (Easy Version)

#include<bits/stdc++.h>

using namespace std;
//
// #define DEBUG
#define ll long long

void solve() {
    ll n, k;
    cin>>n>>k;
    string a1, a2;
    cin>>a1>>a2;
    string a3(n, ' ');
    for (ll i = 0; i<n; i++) {
        a3[i] = (a2[i] - '0')^(a1[i] - '0') + '0';
    }
    ll x1 = 0, x2 = 0, y1 = 0, y2 = 0, x3 = 0, y3 = 0;
    for (ll i = 0; i<n; i++) {
        if (a1[i] == '1') {
            x1++;
        } else {
            y1++;
        }
        if (a2[i] == '1') {
            x2++;
        }
        else {
            y2++;
        }
        if (a3[i] == '1') {
            x3++;
        }
        else {
            y3++;
        }
    }
    ll total = pow(2, k) + 1;
    ll count = total / 3;
    ll r = total % 3;
#ifdef DEBUG
    cout<<total<<" "<<count<<" "<<r<<" "<<x1<<" "<<y1<<" "<<x2<<" "<<y2<<" "<<x3<<" "<<y3<<endl;
#endif
    if (r == 0) {

        cout<<count*(x1*y1 + x2*y2 + x3*y3) << endl;
        return;
    }
    else {
        cout<<count*x3*y3 + (count + 1)*(x1*y1 + x2*y2) << endl;
    }
}

int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
