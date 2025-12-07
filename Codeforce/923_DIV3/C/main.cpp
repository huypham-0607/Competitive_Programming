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
bool va[maxn*2],vb[maxn*2];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n >> m >> k;
        for (int i=1; i<=k; i++){
            va[i] = false;
            vb[i] = false;
        }
        int cnt=0,ca=0,cb=0;
        int x;
        for (int i=1; i<=n; i++){
            cin >> x;
            if (x>k) continue;
            if (!va[x] && !vb[x]){
                ++cnt;
                ++ca;
                va[x] = true;
            }
            else if(!va[x]){
                ++ca;
                va[x] = true;
            }
        }
        for (int i=1; i<=m; i++){
            cin >> x;
            if (x>k) continue;
            if (!va[x] && !vb[x]){
                ++cnt;
                ++cb;
                vb[x] = true;
            }
            else if(!vb[x]){
                ++cb;
                vb[x] = true;
            }
        }
        if (cnt >= k && ca>=k/2 && cb>=k/2){
            cout << "YES" << endl;
        }
        else cout << "NO" << endl;
//        cout << cnt << " " << ca << " " << cb;
    }
    return 0;
}
