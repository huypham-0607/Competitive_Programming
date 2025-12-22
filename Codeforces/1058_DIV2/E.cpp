/*She smiles, but nothing behind it feels real. The neon glow wraps around her like armor vibrant, untouchable, cold. Once, maybe, there was warmth in her gestures… but now it’s rehearsed. Perfectly practiced detachment. Her wave is polite, her wink playful, yet there’s an eerie hollowness like a ghost who forgot what it meant to feel. She doesn’t break down. She doesn’t react. She simply exists flawless, empty, and free. Because having zero feelings means never being hurt again.*/
#include <bits/stdc++.h>

#define TEXT ""

using namespace std;

#define pb push_back
#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define lb lower_bound
#define ub upper_bound
#define mp make_pair
#define fi first
#define se second

typedef int int2;
//#define int long long

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

//Starts here

int n,m;

int getIdx(int l, int r){
    return m*(m-1)/2 - (m-l+1)*(m-l)/2 + (r-l);
}

void solve(){
    bool flip = false;
    cin >> n >> m;
    if (n<m){
        swap(n,m);
        flip = true;
    }
    vector<vector<int>> v(n+2, vector<int>(m+2,0));
    if (flip){
        for (int j=1; j<=m; j++){
            for (int i=1; i<=n; i++){
                char c; cin >> c;
                v[i][j] = c-'0';
            }
        }
    } else {
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
                char c; cin >> c;
                v[i][j] = c-'0';
            }
        }
    }

//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=m; j++){
//            cout << v[i][j] << " ";
//        }
//        cout << endl;
//    }

    vector<int> prev(m*(m-1)/2+10,0);
    vector<vector<vector<int>>> dp(n+2,vector<vector<int>>(m+2,vector<int>(m+2,INF)));
//    vector<vector<pair<pii,int>>> seg(m*(m-1)/2+10);
    vector<pair<int,int>> last(m*(m-1)/2+10,{0,INF});

    for (int i=1; i<=n; i++){
        vector<int> pos;
        for (int j=1; j<=m; j++){
            if (v[i][j]) pos.push_back(j);
        }
//        cout << i << endl;
        for (int x = 0; x < pos.size(); x++){
            for (int y = x+1; y<pos.size(); y++){
                int l = pos[x];
                int r = pos[y];
                int idx = getIdx(l,r);
//                cout << "idx: " << idx << endl;
                if (prev[idx]!=0){
                    int area = ((r-l+1)*(i-prev[idx]+1));

//                    if (seg[idx].size()){
//                        if (seg[idx].back().se > area){
//                            auto tmp = seg[idx].back();
//                            seg[idx].pop_back();
//                            tmp.fi.se--;
//                            seg[idx].push_back(tmp);
//                            seg[idx].push_back({{prev[idx],i},area});
//                        }
//                        else seg[idx].push_back({{prev[idx]+1,i},area});
//                    }
//                    else seg[idx].push_back({{prev[idx],i},area});
                    if (last[idx].fi){
                        if (last[idx].se > area){
                            dp[last[idx].fi][l][r] = area;
                        }
                    }
                    for (int i2 = i; i2 > last[idx].fi; i2--){
//                        cout << "i2 " << i2 << endl;
                        dp[i2][l][r] = area;
                    }
                    last[idx] = {i,area};

                }
                else{
                    last[idx] = {i,INF};
                }
                prev[idx] = i;
            }
        }
//        cout << i << endl;
//        for (int idx=1; idx<=m*(m-1)/2; idx++){
//            cout << prev[idx] << " ";
//        }
//        cout << endl;
    }
//    for (int i=1; i<=n; i++){
//        cout << "i: " << i << endl;
//        for (int l=1; l<=m; l++){
//            for (int r=1; r<=m; r++){
//                cout << dp[i][l][r] << " ";
//            }
//            cout << endl;
//        }
//    }


    for (int i=1; i<=n; i++){
        for (int delta = m-1; delta>=0; delta--){
            for (int l=1, r=l+delta; r<=m; l++, r++){
//                cout << l << " " << r << endl;
                if (l!=1) dp[i][l][r] = min(dp[i][l][r],dp[i][l-1][r]);
                if (r!=m) dp[i][l][r] = min(dp[i][l][r],dp[i][l][r+1]);
            }
        }
    }

//    for (int l=1; l<=m; l++){
//        for (int r=l+1; r<=m; r++){
//            int idx = getIdx(l,r);
//            cout << "seg: " << l << " " << r << " " << idx << endl;
//            for (auto in:seg[idx]){
//                cout << in.fi.fi << " " << in.fi.se << " " << in.se << endl;
//            }
//        }
//    }

//    vector<vector<int>> ans(n+2,vector<int>(m+2,INF));
//
//    vector<vector<int>> dp(m+2,vector<int>(m+2,INF));
//
//    if (n==500 && v[1][1]) return;
//    vector<deque<pii>> dq(n+2,deque<pii>());
//    for (int w=2; w<=m; w++){
//        for (int i=1; i<=n; i++){
//            dq[i].clear();
//        }
//        for (int j=1; j<=m; j++){
//            for (int i=1; i<=n; i++){
//                while (!dq[i].empty() && dq[i].front().se<j) dq[i].pop_front();
//            }
//
//            int l = j;
//            int r = j+w-1;
//            if (r<=m){
//                int idx = getIdx(l,r);
//                int pos = -1;
//                for (int i=1; i<=n; i++){
//                    if (pos+1 < seg[idx].size() && i >= seg[idx][pos+1].fi.fi) ++pos;
//                    if (pos == -1 || i>seg[idx][pos].fi.se) continue;
//
//                    int val = seg[idx][pos].se;
//                    while (!dq[i].empty() && dq[i].back().fi >= val){
//                        dq[i].pop_back();
//                    }
//                    dq[i].push_back({val,r});
//                }
//            }
//
//            for (int i=1; i<=n; i++){
//                if (!dq[i].empty()){
//                    ans[i][j] = min(ans[i][j],dq[i].front().fi);
//                }
//            }
//        }
//    }

    if (!flip){
        for (int i=1; i<=n; i++){
            for (int j=1; j<=m; j++){
//                if (ans[i][j] == INF) ans[i][j] = 0;
//                cout << ans[i][j] << " ";
                if (dp[i][j][j]==INF) dp[i][j][j] = 0;
                cout << dp[i][j][j] << " ";
            }
            cout << endl;
        }
    }
    else{
        for (int j=1; j<=m; j++){
            for (int i=1; i<=n; i++){
//                if (ans[i][j] == INF) ans[i][j] = 0;
//                cout << ans[i][j] << " ";
                if (dp[i][j][j]==INF) dp[i][j][j] = 0;
                cout << dp[i][j][j] << " ";
            }
            cout << endl;
        }
    }
}

/*Driver Code*/
signed main(){
//    cin.tie(0) -> sync_with_stdio(0);
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

