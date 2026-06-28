//  Permutation Reconstruction
#include<bits/stdc++.h>
using namespace std;
#define DEBUG
#define ll long long

void upd(int i,int v, vector<int>& bit, int n) {
    for(; i<=n; i+=i&-i)
        bit[i]+=v;
}
int qpre(int i, vector<int>& bit, int n) {
    int s=0;
    for(; i>0; i-=i&-i)
        s+=bit[i];
    return s;
}
int kth(int target, vector<int>& bit, int n){
    int pos=0,cur=0,LOG=0;
    while((1<<(LOG+1))<=n) ++LOG;
    for(int pw=LOG; pw>=0; --pw){
        int nx=pos+(1<<pw);
        if(nx<=n && cur+bit[nx]<target){ pos=nx; cur+=bit[nx]; }
    }
    return pos+1;
}

void solve() {
    int n; vector<int> bit;
    cin>>n;
    bit.assign(n+1,0);
    for(int v=1;v<=n;v++)
        upd(v,1, bit, n);
    vector<char> typ(n+1);
    vector<ll> val(n+1);
    for(int i=1;i<=n;i++) {
        char c[4];
        ll x;
        cin>>c>>x;
        typ[i]=c[0];
        val[i]=x;
    }
    vector<int> p(n+1);
    ll prevS=0, M=n;
    for(int i=1;i<=n;i++){
        int chosen;
        if(typ[i]=='p')
            chosen=(int)val[i];
        else {
            ll k=val[i]-prevS;
            chosen=kth((int)(M-k), bit, n);
        }

        ll unusedAbove = M - qpre(chosen, bit, n);
        ll placedAbove = (ll)(n-chosen) - unusedAbove;
        prevS += placedAbove;
        p[i]=chosen; upd(chosen,-1, bit, n); --M;
    }
    for(int i=1;i<=n;i++)
        cout<<p[i]<<" ";
}

int main() {
    int t;
    scanf("%d",&t);
    while(t--) {
        solve();
    }
    return 0;
}