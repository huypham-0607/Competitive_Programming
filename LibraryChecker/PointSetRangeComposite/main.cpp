/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int MD = 998244353;
const int N = 5e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;

struct Node{
    int a, b;
    Node(int _a=0,int _b=0): a(_a), b(_b){};
};

Node Comb(Node& x, Node& y){
    Node res(x.a,x.b);
    res.a = (res.a*y.a)%MD;
    res.b = ((res.b*y.a)%MD+y.b)%MD;
    return res;
}

Node ST[2*N];

void BuildST(){
    for (int i=n-1; i>0; --i) ST[i] = Comb(ST[i<<1],ST[i<<1|1]);
}

void UpdateST(int x, Node v){
    for (ST[x+=n] = v; x>>=1; ) ST[x] = Comb(ST[x<<1],ST[x<<1|1]);
}

Node GetST(int l, int r){
    Node resl(1,0), resr(1,0);
    for (l+=n, r+=n; l<r; l>>=1, r>>=1){
        if (l&1) resl = Comb(resl,ST[l++]);
        if (r&1) resr = Comb(ST[--r],resr);
    }
    return Comb(resl,resr);
}

/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=0; i<n; i++){
        cin >> ST[i+n].a >> ST[i+n].b;
        ST[i+n].a%=MD;
        ST[i+n].b%=MD;
    }
    BuildST();
    int id,x,y,z;
    while (q--){
        cin >> id >> x >> y >> z;
        x%=MD; y%=MD; z%=MD;
        if (!id){
            Node tmp(y,z);
            UpdateST(x,tmp);
        }
        else{
            Node u(z,0), v = GetST(x,y);
            u = Comb(u,v);
            cout << (u.a+u.b)%MD << endl;
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
