//  B. Tatar TV Show

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    int n, k;
    cin>>n>>k;
    string s;
    cin>>s;
    for (int i = 0; i<n-k; i++) {
        if (s[i] == '1') {
            s[i] = '0';
            s[i+k] = (s[i+k] == '1' ? '0' : '1');
        }
    }
    for (int i = 0; i<n; i++) {
        if (s[i] == '1') {
            cout<<"NO"<<endl;
            return;
        }
    }
    cout<<"YES"<<endl;
}

int main() {
    int t;
    cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}
