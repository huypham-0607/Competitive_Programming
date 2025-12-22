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
int cnt[maxn],a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=0; i<=n; i++){
            cnt[i] = 0;
        }
        for (int i=1; i<=n; i++){
            cin >> a[i];
            cout << char(97+cnt[a[i]]);
            ++cnt[a[i]];
        }
        cout << endl;
    }
    return 0;
}
