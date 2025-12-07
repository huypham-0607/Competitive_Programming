#include <bits/stdc++.h>
using namespace std;

int i,j,m,n,a[1000][1000],sta[3];
bool visit[1000][1000];
string st;
void dfs(int i,int j){
    visit[i][j] = true;
    if (j+1 < m && a[i][j+1] == a[i][j] && !visit[i][j+1])
        dfs(i,j+1);
    if (i+1 < n && a[i+1][j] == a[i][j] && !visit[i+1][j])
        dfs(i+1,j);
    if (j-1 > -1 && a[i][j-1] == a[i][j] && !visit[i][j-1])
        dfs(i,j-1);
    if (i-1 > -1 && a[i-1][j] == a[i][j] && !visit[i-1][j])
        dfs(i-1,j);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for (int i=0; i<n; i++)
        for (int j =0; j<m; j++)
            visit[i][j] = false;
    for (int i=0; i<n; i++){
        cin >> st;
        for (int j =0; j<m; j++){
            a[i][j] = int(st[j])-48;
        }
    }
    cout << "\n";
    for (int i=0; i<n; i++){
        for (int j =0; j<m; j++){
            if (!visit[i][j]){
                sta[a[i][j]]++;
                dfs(i,j);
            }
        }
    }

    cout << "  Co tong cong " << sta[0] <<" khu dat trong.\n";
    cout << "  Co tong cong " << sta[1] <<" mang luoi duong lien thong.\n";
    cout << "  Co tong cong " << sta[2] <<" khu dat da duoc xay dung.\n";
    return 0;
}
