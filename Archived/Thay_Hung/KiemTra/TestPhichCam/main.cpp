#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int main(){
    freopen("test.OUT","w",stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    srand(4299);
    int n = rand()%150+1;
    int m = rand()%150+1;
    int k = rand()%150+1;
    cout << n << endl;
    for (int i=1; i<=n; i++){
        int a = rand()%150+1;
        cout << a << endl;
    }
    cout << m << endl;
    for (int i=1; i<=m; i++){
        int a = rand()%150+1;
        cout << a << " " << a << endl;
    }
    cout << k << endl;
    for (int i=1; i<=k; i++){
        int a = rand()%150+1;
        int b = rand()%150+1;
        cout << a << " " << b << endl;
    }
    return 0;
}
