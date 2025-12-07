#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define lim 200010
using namespace std;

int ans[lim],childcount[lim];
vector<int> a[lim];
int m,n;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    while (m--){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        childcount[y]++;
    }

    priority_queue <int,vector<int>,greater<int>> pq;
    int c=0;
    for (int i=1; i<=n; i++){
        if (childcount[i]==0){
            pq.push(i);
        }
    }

    while (!pq.empty()){
        int u = pq.top();
        pq.pop();
        c++;
        ans[c] = u;
        for (auto v:a[u]){
            childcount[v]--;
            if (childcount[v] == 0){
                pq.push(v);
            }
        }
    }

    if (c<n){
        cout << -1;
    }
    else{
        for (int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
    }
    return 0;
}
