/*Author: KawakiMeido*/
#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define int long long
#define all(x) (x).begin(),(x).end()
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

/*Constants*/
const int N = 3e3+10;
const int INF = 1e9+7;
const long long LLINF = 1e15+3;

/*TestCases*/
int test=1;
void solve();
void TestCases(bool v){
    if (v) cin >> test;
    while(test--) solve();
}

/*Global Variables*/
int n;
int a[N][N];
priority_queue<piii,vector<piii>,greater<piii>> pq;
int rawr=0;

/*Solution*/
void solve(){
    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> a[1][i];
    }
    sort(a[1]+1,a[1]+n+1);
    rawr+=a[1][1];
    int tmp = a[1][1];
    for (int i=1; i<=n; i++){
        a[1][i]-=tmp;
        if (i>1) pq.push({a[1][i] + a[1][i-1],{i-1,i}});
    }
//    cout << rawr << endl;
    for (int lvl=2; lvl<=n; lvl++){
        for (int i=1; i<=n-lvl+1; i++){
            int val = pq.top().fi;
            int l = pq.top().se.fi;
            int r = pq.top().se.se;

            pq.pop();

            a[lvl][i] = val;
            if (r+1<=n-(lvl-1)+1){
                pq.push({a[lvl-1][l] + a[lvl-1][r+1],{l,r+1}});
            }
        }
        while (!pq.empty()){
            pq.pop();
        }
        tmp = a[lvl][1];
        rawr = (rawr*2)%INF;
        rawr = (rawr+tmp)%INF;
//        cout << rawr << endl;
        for (int i=1; i<=n-lvl+1; i++){
            a[lvl][i]-=tmp;
            if (i>1) pq.push({a[lvl][i] + a[lvl][i-1],{i-1,i}});
        }
    }
    cout << (a[n][1]+rawr)%INF << endl;
}

/*Driver Code*/
signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    TestCases(0);

    return 0;
}
