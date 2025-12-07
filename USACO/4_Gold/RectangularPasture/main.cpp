#include <bits/stdc++.h>
#define int long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e3 + 5e2 + 10;
const int INF = 2e9;

int n;
int pre[maxn][maxn],order[maxn];
vector<ii> xcord,ycord;
int inx[maxn],iny[maxn];

int calc(int i1, int j1, int i2, int j2){
    return pre[i2][j2] - pre[i1-1][j2] - pre[i2][j1-1] + pre[i1-1][j1-1];
}

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n;
    for (int i=1; i<=n; i++){
        int x,y;
        cin >> x >> y;
        xcord.push_back({x,i});
        ycord.push_back({y,i});
    }
    sort(xcord.begin(),xcord.end());
    sort(ycord.begin(),ycord.end());
    for (int i = 0; i<n; i++){
        iny[ycord[i].se] = i+1;
        inx[xcord[i].se] = i+1;
    }
    for (int i=1; i<=n; i++){
        pre[iny[i]][inx[i]] = 1;
        order[iny[i]] = inx[i];
    }
    cout << "\n";
    int c=0;
    for (int i=1; i<=n; i++){
        cout << "   ";
        for (int j=1; j<=n; j++){
            if (pre[i][j]){
                c++;
                cout << c << " ";
            }
            else cout << 0 << " ";
        }
        cout << "\n";
    }
    cout << "\n";
    for (int i=1; i<=n; i++){
        for (int j=1; j<=n; j++){
            pre[i][j] = pre[i][j] + pre[i-1][j] + pre[i][j-1] - pre[i-1][j-1];
            //cout << pre[i][j] << " ";
        }
        //cout << "\n";
    }
    int ans = 1;
    for (int i1=1; i1<=n; i1++){
        for (int i2=i1; i2<=n; i2++){
            int j1 = order[i1];
            int j2 = order[i2];
            if (j1 > j2) swap(j1,j2);
            int left = calc(i1,1,i2,j1);
            int right = calc(i1,j2,i2,n);
            ans+=right*left;
        }
    }
//    for (int i=1; i<=n; i++){
//        for (int j=1; j<=n; j++){
//            cout << pre[i][j] << " ";
//        }
//        cout << "\n";
//    }
    cout << ans;
    return 0;
}
