/*Author: KawakiMeido*/
#include "circus.h"
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 1e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,m;
int p[N];
int dist[N][2];
vector<int> posl,vall,posr,valr;

void Dijkstra(){
    priority_queue<piii,vector<piii>,greater<piii>> pq;
    for (int i=0; i<n; i++){
        dist[i][0] = INF;
        dist[i][1] = INF;
    }
    dist[n-1][0] = 0;
    dist[n-1][1] = 0;
    pq.push({0,{n-1,0}});
    pq.push({0,{n-1,1}});
    while (!pq.empty()){
        int d = pq.top().fi;
        int u = pq.top().se.fi;
        int dir = pq.top().se.se;
        pq.pop();

        if (d > dist[u][dir]) continue;

//        cout << "cur: " << u << " " << dir << endl;

        /*Create new Ripple*/
        if (!((dist[u][0] == INF)&& (dist[u][1] == INF))){
            int pos,v;

            pos = p[u] - d;
            v = (upper_bound(p,p+n,pos))-p-1;
            if (v>=0 && v<n){
                int delta = abs(p[u] - p[v]);
                if (delta<dist[v][1]){
                    dist[v][1] = delta;
                    pq.push({delta,{v,1}});
                }
            }

            pos = p[u] + d;
            v = (lower_bound(p,p+n,pos)) - p;
            if (v>=0 && v<n){
                int delta = abs(p[u] - p[v]);
                if (delta<dist[v][0]){
                    dist[v][0] = delta;
                    pq.push({delta,{v,0}});
                }
            }
        }

        /*Continue previous Ripple*/
        int v = u;
        if (!dir) ++v;
        else --v;

        if (v>=0 && v<n){
            int delta = abs(p[u] - p[v]);
            if (d+delta<dist[v][dir]){
                dist[v][dir] = d+delta;
                pq.push({d+delta,{v,dir}});
            }
        }
    }
}

void CalcLeft(vector<int> &pos, vector<int>& val){
    vector<pii> query;
    pos.push_back(-INF);
    val.push_back(-INF);
    for (int i=0; i<n; i++){
        int mn = min(dist[i][0],dist[i][1]);
        query.push_back({p[i]+mn,p[i]});
    }
    sort(all(query));
    int idx = 0;
    while (idx!=(int)query.size()){
        int i = query[idx].fi;
        int w = -INF;
        while (idx!=(int)query.size() && query[idx].fi == i){
            w = max(w,query[idx].se);
            ++idx;
        }
        if (w>val.back()){
            pos.push_back(i);
            val.push_back(w);
        }
    }
}

void CalcRight(vector<int> &pos, vector<int>& val){
    vector<pii> query;
    pos.push_back(INF);
    val.push_back(INF);
    for (int i=0; i<n; i++){
        int mn = min(dist[i][0],dist[i][1]);
        query.push_back({p[i]-mn,p[i]});
    }
    sort(all(query),greater<pii>());
    int idx = 0;
    while (idx!=(int)query.size()){
        int i = query[idx].fi;
        int w = INF;
        while (idx!=(int)query.size() && query[idx].fi == i){
            w = min(w,query[idx].se);
            ++idx;
        }
        if (w<val.back()){
            pos.push_back(i);
            val.push_back(w);
        }
    }
    reverse(all(pos));
    reverse(all(val));
}

/*Solution*/
void init(int N, int M, int P[]){
    n = N;
    m = M;
    for (int i=0; i<n; i++){
        p[i] = P[i];
    }

    p[n] = m;
    ++n;

    sort(p,p+n);

    Dijkstra();

//    for (int i=0; i<n; i++){
//        cout << dist[i][0] << " " << dist[i][1] << endl;
//    }

    CalcLeft(posl,vall);
    CalcRight(posr,valr);
//    cout << "Left:" << endl;
//    for (int idx=0; idx<(int)posl.size(); idx++) cout << posl[idx] << " " << vall[idx] << endl;
//    cout << "Right:" << endl;
//    for (int idx=0; idx<(int)posr.size(); idx++) cout << posr[idx] << " " << valr[idx] << endl;
}

int minLength(int D){
    int ans = INF;
    int pos;
    pos = upper_bound(all(posl),D) - posl.begin()-1;
    ans = min(ans,abs(D-vall[pos]));
    pos = lower_bound(all(posr),D) - posr.begin();
    ans = min(ans,abs(D-valr[pos]));
    return ans;
}

//int q;
//
//void Solve(){
//    cin >> n >> m;
//    for (int i=0; i<n; i++){
//        cin >> p[i];
//    }
//    init(n,m,p);
//    cin >> q;
//    for (int i=1; i<=q; i++){
//        int x; cin >> x;
//        cout << minLength(x) << endl;
//    }
//}
//
///*Driver Code*/
//signed main(){
//    freopen("circus.inp","r",stdin);
//    freopen("circus.out","w",stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    Solve();
//
//    return 0;
//}
