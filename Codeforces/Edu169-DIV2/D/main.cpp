/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 2e5+10;
const int INF = 1e9+7;
const long long LLINF = 1e18+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n,q;
string s;
int a[N];

int GetIdx(char c){
    if (c == 'B') return 0;
    if (c == 'G') return 1;
    if (c == 'R') return 2;
    if (c == 'Y') return 3;
    return 4;
}

int tpe[3] = {3,5,9};

int precalc[3][2][N];
int cnt[3][N];


/*Solution*/
void solve(){
    cin >> n >> q;
    for (int i=1; i<=n; i++){
        cin >> s;
        int rawr = 0;
        rawr^=(1<<(GetIdx(s[0])));
        rawr^=(1<<(GetIdx(s[1])));
        a[i] = rawr;
//        cout << a[i] << " ";
    }
//    cout << endl;
    for (int i=0; i<3; i++){
        precalc[i][0][0] = -1;
        for (int idx=1; idx<=n; idx++){
            if (a[idx]!=tpe[i] && a[idx]!=(((1<<4)-1)^tpe[i])) precalc[i][0][idx] = idx;
            else precalc[i][0][idx] = precalc[i][0][idx-1];
        }

        precalc[i][1][n+1] = -1;
        for (int idx=n; idx>0; idx--){
            if (a[idx]!=tpe[i] && a[idx]!=(((1<<4)-1)^tpe[i])) precalc[i][1][idx] = idx;
            else precalc[i][1][idx] = precalc[i][1][idx+1];
        }
//        cout << "woof" << endl;
        cnt[i][0] = 0;
        for (int idx=1; idx<=n; idx++){
            cnt[i][idx] = cnt[i][idx-1];
            if (a[idx]!=tpe[i] && a[idx]!=(((1<<4)-1)^tpe[i])) cnt[i][idx]++;
        }
//        cout << "meow" << endl;
    }
//    for (int i=0; i<3; i++){
//        for (int j=0; j<2; j++){
//            for (int idx=1; idx<=n; idx++){
//                cout << precalc[i][j][idx] << " ";
//            }
//            cout << endl;
//        }
//        for (int idx=1; idx<=n; idx++){
//            cout << cnt[i][idx] << " ";
//        }
//        cout << endl << endl;
//    }
    while (q--){
        int l,r;
        cin >> l >> r;
        if (l>r) swap(l,r);
        if (a[l]&a[r]) cout << r-l << endl;
        else{
            int sus=0;
            for (int i=0; i<3; i++){
                if (tpe[i] == a[l] || tpe[i] == a[r]){
                    sus = i;
                    break;
                }
            }
            if (cnt[sus][r]-cnt[sus][l-1]){
                cout << r-l << endl;
            }
            else{
                int delta = INF;
                if (precalc[sus][0][l-1]!=-1) delta = min(delta,l-precalc[sus][0][l-1]);
                if (precalc[sus][1][r+1]!=-1) delta = min(delta,precalc[sus][1][r+1]-r);
//                cout << delta << endl;
                if (delta == INF) cout << -1 << endl;
                else cout << delta*2+r-l << endl;
            }
        }
    }
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(1);

    return 0;
}
