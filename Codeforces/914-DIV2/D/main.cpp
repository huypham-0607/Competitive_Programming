#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e3+10;
const int INF = 2e9;

int n,t;
int a[maxn],b[maxn];
bool reach[maxn][maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        bool check = true;
        cin >> n;
        for (int i=1; i<=n; i++) cin >> a[i];
        for (int i=1; i<=n; i++) cin >> b[i];
        for (int i=1; i<=n; i++){
            for (int j=1; j<=n; j++){
                reach[i][j] = false;
            }
        }
        for (int idx=1; idx<=n; idx++){
            if (a[idx] > b[idx]){
                check = false;
                continue;
            }
            int j = idx;
            int i = a[idx];
            reach[i][j] = true;
            while (j-1 > 0 && a[idx] <= b[j-1] && a[idx] >= a[j-1]){
                --j;
                reach[i][j] = true;
            }
            j = idx;
            while (j+1 <= n && a[idx] <= b[j+1] && a[idx] >= a[j+1]){
                ++j;
                reach[i][j] = true;
            }
        }
        if (!check) cout << "NO" << endl;
        else{
            for (int i=1; i<=n ;i++){
                if (!reach[b[i]][i]) check = false;
            }
            if (!check) cout << "NO" << endl;
            else cout << "YES" << endl;
        }
//        for (int i=1; i<=n; i++){
//            for (int j=1; j<=n; j++){
//                cout << reach[i][j] << " ";
//            }
//            cout << endl;
//        }
    }
    return 0;
}
