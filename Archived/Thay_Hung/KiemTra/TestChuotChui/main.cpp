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
    srand(177013);
    int n = rand()%20;
    int m = rand()%20;
    int s = rand()%40;
    int v = rand()%40;
    cout << n << " " << m << " " << s << " " << v << endl;
    for (int i=1; i<=n; i++){
        int a = rand()%1000;
        int b = rand()%10;
        if (!b) b = 1;
        cout << double(1.0*a/b) << " ";
        a = rand()%1000;
        b = rand()%10;
        if (!b) b = 1;
        cout << double(1.0*a/b) << " ";
        cout << endl;
    }
    for (int i=1; i<=m; i++){
        int a = rand()%1000;
        int b = rand()%10;
        if (!b) b = 1;
        cout << double(1.0*a/b) << " ";
        a = rand()%1000;
        b = rand()%10;
        if (!b) b = 1;
        cout << double(1.0*a/b) << " ";
        cout << endl;
    }
    return 0;
}
