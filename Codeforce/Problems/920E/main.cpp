/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
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
int n,m;
set<int> st;
vector<int> bar[N];
int cnt = 0;
vector<int> lst;

int BFS(int s){
    queue<int> q;
    q.push(s);
    int cur = 0;
    st.erase(s);
    while (!q.empty()){
        int u = q.front();

//        cout << u << endl;

        q.pop();

        ++cur;

        for (int i=1; i<(int)bar[u].size(); i++){
            int l = bar[u][i-1]+1;
            int r = bar[u][i]-1;
            if (l>r) continue;
            auto itl = st.lower_bound(l);
            auto itr = st.upper_bound(r);
            for (auto it=itl; it!=itr; it++){
                q.push((*it));
            }
            st.erase(itl,itr);
        }
    }
    return cur;
}

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        bar[i].push_back(0);
        bar[i].push_back(n+1);
        st.insert(i);
    }
    cin >> m;
    for (int i=1; i<=m; i++){
        int u,v;
        cin >> u >> v;
        bar[u].push_back(v);
        bar[v].push_back(u);
    }

    for (int i=1; i<=n; i++){
        sort(all(bar[i]));
    }

    for (int i=1; i<=n; i++){
        if (st.count(i)){
//            cout << "s: " << i << endl;
            ++cnt;
            lst.push_back(BFS(i));
        }
    }

    sort(all(lst));

    cout << cnt << endl;
    for (auto x:lst){
        cout << x << " ";
    }

}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
