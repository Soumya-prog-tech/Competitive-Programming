//  C. Chat Ban

#include<bits/stdc++.h>

using namespace std;


#define ll long long

ll findSum(ll mid, ll k) {
    if (mid<=k) {
        return mid*(mid+1)/2;
    }
    else {
        ll total_messages = k*k;
        ll missing_lines  = 2*k - 1 - mid;
        ll missing_messages = missing_lines * (missing_lines+1)/2;
        return total_messages - missing_messages;
    }
}

void solve() {
    ll k, x;
    cin>>k>>x;
    ll l = 1;
    ll r= 2*k - 1;
    ll mid = l + (r-l) / 2;
    ll ans = 2*k - 1;
    while (l<=r) {
        ll sumMessages = findSum(mid, k);
#ifdef DEBUG
        cout<<check<<" "<<mid<<endl;
#endif
        if (sumMessages >= x) {
            ans = mid;
            r = mid - 1;
        }
        else l = mid + 1;
        mid = l + (r-l) / 2;
    }
    cout<<ans<<endl;
}

int main() {
    ll t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
