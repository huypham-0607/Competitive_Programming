#include <bits/stdc++.h>
#define endl "\n"
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e18;
int lg = 62;
int fib[maxn];
int n,test;

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    fib[0] = 1;
    fib[1] = 2;
    int temp = 2;
    while (fib[temp-1] + fib[temp-2] <= INF){
        fib[temp] = fib[temp-1] + fib[temp-2];
        ++temp;
    }
    cin >> test;
    while (test--){
        cin >> n;
            for (int j=temp-1; j>=0; j--){
                if (n>=fib[j]){
                    cout << j << endl;
                    break;
                }
            }
    }
    return 0;
}
