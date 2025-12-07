#include <bits/stdc++.h>
#define endl "\n"
#define int unsigned long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int n;

int add[maxn];
int mul[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n >> q;
        int prev = 0;
        int c = 0;
        for (int i=1; i<=n; i++){
            int idx,x;
            cin >> idx >> x;
            if (idx == 1){
                if (prev!=1){
                    ++c;

                }
            }
        }
    }
    return 0;
}
