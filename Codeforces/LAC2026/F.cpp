#pragma GCC optimize("Ofast")
#pragma GCC optimize("inline")
#include <bits/stdc++.h>

using namespace std;

#define endl "\n"
#define fi first
#define se second

typedef pair<short, short> pii;

const int N = 160;
const int LGC = 17;
//Starts here

int LG = 17;
short n;
short a[N];
bool vis[LGC+2][LGC+2];
short col[LGC+2][LGC+2];
pii pts[N];

vector<int> di = {1,1,0,-1,-1,0};
vector<int> dj = {-1,0,1,1,0,-1};


short BFS(pii s, int c) {
    short res = 0;
    queue<pii> q;
    vis[s.fi][s.se] = true;
    q.push(s);
    while (!q.empty()) {
        pii u = q.front();
        ++res;
        q.pop();

        for (short dir = 0; dir < 6; dir++) {
            pii v = {u.fi+di[dir],u.se+dj[dir]};
            if (!vis[v.fi][v.se] && col[v.fi][v.se] == c) {
                vis[v.fi][v.se] = true;
                q.push(v);
            }
        }
    }
    return res;
}

void solve(){
    cin >> n;
    for (short i=1; i<=n; i++){
        cin >> a[i];
    }

    short ans = 0;
    LG = 1;
    while (LG*(LG+1)/2 < n) ++LG;

    for (int mask=0; mask<(1<<LG); mask+=2){
        short idx = 0;
        short l = __builtin_popcount(mask);
        short r = __builtin_popcount(mask)+1;
        for (int lg=0; lg<LG; lg++) {
            if (idx > n) break;
            if (mask&(1<<lg)) {
                for (short i=1; i<=lg+1; i++){
                    ++idx;
                    if (idx > n) break;
                    pts[idx] = {l,i};
                    col[l][i] = a[idx];
                }
                --l;
            }
            else {
                for (short i=1; i<=lg+1; i++){
                    ++idx;
                    if (idx > n) break;
                    pts[idx] = {r-i+1,i};
                    col[r-i+1][i] = a[idx];
                }
                ++r;
            }
        }
        for (int idx=1; idx<=n; idx++){
            if (col[pts[idx].fi][pts[idx].se] != 0 && !vis[pts[idx].fi][pts[idx].se]) {
                short res = BFS(pts[idx],col[pts[idx].fi][pts[idx].se]);
                ans = max(ans,res);
            }
        }

        for (int idx=1; idx<=n; idx++) {
            col[pts[idx].fi][pts[idx].se] = 0;
            vis[pts[idx].fi][pts[idx].se] = 0;
        }
    }
    cout << ans << endl;
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    int testCount = 1;
//    cin >> testCount;
    while (testCount--){
        solve();
    }

    return 0;
}
