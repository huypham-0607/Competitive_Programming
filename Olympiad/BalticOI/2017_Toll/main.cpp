/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const int LG = 16;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

struct Node{
    vector<vector<int>> val;

    Node(int k){
        val.resize(k,vector<int>(k,INF));
    }
};

/*Global Variables*/
int k,n,m,q;
vector<Node> adj;
vector<vector<Node>> DNC;
int mask[N];

Node Comb(Node x, Node y){
    Node res(k);
    for (int i=0; i<k; i++){
        for (int mid=0; mid<k; mid++){
            for (int j=0; j<k; j++){
                res.val[i][j] = min(res.val[i][j],x.val[i][mid]+y.val[mid][j]);
            }
        }
    }
    return res;
}

void BuildDNC(int l, int r, int lg){
    if (l==r) return;
    int mid = (l+r)/2;
    for (int i=0; i<k; i++){
        for (int j=0; j<k; j++){
            if (i==j) DNC[lg][mid].val[i][j] = 0;
            else DNC[lg][mid].val[i][j] = INF;
        }
    }
    DNC[lg][mid+1] = adj[mid];
//    for (int i=0; i<k; i++){
//        for (int j=0; j<k; j++){
//            if (i==j) DNC[lg][mid+1].val[i][j] = 0;
//            DNC[lg][mid+1].val[i][j] = INF;
//        }
//    }
    for (int i=mid-1; i>=l; i--){
        DNC[lg][i] = Comb(adj[i],DNC[lg][i+1]);
    }
    for (int i=mid+2; i<=r; i++){
        DNC[lg][i] = Comb(DNC[lg][i-1],adj[i-1]);
    }
    for (int i=l; i<=mid; i++){
        mask[i] = mask[i]^((ll)1<<lg);
    }
    BuildDNC(l,mid,lg+1); BuildDNC(mid+1,r,lg+1);
}

/*Solution*/
void solve(){
    cin >> k >> n >> m >> q;

    adj.resize((n-1)/k+10,Node(k));
    DNC.resize(LG,vector<Node>((n-1)/k+10,Node(k)));

//    for (int i=0; i<n; i++){
//        cin >> a[i];
//    }

    for (int i=0; i<m; i++){
        int u,v,w; cin >> u >> v >> w;
        adj[u/k].val[u%k][v%k] = w;
    }

    BuildDNC(0,(n-1)/k,0);
    for (int i=1; i<=q; i++){
        int u,v;
        cin >> u >> v;
        int x = u/k, y = v/k;
        if (x==y){
            if (u==v) cout << 0 << endl;
            else cout << -1 << endl;
        }
        else{
            int lg = __builtin_ctzll(mask[x]^mask[y]);
            Node tmp = Comb(DNC[lg][x],DNC[lg][y]);
            if (tmp.val[u%k][v%k] == INF) cout << -1 << endl;
            else cout << tmp.val[u%k][v%k] << endl;
        }
    }

//    for (int idx=0; idx<=n/k; idx++){
//        for (int i=0; i<k; i++){
//            for (int j=0; j<k; j++){
//                if (adj[idx].val[i][j] == INF) cout << -1 << " ";
//                else cout << adj[idx].val[i][j] << " ";
//            }
//            cout << endl;
//        }
//        cout << endl;
//    }
//
//    for (int lg=0; lg<2; lg++){
//        cout << "log: " << lg << endl;
//        for (int idx=0; idx<=n/k; idx++){
//            for (int i=0; i<k; i++){
//                for (int j=0; j<k; j++){
//                    if (DNC[lg][idx].val[i][j] == INF) cout << -1 << " ";
//                    else cout << DNC[lg][idx].val[i][j] << " ";
//                }
//                cout << endl;
//            }
//            cout << endl;
//        }
//    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
