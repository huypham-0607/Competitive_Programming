#include <bits/stdc++.h>

using namespace std;

int n,w,f[5000][5000],m[5000],v[5000];

int main()
{
    freopen("BALO.INP","r",stdin);
    freopen("BALO.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> w;
    for (int i = 1; i<=n; i++)
        cin >> m[i] >> v[i];

    for (int j = 0; j<n; j++)
        f[0][j] =0;

    for (int i = 1; i<=n; i++){
        for(int j =0; j<=w;j++){
            f[i][j] = f[i-1][j];
            if (m[i]<=j && v[i] + f[i-1][j-m[i]] > f[i][j]){
                f[i][j] = v[i] + f[i-1][j-m[i]];
            }
        }
    }
    cout << f[n][w] << endl;

    int j = w;
    for (int i = n; i>0; i--){
        if  (f[i][j] != f[i-1][j]){
            cout << i << " ";
            j-=m[i];
        }
    }


    return 0;
}
