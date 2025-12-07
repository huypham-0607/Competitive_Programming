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
int n;
ll k;
priority_queue<ll,vector<ll>,greater<ll>> pq;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> k >> n;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        pq.push(x);
    }
    ll ans = 0;
    while (pq.size()>1){
        int u = pq.top();
        pq.pop();
        ll v = pq.top();
        pq.pop();

        ans+=u+v;
        pq.push(u+v);
    }
    cout << ans;
    return 0;
}
