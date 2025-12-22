#include <bits/stdc++.h>
#define int long long
#define N 100010

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n,m,t,fo[N],re[N];
vector<int> a;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    for (int tam = 1; tam<=t; tam++){
        cin >> n;
        a.push_back(0);
        for (int i=1; i<=n; i++){
            int x;
            cin >> x;
            a.push_back(x);
        }
        for (int i=0; i<=n; i++){
            fo[i] = 0;
            re[i] = 0;
        }
        fo[1] = 1;
        re[n] = 1;
        for (int i=2; i<n; i++){
            if (a[i]-a[i-1] < a[i+1] - a[i]){
                fo[i] = a[i+1] - a[i];
                re[i-1] = 1;
            }
            else{
                re[i-1] = a[i] - a[i-1];
                fo[i] = 1;
            }
        }
        for (int i=1; i<=n; i++){
            fo[i]=fo[i]+fo[i-1];
            re[i]=re[i]+re[i-1];
        }
        cin >> m;
        for (int i=1; i<=m; i++){
            int meow,woof;
            cin >> meow >> woof;
            if (meow < woof){
                cout << fo[woof-1] - fo[meow-1] << "\n";
            }
            else{
                cout << re[meow-1] - re[woof-1] << "\n";
            }
        }
    }
    return 0;
}
