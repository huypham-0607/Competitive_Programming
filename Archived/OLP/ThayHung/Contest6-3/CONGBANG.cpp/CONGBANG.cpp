#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 110;
const int INF = 2e9;

int test;
int n,c;
int ans[maxn];
vector<pii> v;

int main(){
    freopen("CONGBANG.INP","r",stdin);
    freopen("CONGBANG.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        v.clear();
        cin >> c >> n;
        int t = 0,x;
        for (int i=1; i<=n; i++){
            cin >> x;
            t+=x;
            v.push_back({x,-i});
        }
        if (t < c){
            cout << "IMPOSSIBLE" << endl;
            continue;
        }
        int cnt = n;
        sort(v.begin(),v.end());
        for (auto in:v){
            int pos = -in.se;
            int val = in.fi;

//            cout << pos << " " << val << endl;

            int meow = min(val,c/cnt);
            ans[pos] = meow;
            c-=meow;

            --cnt;
        }
        for (int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
