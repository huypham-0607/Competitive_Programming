/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int LG = 22;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*Global Variables*/
int n,m;
vector<vector<int>> a;

int SOS[(1<<LG)+10];

void initialize(int _n, int _m , int** _a){
    n = _n;
    m = _m;

    a.resize(n+1);
    for (int i=0; i<n; i++){
        a[i].resize(m+1);
        for (int j=0; j<m; j++){
            a[i][j] = _a[i][j];
        }
    }

//    lg2[0] = 1;
//    for (int i=1; i<=LG; i++){
//        lg2[i] = lg2[i-1]*2;
//    }

//    cout << n << " " << m << endl;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            int x = (i|j);
//            cout << i << " " << j << " " << x << endl;
            SOS[x]^=a[i][j];
        }
    }

    for (int i=0; i<LG; i++){
        for (int mask=0; mask<(1<<LG); mask++){
            if ((mask&(1<<i))){
                SOS[mask] = SOS[mask]^SOS[mask^(1<<i)];
            }
        }
    }
}

int query(int k){
    k%=(1<<LG);
//    cout << k << " ";
    return SOS[k];
    return 0;
}

//int q;
//
///*Solution*/
//void Solve(){
//    cin >> n >> m >> q;
//    a.resize(n+1);
//    for (int i=0; i<n; i++){
//        a[i].resize(m+1);
//        for (int j=0; j<m; j++){
//            cin >> a[i][j];
//        }
//    }
//
//    initialize(n,m);
//
//    for (int i=1; i<=q; i++){
//        int x; cin >> x;
//        cout << query(x) << endl;
//    }
//
////    int tmp = 0;
////    for (int i=0; i<4; i++){
////        for (int j=0; j<4; j++){
////            tmp^=a[i][j];
////        }
////    }
////    cout << tmp << endl;
//}

///*Driver Code*/
//signed main(){
//    freopen("xortransform.inp","r",stdin);
//    freopen("xortransform.out","w",stdout);
//    ios_base::sync_with_stdio(0);
//    cin.tie(0);
//
//    Solve();
//
//    return 0;
//}
