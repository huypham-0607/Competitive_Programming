#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,test;
string a,b,c;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        cin >> a >>  b >> c;
        bool v = false;
        for (int i=0; i<n; i++){
            if (c[i] != a[i] && c[i]!=b[i]) v = true;
        }
        if (v) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
