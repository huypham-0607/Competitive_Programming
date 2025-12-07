#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define cap 200100

using namespace std;

int n, mx;
vector<int> a[cap];
bool visit[cap];
int len[cap];

void dfs(int u){
    int first = 0;
    int second = 0;
    visit[u] = true;
    for (auto v:a[u]){
        if (!visit[v]){
            dfs(v);
            int x = len[v]+1;
            if (x>first) swap(first,x);
            if (x>second) swap(second,x);
        }
    }
    mx = max(mx,first+second);
    len[u] = first;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<n; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
        a[y].push_back(x);
    }
    mx = 0;
    dfs(1);

    cout << mx;
    return 0;
}

