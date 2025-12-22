#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

const int maxn = 1e6+10;
const int INF = 2e9;

int t;
int n;
int BIT[maxn*2];
int ans[maxn],a[maxn];
vector<piii> v;

//BIT

void update(int x, int val){
    int i = x;
    while (i<=2*n){
        BIT[i]+=val;
        i+=(i&(-i));
    }
}

int query(int x){
    int i = x;
    int ans = 0;
    while (i>0){
        ans+=BIT[i];
        i-=(i&(-i));
    }
    return ans;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        fill_n(BIT,n*2+10,0);
//        for (int i=1; i<=n*2; i++){
//            cout << BIT[i] << " ";
//        }
//        cout << endl;
        v.clear();
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            a[x] = i;
            if (i>x){
                v.push_back({{-i,x+n},x});
            }
            else{
                v.push_back({{-i,x},x});
                v.push_back({{-(i+n),x+n},x+n});
            }
        }
        sort(v.begin(),v.end());
        for (auto in:v){
            //int l = -in.fi.fi;
            int r = in.fi.se;
            int i = in.se;

            if (i<=n) ans[i] = query(r);
            update(r,1);
//            cout << l << " " << r << " " << i << endl;
//            for (int i=1; i<=2*n; i++){
//                cout << query(i) << " ";
//            }
//            cout << endl;
        }
        for (int i=1; i<=n; i++){
            cout << (i-a[i]+n)%n-ans[i] << " ";
            //cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
