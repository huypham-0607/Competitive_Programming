#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<int,pii>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,k;
vector<int> v;
vector<piii> a;
int mx[maxn];

int main(){
    freopen("diamond.in","r",stdin);
    freopen("diamond.out","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    for (int i=1; i<=n; i++){
        int x;
        cin >> x;
        v.push_back(x);
    }
    sort(v.begin(),v.end());
    v.push_back(INF+100);
    int c = 0;
    int l=0, r=0;
    for (int l=0; l<n; l++){
        while (v[r+1] - v[l] <= k){
            ++r;
        }
        a.push_back({r-l+1,{l,r}});
        c++;
    }
    a.push_back({0,{INF+100, INF+101}});
    mx[c] = 0;
    for (int i=c-1; i>=0; i--){
        mx[i] = max(mx[i+1],a[i].fi);
    }
    l=0, r=0;
    int ans = 0;
    for (int l=0; l<c; l++){
        while (a[l].se.se >= a[r+1].se.fi) ++r;
        ans = max(ans,a[l].fi+mx[r+1]);
    }
    cout << ans;

//    cout << endl;
//    for (auto in:v){
//        cout << in << " ";
//    }
//    cout << endl;
//    for (int i=0; i<c; i++){
//        cout << a[i].fi << " " << a[i].se.fi << " " << a[i].se.se << endl;
//    }
    return 0;
}
