#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,c;
vector<pii> v;
priority_queue<int> pq;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        v.clear();
        cin >> n >> c;
        int x,y;
        for (int i=1; i<=n; i++){
            cin >> x >> y;
            v.push_back({y,x});
        }
        sort(v.begin(),v.end());
        int ans = 0;
//        int meow = 0;
        for (int i=0; i<n; i++){
            while (!pq.empty()){
                pq.pop();
            }
            int t = 0;
            int l = v[i].fi;
            int cnt = 0;
            if (t > c) continue;
            for (int j = i; j<n; j++){
//                while (!pq.empty() && t+r-l > c)
                int r = v[j].fi;
                int val = v[j].se;
                pq.push(val);
                ++cnt;
                t+=val;
                while (!pq.empty() && t+r-l > c){
                    t-=pq.top();
                    pq.pop();
                    --cnt;
                }
                if (ans < cnt){
                    ans = cnt;
//                    meow = t + r-l;
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
