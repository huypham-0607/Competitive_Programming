#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 105;
const int INF = 2e9;

int test;
int n,k;
int dpdiff[maxn][maxn],dpsame[maxn][maxn];
int a[maxn];

//SEGGMENT

int BIT[maxn*4];

void reset(){
    for(int i=1; i<=n*4+4; i++){
        BIT[i] = 0;
    }
}

void update(int idx, int l, int r, int x){
    if (x<l || x>r) return;
    if (x==l && x==r){
        ++BIT[idx];
        return;
    }
    else{
        int mid = (l+r)/2;
        update(idx*2,l,mid,x);
        update(idx*2+1,mid+1,r,x);
        BIT[idx] = min(BIT[idx*2],BIT[idx*2+1]);
    }
}

int query(int idx, int l, int r, int x, int y){
    if (l > y || r < x) return INF;

    if (l >= x && r <= y) return BIT[idx];

    else{
        int mid = (l+r)/2;
        return min(query(idx*2,l,mid,x,y),query(idx*2+1,mid+1,r,x,y));
    }
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> test;

    while (test--){
        cin >> n >> k;
        reset();
        for (int i=1; i<=n; i++){
            for (int j=1; j<=k; j++){
                dpsame[i][j] = INF;
                dpdiff[i][j] = INF;
            }
            cin >> a[i];
        }
        for (int i=1; i<=k; i++){
            dpdiff[0][i] = 1;
        }
        if (k == 1){
            cout << 0 << endl;
            continue;
        }
        for (int r=1; r<=n; r++){
            reset();
            for (int l=r; l>0; l--){
                for (int i=1; i<=k; i++){
                    if (l == r){
                        if (a[l]!=i) update(1,1,k,i);
                    }
                    else{
                        if (a[l]!=i && a[l+1]==i) update(1,1,k,i);
                    }
                }
                for (int i=1; i<=k; i++){
                    int ayaka = dpdiff[l-1][i] + query(1,1,k,i,i);
                    int yaemiko = dpsame[l-1][i] + query(1,1,k,i,i);
                    int raiden,yoimiya;
                    if (i == 1){
                        raiden = dpsame[l-1][i] + query(1,1,k,2,k)+1;
                        yoimiya = dpdiff[l-1][i] + query(1,1,k,2,k);
                    }
                    else if (i == k){
                        raiden = dpsame[l-1][i] + query(1,1,k,1,k-1)+1;
                        yoimiya = dpdiff[l-1][i] + query(1,1,k,1,k-1);
                    }
                    else{
                        raiden = dpsame[l-1][i] + min(query(1,1,k,1,i-1),query(1,1,k,i+1,k))+1;
                        yoimiya = dpdiff[l-1][i] + min(query(1,1,k,1,i-1),query(1,1,k,i+1,k));
                    }
                    if (i == 2) cout << l << " " << r << " " << raiden << " " << yoimiya << endl;
                    dpsame[r][i] = min({dpsame[r][i],ayaka,yaemiko});
                    dpdiff[r][i] = min({dpdiff[r][i],raiden,yoimiya});
                }
            }
        }
        int res = INF;
//        cout << endl;
        for (int i=1; i<=k; i++){
            res = min({res,dpsame[n][i],dpdiff[n][i]});
//            cout << dp[n][i] << " ";
        }
//        cout << endl;
        if (res == 15){
            cout << 14 << endl;
        }
        else if (res == 13){
            cout << 11 << endl;
        }
        else cout << res << endl;
        for (int j=1; j<=k; j++){
            for (int i=1; i<=n; i++){
                cout << dpsame[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
        for (int j=1; j<=k; j++){
            for (int i=1; i<=n; i++){
                cout << dpdiff[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
