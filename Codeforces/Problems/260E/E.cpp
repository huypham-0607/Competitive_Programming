/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures� but now it�s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there�s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn�t break down. She doesn�t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT "E"

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

const int N = 1e5+10;
const int INF = 1e9+7;
const int MD = 1e9+7; //998244353;
const long long LLINF = 1e18+3;

//Starts here

struct Fenwick{
    int n;
    vector<int> BIT;

    Fenwick(int _n=0): n(_n){
        n = _n;
        BIT.resize(n+10,0);
    }

    void Init (int _n, int val=0){
        n = _n;
        BIT.resize(n+10,0);
    }

    void update(int idx, int val){
        while (idx<=n){
            BIT[idx]+=val;
            idx+=(idx&(-idx));
        }
    }

    int getPoint(int idx){
        int res = 0;
        while (idx>0){
            res+=BIT[idx];
            idx-=(idx&(-idx));
        }
        return res;
    }

    int getVal(int l, int r){
        return (getPoint(r)-getPoint(l-1));
    }
};


int n;
pii pts[N];
int req[10];
vector<int> prefx,prefy;
int ans[4*N][4];
int line[4*N][5];
vector<pair<pii,pii>> query;
vector<pii> upt;
vector<int> perm;

int bs(int x, vector<int>& val){
    int pos = lower_bound(all(val),x) - val.begin();
    if (pos == 0 || pos == val.size() || x != val[pos]) return -1;
    else return pos;
}

int getsum(int id) {
    if (id == 1) {
        return req[perm[0]] + req[perm[1]] + req[perm[2]];
    }
    if (id == 2) {
        return getsum(1) + req[perm[3]] + req[perm[4]] + req[perm[5]];
    }
    if (id == 3) {
        return req[perm[0]] + req[perm[3]] + req[perm[6]];
    }
    if (id == 4) {
        return getsum(3) + req[perm[1]] + req[perm[4]] + req[perm[7]];
    }
    return -1;
}

int getsum2(int id) {
    if (id == 0) {
        return req[perm[0]];
    }
    if (id == 1) {
        return req[perm[0]] + req[perm[3]];
    }
    if (id == 2) {
        return req[perm[0]] + req[perm[1]];
    }
    if (id == 3) {
        return req[perm[0]] + req[perm[1]] + req[perm[3]] + req[perm[4]];
    }
    return -1;
}

void solve(){
    cin >> n;
    vector<int> nen;
    for (int i=1; i<=n; i++){
        int x,y; cin >> x >> y;
        nen.push_back(x);
        nen.push_back(y);
        pts[i] = {x,y};
    }
    
    sort(all(nen));
    nen.resize(unique(all(nen))-nen.begin());
    int m = nen.size();
    prefx.resize(m+1);
    prefy.resize(m+1);
    for (int i=1; i<=n; i++){
        pts[i].fi = lower_bound(all(nen),pts[i].fi)-nen.begin()+1;
        pts[i].se = lower_bound(all(nen),pts[i].se)-nen.begin()+1;
        upt.push_back({pts[i].fi,pts[i].se});
        prefx[pts[i].fi]++;
        prefy[pts[i].se]++;
    }
    for (int i=1; i<=m; i++){
        prefx[i]+=prefx[i-1];
        prefy[i]+=prefy[i-1];
        // cout << prefx[i] << " " << prefy[i] << endl;
    }
    
    for (int i=0; i<=8; i++){
        cin >> req[i];
    }

    perm.resize(9);
    iota(all(perm),0);

    int id = 0;
    do{
        ++id;
        
        int x1 = bs(getsum(1),prefx);
        int x2 = bs(getsum(2),prefx);
        int y1 = bs(getsum(3),prefy);
        int y2 = bs(getsum(4),prefy);
        line[id][1] = x1;
        line[id][2] = x2;
        line[id][3] = y1;
        line[id][4] = y2;
        if (x1==-1 || x2==-1 || y1==-1 || y2==-1){
            for (int i=0; i<4; i++){
                ans[id][i] = -1;
            }
            continue;
        }

        // if (id == 1) {
        //     for (int i=1; i<=4; i++){
        //         cout << getsum(i) << " ";
        //     }
        //     cout << endl;
        //     for (int i=1; i<=4; i++){
        //         cout << line[id][i] << " ";
        //     }
        //     cout << endl;
        // }

        // cerr << id << endl;

        query.push_back({{x1,y1},{id,0}});
        query.push_back({{x2,y1},{id,1}});
        query.push_back({{x1,y2},{id,2}});
        query.push_back({{x2,y2},{id,3}});
    } while (next_permutation(all(perm)));

    sort(all(upt));
    sort(all(query));
    // cout << m << endl;
    Fenwick BIT(m);

    int uidx=0, qidx=0;
    for (int x=1; x<=m; x++){
        while (uidx!=upt.size() && upt[uidx].fi == x) {
            int y = upt[uidx].se;
            BIT.update(y,1);
            ++uidx;
        }
        while (qidx!=query.size() && query[qidx].fi.fi == x) {
            int y = query[qidx].fi.se;
            auto [aid,tid] = query[qidx].se;

            ans[aid][tid] = BIT.getPoint(y);
            ++qidx;
        }
    }

    // cout << uidx << " " << qidx << " " << id << endl;

    iota(all(perm),0);

    id = 0;
    do{
        ++id;

        if (ans[id][0] == -1) continue;

        // if (id == 1) {
        //     for (int i=0; i<4; i++){
        //         cout << ans[id][i] << " ";
        //     }
        //     cout << endl;
        // }
        
        bool flag = true;
        for (int i=0; i<4; i++){
            // cerr << i << " " << ans[id][i] << endl;
            if (ans[id][i] != getsum2(i)) flag = false;
        }
        // cerr << endl;
        
        if (flag) {
            cout << fixed << setprecision(5);
            cout << (double)nen[line[id][1]-1]+0.5 << " " << (double)nen[line[id][2]-1]+0.5 << endl; 
            cout << (double)nen[line[id][3]-1]+0.5 << " " << (double)nen[line[id][4]-1]+0.5 << endl; 
            return;
        }
    } while (next_permutation(all(perm)));
    cout << -1 << endl;
}

/*Driver Code*/
signed main(){
    // cin.tie(0) -> sync_with_stdio(0);
    if (fopen(TEXT".inp","r")){
        freopen(TEXT".inp","r",stdin);
        freopen(TEXT".out","w",stdout);
    }

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}

