#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,k;
int cnt[maxn];
vector<int> a[maxn];

int dfs(int u, int p, int val){
    int res = 0;
    cnt[u] = 1;
    for (auto v:a[u]){
        if (v == p) continue;
        res+=dfs(v,u,val);
        cnt[u]+=cnt[v];
    }
    if (cnt[u] >= val){
        cnt[u] = 0;
        res++;
    }
//    cout << u << " " << res << endl;
    return res;
}

bool check(int x){
    int res = dfs(1,0,x);
    if (res > k || (res == k && cnt[1] >= x)) return true;
    else return false;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    while (test--){
        cin >> n >> k;
        for (int i=1; i<=n; i++){
            a[i].clear();
        }
        for (int i=1; i<n; i++){
            int u,v;
            cin >> u >> v;
            a[u].push_back(v);
            a[v].push_back(u);
        }
        int ans = 0, l=1, r=n-1;
        while (l<=r){
            int mid = (l+r)/2;
//            cout << "{" << mid << "}" << endl;
            if (check(mid)){
                ans = mid;
                l = mid+1;
            }
            else r = mid-1;
        }
        cout << ans << endl;
    }

    return 0;
}
