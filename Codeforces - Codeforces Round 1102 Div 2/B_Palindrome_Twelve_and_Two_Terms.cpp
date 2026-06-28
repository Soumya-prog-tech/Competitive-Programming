//  B. Palindrome, Twelve and Two Terms

#include<bits/stdc++.h>

using namespace std;

#define DEBUG
#define ll long long

void solve() {
    ll n;
    cin>>n;

    ll r = n%12;
    if (r == 10) {
        if (n == 10) {
            cout<<-1<<endl;

        }
        else {
            cout<<22<<" "<<n-22<<endl;
        }
    }
    else {
        cout<<r<<" "<<n-r<<endl;
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
