#include <bits/stdc++.h>

using namespace std;
vector <int> v[1000];
bool visit[1000];
int n,m,k;
void dfs(int p){
    visit[p] = true;
    for (auto x:v[p]){
        if (!visit[x]){
            dfs(x);
        }
    }
}

int main()
{
    freopen("GIAOSUA.INP","r",stdin);
    freopen("GIAOSUA.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m >> k;
    fill_n(visit,n+1,false);
    for (int i =0; i<m; i++){
        int a,b,t;
        cin >>a>>b>>t;
        if (t>=k){
            v[a].push_back(b);
            v[b].push_back(a);
        }
    }

    int t=0;
    for (int i=1; i<=n; i++){
        if (!visit[i]){
            t++;
            dfs(i);
        }
    }
    cout << t << endl;

    return 0;
}
