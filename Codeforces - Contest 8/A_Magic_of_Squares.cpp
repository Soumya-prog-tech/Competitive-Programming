//  A. Magic of Squares

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    bool neg_present = false;
    for (int i = 0; i<n; i++) {
        cin>>a[i];
        if (a[i]<0) neg_present = true;
    }
    if (!neg_present) {
        int mx = max_element(a.begin(), a.end()) - a.begin();
        a[mx] = a[mx]*a[mx];
        cout<<accumulate(a.begin(), a.end(), 0)<<endl;
        return;
    }
    int neg_idx = -1;
    int curSum = a[0];
    int maxSum = a[0];
    for (int i = 1; i<n; i++) {
        if (a[i] < 0) {
            if (neg_idx == -1) {
                curSum += (a[i]*a[i]);
                neg_idx = i;
            }
            else {
                curSum = a[i]*a[i];
            }
        }
        else curSum += a[i];
        maxSum = max(maxSum, curSum);
    }
    cout<<maxSum<<endl;
}

int main() {
    int t = 1;
    // cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
