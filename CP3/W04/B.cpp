#pragma GCC target ("avx2")
#pragma GCC optimize ("O3")
#pragma GCC optimize ("unroll-loops")
#include <stdio.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <utility>

using namespace std;

#define endl "\n"
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

typedef int int2;

typedef long long ll;

const int N = 1e5+10;
const int M = 2000;

//Starts here

int n,q;
int e[N];

priority_queue<int,vector<int>,greater<int>> ITmn[M*2+10];
priority_queue<int> ITmx[M*2+10];

pii getVal(int p, int t) {
    pii res = {n+1,0};
    p+=M;
    for (p; p > 1; p >>= 1) {

        while (!ITmn[p].empty() && e[ITmn[p].top()] < t) ITmn[p].pop(); 
        while (!ITmx[p].empty() && e[ITmx[p].top()] < t) ITmx[p].pop(); 
        if (ITmn[p].size() == 0) continue;
        else res = {min(res.fi,ITmn[p].top()),max(res.se,ITmx[p].top())};
    }
    return res;
}

void update(int l, int r, int val) {
    int res = 0;
    for (l += M, r += M; l < r; l >>= 1, r >>= 1) {
        if (l&1) {
            ITmx[l].push(val);
            ITmn[l].push(val);
            ++l;
        }
        if (r&1){
            --r;
            ITmx[r].push(val);
            ITmn[r].push(val);
        }
    }
}

int BIT[N];

void updateBIT(int idx, int val){
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

pair<pii,pii> query[N];
pair<pii,pii> pts[M*M+N];
int qsz = 0, ptssz = 0;
int ans[N];

void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        int i1, j1, i2, j2;
        cin >> i1 >> j1 >> i2 >> j2;
        ++i1; ++j1;
        e[i] = j2;
        query[qsz++] = {{j1,i},{i1,i2}};
    }
    sort(query,query+qsz);
    int idx = 0;
    for (int j=1; j<=M; j++){
        while (idx!=qsz && query[idx].fi.fi == j) {
            int val = query[idx].fi.se;
            int l = query[idx].se.fi;
            int r = query[idx].se.se;
            ++idx;

            update(l-1,r,val);
        }
        for (int i=1; i<=M; i++){
            pii res = getVal(i-1,j);
            pts[ptssz++] = {{res.fi,1},{res.se,0}};
            // cout << i << " " << j << " " << res.fi << " " << res.se << endl;
        }
    }

    for (int i=1; i<=q; i++){
        int l,r; cin >> l >> r;
        pts[ptssz++] = {{l,0},{r,i}};
    }
    sort(pts, pts+ptssz, greater<pair<pii,pii>>());

    idx = 0;
    int t = 0;
    for (int i = n+1; i > 0; i--){
        while (idx!=ptssz && pts[idx].fi.fi == i) {
            int op = pts[idx].fi.se;
            int pos = pts[idx].se.fi;
            int id = pts[idx].se.se;
            ++idx;

            if (op == 1) {
                if (i == n+1) {
                    ++t;
                }
                else {
                    if (pos == 0) continue;
                    updateBIT(pos,1);
                }
            }
            else {
                int res = getPoint(pos) + t;
                ans[id] = M*M-res;
            }
        }
    }

    for (int i=1; i<=q; i++){
        cout << ans[i] << endl;
    }
}

/*Driver Code*/
signed main(){
    cin.tie(0) -> sync_with_stdio(0);

    solve();

    return 0;
}

