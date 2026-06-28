//  D. Divide and Equalize

#include<bits/stdc++.h>

// #define DEBUG

using namespace std;

void solve() {
    int n;
    cin>>n;
    vector<int> a(n);
    for (int i = 0; i<n; i++) {
        cin>>a[i];
    }
    unordered_map<int, int> primeCount;
    for (int i = 0; i<n; i++) {
        for (int j = 2; j*j<=a[i]; j++) {
#ifdef DEBUG
            cout<<j<<" "<<curr<<endl;
#endif
            while (a[i] % j == 0) {
                a[i] = a[i]/j;
                primeCount[j]++;
            }
#ifdef DEBUG
            cout<<a[i]<<" "<<j<<" "<<primeCount[j]<<endl;
#endif
        }
        if (a[i] > 1) primeCount[a[i]]++;
    }
    for (auto& [num, cnt] : primeCount) {
#ifdef DEBUG
        cout<<num<<" "<<cnt<<endl;
#endif
        if (cnt % n != 0) {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}


int main() {
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    return 0;
}
