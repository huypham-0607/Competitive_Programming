#include <bits/stdc++.h>
#define in 1001
using namespace std;

int cnt[in],k,n,m;
bool visit[in];
vector<int> a[in],t;

void dfs(int s){
    cnt[s]++;
    visit[s] = true;
    for (auto x:a[s]){
        if (!visit[x]){
            dfs(x);
        }
    }
}

int main()
{
    freopen("KEHOACH.INP","r",stdin);
    freopen("KEHOACH.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> k >> n >> m;
    for (int i = 0; i<k; i++){
        int x;
        cin >> x;
        t.push_back(x);
    }
    for (int i = 0; i<m; i++){
        int x,y;
        cin >> x >> y;
        a[x].push_back(y);
    }

    fill_n(cnt,in,0);
    for (auto x:t){
        fill_n(visit,in,false);
        dfs(x);
    }

    int c=0;
    for (int i=1; i<=n; i++){
        if (cnt[i] == k){
            c++;
        }
    }

    cout << c;

    return 0;
}
