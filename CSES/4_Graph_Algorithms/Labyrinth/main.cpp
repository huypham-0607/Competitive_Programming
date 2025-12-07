#include <bits/stdc++.h>
#define ii pair<int,int>
#define fi first
#define se second
using namespace std;

int n,m;
int a[1010][1010];
int di[4] = {0,1,0,-1},
    dj[4] = {1,0,-1,0};
bool visit[1010][1010];
bool mark[1010][1010];
string dir[4] = {"R","D","L","U"};
string ans = "";
ii start,e;

bool inbound(int i, int j){
    if (i>=0 && i<n && j>=0 && j<m) return true;
    else return false;
}

void dfs(ii in){
    visit[in.fi][in.se] = true;
    for (int x=0; x<4; x++){
        int i = in.fi+di[x];
        int j = in.se+dj[x];
        if (inbound(i,j) && a[i][j] && !visit[i][j]){
            dfs({i,j});
        }
    }
}

bool dfspath(ii in){
    //cout << in.fi << " " << in.se << endl;
    if (in==e) return true;
    mark[in.fi][in.se] = true;
    for (int x=0; x<4; x++){
        int i = in.fi+di[x];
        int j = in.se+dj[x];
        if (inbound(i,j) && a[i][j] && !mark[i][j]){
            ans+=dir[x];
            if (dfspath({i,j})){
                return true;
            }
        }
    }
    ans = ans.substr(0,ans.size()-1);
    return false;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m;
    for (int i=0; i<n; i++){
        string s;
        cin >> s;
        for (int j=0; j<m; j++){
            char c = s[j];
            if (c=='A') start = {i,j};
            if (c=='B') e = {i,j};
            if (c=='#') a[i][j]=0;
            else a[i][j]=1;
        }
    }
    dfs({start.fi,start.se});
    if (visit[e.fi][e.se]){
        cout << "YES";
        //cout << endl;
        bool meow = dfspath(start);
        cout << "\n" << ans;
    }
    else cout << "NO";
    return 0;
}
