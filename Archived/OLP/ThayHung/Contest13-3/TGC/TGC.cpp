#include <bits/stdc++.h>
#define endl "\n"
#define int long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e6+10;
const int INF = 1e17;

int test;
int n;
int cnt = 0;
vector<int> v;
int a[maxn];
int c[maxn];
int com[maxn],com2[maxn],pre[maxn];

signed main(){
    freopen("TGC.INP","r",stdin);
    freopen("TGC.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    v.push_back(0);
    v.push_back(INF);
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());

    int prev = 0;
    for (int i=0; i<=n+1; i++){
        if (v[i]!=prev){
            ++cnt;
            a[cnt] = v[i];
            c[cnt] = 1;
        }
        else{
            ++c[cnt];
        }
        prev = v[i];
    }
    for (int i=cnt; i>=0; i--){
        if (c[i] <= 1) com[i] = 0;
        else com[i] = c[i]*(c[i]-1)/2;
        if (c[i]<=2) com2[i] = 0;
        else com2[i] = c[i]*(c[i]-1)*(c[i]-2)/6;
        pre[i]=pre[i+1]+com[i];
    }
    int res = 0;
    int idx = 0;
    for (int i=1; i<=cnt; i++){
        int l = a[i];
        while (a[idx]<=l/2){
            ++idx;
        }
        res+=c[i]*(pre[idx]-com[i])+com2[i];
//        cout << c[i]*(pre[idx]-com[i])+com2[i] << " ";
    }
//    cout << endl;
    cout << res;
//    cout << endl;
//    for (int i=0; i<=cnt; i++){
//        cout << a[i] << " " << c[i] << " " << com[i] << " " << com2[i] << " " << pre[i] << endl;
//    }
    return 0;
}
