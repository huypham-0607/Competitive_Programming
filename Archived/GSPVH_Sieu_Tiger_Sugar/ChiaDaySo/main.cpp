#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int N = 7005;
const int MOD = 998244353;

string s;
int lcp[N][N];
//lcp[i][j] = s[i] == s[j] ? lcp[i+1][j+1] + 1 : 0;

int getcmp(int a,int b){
    if (a > b) return 1;
    if (a == b) return 0;
    return -1;
}

int cmp(int l,int r,int u,int v){
    int t = lcp[l][u];
    if (t >= r - l + 1 || t >= v - u + 1) return getcmp(r - l,v - u);
    return getcmp(s[l + t],s[u + t]);
}
int main(){
    //freopen(".INP","r",stdin);
    //freopen(".OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> s;
    int n = s.size();
    s = ' ' + s;
    for (int i = n; i >= 1; i--){
        for (int j = n; j >= 1; j--){
            lcp[i][j] = s[i] == s[j] ? lcp[i+1][j+1] + 1 : 0;
        }
    }
    cout << cmp(1,3,1,n);
    return 0;
}
