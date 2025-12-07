#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,t;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        a[0] = 1;
        a[n+1] = 1;
        int aircnt = 0;
        int cnt = 0;
        int mx = 0;
        for (int i=1; i<=n; i++){
            char c;
            cin >> c;
            if (c == '#'){
                a[i] = 1;
                mx = max(cnt,mx);
                cnt=0;
            }
            else{
                ++aircnt;
                a[i] = 0;
                ++cnt;
            }
        }
        mx = max(cnt,mx);
        if (mx >=3){
            cout << 2 << endl;
        }
        else{
            cout << aircnt << endl;
        }
    }
    return 0;
}
