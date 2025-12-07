#include <bits/stdc++.h>

using namespace std;
int a[101][101];
int cnt[101];
int b[100];
int n,m,i,j,k;

int main()
{
    freopen("XEPHANG.INP","r",stdin);
    freopen("XEPHANG.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    fill_n(cnt,101,0);

    for (int i=0; i<n; i++){
        for (j=0; j<n; j++){
            a[i][j] = 2;
        }
    }
    for (int i=0; i<m; i++){
        int x,y;
        cin >> x >> y;
        a[x][y] = 1;
        a[y][x] = 0;
        cnt[x]++;
        cnt[y]++;
    }
    for(int k=1;k<=n;k++)
        for(int i=1;i<=n;i++)
            for(int j=1;j<=n;j++)
                if (a[i][k]==1 && a[k][j]==1) {
                    a[i][j]=1;
                    a[j][i]=0;
                    cnt[i]++;
                    cnt[j]++;
                }

    cout << endl;
    int c=0;
    for(int i = 1; i<=n; i++){
        cout << i <<" "<< cnt[i] << endl;
            if (cnt[i] == n-1)
                c++;
    }

    cout << c << endl;
    return 0;
}
