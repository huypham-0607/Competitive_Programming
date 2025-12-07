#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second
#define cap 200100

using namespace std;

vector<int> a[cap];
int sub[cap];
int n;

void dfs(int u){
    int x=0;
    for (auto v:a[u]){
        dfs(v);
        x+=sub[v]+1;
    }
    sub[u] = x;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=2; i<=n; i++){
        int x;
        cin >> x;
        a[x].push_back(i);
    }
    dfs(1);
    for (int i=1; i<=n; i++){
        cout << sub[i] << " ";
    }

    return 0;
}
