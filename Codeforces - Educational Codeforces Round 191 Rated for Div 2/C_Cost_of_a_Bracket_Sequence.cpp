//  C. Cost of a Bracket Sequence

#include<bits/stdc++.h>

using namespace std;

// #define DEBUG
#define ll long long

void solve() {
    int n, k;
    cin>>n>>k;

    string s;
    cin>>s;

    string final(n, ' ');
    int best_cost = n+1;

    for (int x = 0; x<=k; x++) { // x = no of deletions of left most open brackets
        string res(n, ' ');
        int y = k - x; // y = no of deletions of right most close brackets
        int cnt = 0;

        // making the leftmost x opening brackets delete
        for (int i = 0; i<n; i++) {
            if (s[i] == '(' && cnt < x) {
                res[i] = '1';
                cnt++;
            }
            else {
                res[i] = '0';
            }
        }

        // making the rightmost y closing brackets delete
        cnt = 0;
        for (int i = n-1; i>=0; i--) {
            if (s[i] == ')' && cnt < y) {
                res[i] = '1';
                cnt++;
            }
        }

        int cost = 0;
        int balance = 0;
        for (int i = 0; i<n; i++) {
            if (s[i] == '(') {
                balance++;
            }
            else {
                if (balance > 0) {
                    cost += 2;
                    balance--;
                }
            }
        }
        if (cost < best_cost) {
            best_cost = cost;
            final = res;
        }
    }
    cout<<final<<endl;
}

int main() {
    // Optimize I/O operations
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    int t;
    if (cin >> t) {
        while (t--) {
            solve();
        }
    }
    return 0;
}