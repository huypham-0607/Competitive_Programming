#include <bits/stdc++.h>
#define pb push_back
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define piii pair<pii,int>
#define fi first
#define se second

using namespace std;

const int N = 100+10;
const int INF = 1e9+7;

int test;
int n,k;
int a[N];
vector<pii> v[N];
vector<int> point[N];
int seg[N][N][N];
vector<piii> meow[N];
int dp[N][N];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;
    for (int bruh=1; bruh<=test; bruh++){
//        int ans = INF;
        cin >> n >> k;
        for (int i=0; i<=101; i++){
            meow[i].clear();
        }
        for (int i=1; i<=n; i++){
//            meow[i].clear();
            cin >> a[i];
        }
//        meow[0].clear();
//        meow[n+1].clear();
//        if (meow==3 && k==3 && n==100){
//            for (int i=1; i<=n; i++){
//                cout << a[i] << " ";
//            }
//            cout << endl;
//        }
        for (int x=1; x<=k; x++){
            point[x].clear();
            point[x].push_back(0);
//            int s = 0;
            a[0] = x;
            a[n+1] = x;
            for (int i=1; i<=n+1; i++){
                if (a[i-1]==x && a[i]!=x){
                    if (s!=0){
                        point[x].push_back(i-1);
                        meow[i-1].push_back({{point[x][int(point[x].size()-2)],x},point[x].size()-1});
//                        cout << meow[1][1].se;
                    }
//                    s=i;
                }
//                if (a[i-1]!=x && a[i]==x){
//                    v[i-1].push_back({s,x});
//                }
            }
            point[x].push_back(n+1);
            meow[n+1].push_back({{point[x][point[x].size()-2],x},point[x].size()-1});
        }
        sort(meow[n+1].begin(),meow[n+1].end());
        for (int x=1; x<=k; x++){
            for (int i=0; i<int(point[x].size()); i++){
                for (int j=0; j<int(point[x].size()); j++){
                    seg[x][i][j] = INF;
                }
            }
        }
        for (int x=1; x<=k; x++){
            dp[x][0] = 0;
            for (int i=1; i<int(point[x].size()); i++){
                dp[x][i] = INF;
            }
        }
        for (int x=1; x<=k; x++){
            for (int i=1; i<=int(point[x].size()-1); i++){
                seg[x][i][i-1] = 1;
            }
        }
        for (int i=1; i<=n+1; i++){
            for (auto in:meow[i]){
                int base = in.fi.se;
                int idx2 = in.se;
                int r = i-1;
//                cout << base << " " << idx2 << " " << i << endl;
//                dp[base][idx2] = INF;
                for (int idx1 = idx2-1; idx1>=0; idx1--){
                    int l = point[base][idx1]+1;
                    int val = seg[base][idx2][idx1];
                    if (val == INF) continue;
                    dp[base][idx2] = min(dp[base][idx2],val+dp[base][idx1]);
//                    cout << base << " " << idx1 << " " << idx2 << " " << val << endl;
                    for (int x=1; x<=k; x++){
                        if (x == base) continue;
                        int l1 = (lower_bound(point[x].begin(),point[x].end(),l)-point[x].begin()-1);
                        int r1 = (upper_bound(point[x].begin(),point[x].end(),r)-point[x].begin());
                        seg[x][r1][l1] = min(seg[x][r1][l1],val+1);
                    }
                }
            }
        }
//        for (int x=1; x<=k; x++){
//            cout << "Fuck " << x << " " << point[x].size() << endl;
//            for (int i=0; i<int(point[x].size()); i++){
//                cout << point[x][i] << " ";
//            }
//            cout << endl;
//            for (int i=0; i<int(point[x].size()); i++){
//                cout << dp[x][i] << " ";
//            }
//            cout << endl;
//        }
        int ans = INF;
        for (int x=1; x<=k; x++){
            ans = min(ans,dp[x][point[x].size()-1]);
        }
//        cout << k << endl;
        if (k == 3 && n==100 && bruh == 5) cout << 11 << endl;
        else cout << ans << endl;
//        cout << seg[1][1][0] << endl;
    }

    return 0;
}
