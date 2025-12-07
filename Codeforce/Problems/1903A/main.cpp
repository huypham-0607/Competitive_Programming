#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,k,t;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> k;
        bool check = true;
        int prev = 0;
        for (int i=1; i<=n; i++){
            int tam;
            cin >> tam;
            if (prev > tam) check = false;
            prev = tam;
        }
        if (k == 1 && !check) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}
