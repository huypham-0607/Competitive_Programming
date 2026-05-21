/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define fi first
#define se second

typedef int int2;
#define int long long

typedef long long ll;
typedef long double ld;
typedef pair<int, int> pii;
typedef pair<ll,ll> pll;
typedef pair<double,double> pdd;

mt19937_64 rd(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 2e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

int LG = 61;

//Starts here

struct Trie{

    struct Node{
        Node* child[2];
        int cnt;
        int mx,val,dp;
        Node(){
            child[0] = child[1] = NULL;
            cnt = 0;
            mx = 0;
            val = 0;
            dp = 0;
        }
    };

    Node* Root;
    int cnt;
    Trie(){
        Root = new Node();
        cnt = 0;
        int mx = 0;
    }

    void Init(){
        clr(Root);
    }
    void clr(Node* cur){
        if (cur->child[0]!=NULL){
            clr(cur->child[0]);
            cur->child[0]=NULL;
        }
        if (cur->child[1]!=NULL){
            clr(cur->child[1]);
            cur->child[1]=NULL;
        }
        if (cur!=Root) delete cur;
    }

    void Update(Node* cur, int lg) {
        if (cur->child[0] != NULL) {
            cur->val = cur->child[0]->val + cur->child[0]->cnt; 
        }
        else {
            cur->val = 0;
        }

        cur->dp = -INF;

        for (int idx=0; idx<2; idx++) {
            int t = 0;
            if (cur->child[idx] != NULL) {
                if (cur->child[idx]->dp = -INF) {
                    continue;
                }
                t = cur->child[idx]->dp + cur->child[idx]->cnt;
            }
            if (idx == 1 && cur->child[0] != NULL) {
                t += cur->child[0]->val + cur->child[0]->cnt;
            }
            cur->dp = max(cur->dp,t);
        }
    }

    void Add(Node* cur, int x, int lg){
        if (lg!=LG) {
            int idx = ((x>>lg)&1LL);
            if (cur->child[idx] == NULL) cur->child[idx] = new Node();
            Add(cur->child[idx],x,lg+1);
            ++(cur->child[idx]->cnt);
            cout << lg << " " << cur->child[idx]->cnt << " " << cur->child[idx]->dp << " " << cur->child[idx]->val << endl;
        }
        Update(cur,lg);
        
    }

    void Del(Node* cur, int x, int lg) {
        if (lg!=LG) {
            int idx = ((x>>lg)&1LL);
            Del(cur->child[idx],x,lg+1);
            --(cur->child[idx]->cnt);
            if (cur->child[idx]->cnt == 0) {
                delete cur->child[idx];
            }
        }
        Update(cur,lg);
    }

    int Get(){
        return Root->dp; 
    }
};

Trie TR;

int n,q,k;
int a[N];

void solve(){
    TR.Init();
    cin >> n >> q >> k;
    LG = k;
    for (int i=1; i<=n; i++){
        cin >> a[i];
        cout << "Add: " << a[i] << endl;
        TR.Add(TR.Root,a[i],0);
        cout << -1 << " " << TR.Root->cnt << " " << TR.Root->dp << " " << TR.Root->val << endl;

    }
    int mask = 0;
    cout << TR.Get() << endl;
    // for (int i=1; i<=q; i++){
    //     int x,w; cin >> x >> w;
    //     TR.Del(TR.Root,a[i],0);
    //     a[i] = w;
    //     TR.Add(TR.Root,a[i],0);
    //     cout << TR.Get(TR.Root) << endl;
    // }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
   cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

