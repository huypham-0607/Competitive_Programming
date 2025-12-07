#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e3;
const int INF = 2e9;

int test;
int n,m;
int a[maxn][maxn];
int pre[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            char c;
            cin >> c;
            if (c == '*') a[i][j] = 1;
            else a[i][j] = 0;
            if (a[i][j]) pre[i][j] = 0;
            else pre[i][j] = pre[i-1][j]+1;
        }
    }

    int ans = 0;
    for (int i=1; i<=n; i++){
        stack<pii> s;
        s.push({0,0});
        for (int j=1; j<=m+1; j++){
            int meow = j;
//            cout << i << " " << j << " " << pre[i][j] << endl;
            while (s.top().fi>pre[i][j]){
                ans = max(ans,(j-s.top().se)*s.top().fi);
//                cout << i << " " << s.top().se << " " << (j-s.top().se)*s.top().fi << " " << j << endl;
                meow = s.top().se;
                s.pop();
            }
            s.push({pre[i][j],meow});
        }
    }
    cout << ans;
    return 0;
}
