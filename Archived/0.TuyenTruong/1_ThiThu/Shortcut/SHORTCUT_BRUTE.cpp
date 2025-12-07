#include "bits/stdc++.h"
#define fast ios_base::sync_with_stdio(0) , cin.tie(0) , cout.tie(0)
#define endl '\n'
using namespace std;
typedef long long int ll;

ll n, m, t, ans = 0;
ll cow[10005], node[10005], go_to[10005], dist[10005], dup_cow[10005];
bool visited[10005];
set <ll> g[10005];
map <ll, map <ll, ll> > price;
priority_queue <pair<ll,ll> > path;

int main()
{
    freopen("shortcut.in", "r", stdin); freopen("shortcut.ans", "w", stdout);
    fast;
    cin >> n >> m >> t;
    for(ll i = 1; i <= n; i++) cin >> cow[i], dup_cow[i] = cow[i];
    for(ll i = 0; i < m; i++){
        ll a, b, x;
        cin >> a >> b >> x;
        g[a].insert(b);
        g[b].insert(a);
        price[a][b] = x;
        price[b][a] = x;
    }
    path.push(make_pair(0ll, 1ll));
    while(!path.empty()){
        ll dist = path.top().first;
        ll farm = path.top().second;
        path.pop();
        if(visited[farm]) continue;
        visited[farm] = true;
        node[farm] = -dist;
        for(ll k : g[farm]){
            path.push(make_pair(dist - price[k][farm], k));
        }
    }
    for(ll i = 1; i <= n; i++){
        go_to[i] = n+1;
        for(ll k : g[i]){
            if(node[i] - node[k] == price[i][k]){
                go_to[i] = min(go_to[i], k);
                break;
            }
        }
    }
    for(ll i = 1; i <= n; i++){
        ll index = i;
        while(index != 1){
            ll prev = index;
            for(ll a : g[index]){
                if(go_to[index] == a){
                    cow[a] += dup_cow[i];
                    index = a;
                    break;
                }
            }
            if(prev == index) break;
        }
    }
    node[1] = 0, cow[1] = 0;
    for(ll i = 1; i <= n; i++){
        ans = max(ans, (node[i]-t)*cow[i]);
    }
    cout << ans << endl;
}
