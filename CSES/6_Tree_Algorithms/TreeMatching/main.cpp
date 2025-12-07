#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define cap 200100

using namespace std;

int n, c;
vector<int> a[cap];
bool visit[cap];

int dfs(int u){
    int x = 0;
    visit[u] = true;
    for (auto v:a[u]){
        if (!visit[v]){
            x = max(x,dfs(v));
        }
    }
    if (x==1){
        c++;
        return 0;
    }
    else return 1;
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
    c = 0;
    int tam = dfs(1);

    cout << c;

    return 0;
}
