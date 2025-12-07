#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,test,m;
int fwd[maxn],bwd[maxn];
int a[maxn];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            fwd[i] = 0;
            bwd[i] = 0;
        }
        fwd[0] =  0;
        fwd[n+1] = 0;
        bwd[0] = 0;
        bwd[n+1] = 0;
        fwd[1] = 1;
        bwd[n] = 1;
        for (int i=2; i<n; i++){
            if (abs(a[i]-a[i-1]) < abs(a[i] - a[i+1])){
                fwd[i] = abs(a[i] - a[i+1]);
                bwd[i] = 1;
            }
            else{
                fwd[i] = 1;
                bwd[i] = abs(a[i] - a[i-1]);
            }
        }
        for (int i=1; i<=n; i++){
            fwd[i]+=fwd[i-1];
            bwd[i]+=bwd[i-1];
        }
        cin >> m;
        for (int i=1; i<=m; i++){
            int x,y;
            cin >> x >> y;
            if (x < y){
                cout << fwd[y-1] - fwd[x-1] << endl;
            }
            else{
                cout << bwd[x] - bwd[y] << endl;
            }
        }
    }
    return 0;
}
