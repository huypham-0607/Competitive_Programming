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
int n,m,k;
int a[maxn],b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n >> m >> k;
        int res = 0;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        for (int j=1; j<=m; j++){
            cin >> b[j];
            for (int i=1; i<=n; i++){
                if (a[i] + b[j] <=k) res++;
            }
        }
        cout << res << endl;
    }
    return 0;
}
