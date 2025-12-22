#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e17;

int test;
int n,m,k,d;

deque<pii> dq;
int bridges[110];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;

    while (test--){
        cin >> n >> m >> k >> d;
        d+=1;
        for (int i=1; i<=n; i++){
            dq.clear();
            dq.push_back({0,1-d});
            for (int j=1; j<=m; j++){
                while (!dq.empty() && dq.front().se < j-d){
                    dq.pop_front();
                }
                int x;
                cin >> x;
                x = x+1+dq.front().fi;
                if (j == m) bridges[i] = x;
                while (!dq.empty() && dq.back().fi > x){
                    dq.pop_back();
                }
                dq.push_back({x,j});
            }
        }
        int t = 0;
        for (int i=1; i<=k; i++){
            t+=bridges[i];
        }
        int res = t;
        for (int i=k+1; i<=n; i++){
            t-=bridges[i-k];
            t+=bridges[i];
            res = min(res,t);
        }
        cout << res << endl;
    }

    return 0;
}
