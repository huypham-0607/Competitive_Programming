#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,k;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> k;
    int ans = 0;
    for (int i=1; i<=n; i++){
        int s,d;
        cin >> s >> d;
        int k1 = k-s;
        if (k1<0 || k1%d){
        }
        else ans++;
    }
    cout << ans;
    return 0;
}
