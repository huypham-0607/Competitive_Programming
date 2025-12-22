#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        char c;
        for (int i=1; i<=n; i++){
            cin >> c;
            if (c == 'W') a[i] = 1;
            else a[i] = 0;
        }
        a[0] = 0;
        a[n+1] = 0;
        int i;
        for (i=1; i<=n; i++){
            if (a[i] == 0) break;
        }
        int j;
        for (j=n; j>0; j--){
            if (a[j] == 0) break;
        }
        cout << max(0,n-(i-1+n-j)) << endl;
    }
    return 0;
}
