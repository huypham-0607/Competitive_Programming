/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
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
int n=0,q;
int parent[N],tp[N];
vector<int> color[N];

//DSU
void Init(){
    for (int i=1; i<=q; i++){
        parent[i] = i;
    }
}

int Find(int x){
    return (parent[x] == x)? x : parent[x] = Find(parent[x]);
}

bool Same(int u, int v){
    return (Find(u) == Find(v));
}

void Union(int u, int v){
    if (!Same(u,v)){
        int x = Find(u);
        int y = Find(v);

        parent[y] = x;
    }
}

/*Solution*/
void solve(){
    cin >> q;
    Init();
    while (q--){
        n++;
        int idx;
        cin >> idx;
        if (idx == 1){
            int x;
            cin >> x;
            color[x].push_back(n);
            tp[n] = x;
        }
        else if (idx == 2){
            int clr,clr2;
            cin >> clr >> clr2;
            if (color[clr].empty()) continue;
            while (color[clr].size()>1){
                Union(color[clr][0],color[clr].back());
                color[clr].pop_back();
            }
            int tmp = color[clr].back();
            color[clr].pop_back();
            color[clr2].push_back(tmp);
            tp[tmp] = clr2;
        }
        else if (idx == 3){
            int t;
            cin >> t;
//            cout << t << " " ;
            cout << tp[Find(t)] << endl;
        }
//        for (int i=1; i<=2; i++){
//            for (auto x:color[i]){
//                cout << x << " ";
//            }
//            cout << endl;
//        }
//        for (int i=1; i<=n; i++){
//            cout << parent[i] << " ";
//        }
//        cout << endl;
    }

}

/*Driver Code*/
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
