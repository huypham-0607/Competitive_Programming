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
string a,b;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        cin >> a >> b;
        int ex = 0, miss = 0;
        for (int i=0; i<n; i++){
            if (a[i] == '1' && b[i] == '0') ++ex;
            if (a[i] == '0' && b[i] == '1') ++miss;
        }
        cout << max(ex,miss) << endl;
    }

    return 0;
}
