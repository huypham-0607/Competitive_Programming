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

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
    string s;
    cin >> n >> s;
    int cnt = 0;
    for (int i=0; i<n; i++){
        if (s[i] == '0') cnt++;
    }
    if (cnt) cout << "YES" << "\n";
    else cout << "NO" << "\n";
    }
    return 0;
}
