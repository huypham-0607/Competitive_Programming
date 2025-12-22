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
int a[maxn];

int check(int k){
//    cout << "[" << k << "]" << endl;
    int l = n/k;
    int res = 0;
    for (int i=1; i<=l; i++){
        int ans = 0;
        for (int j=0; j<k-1; j++){
            int x = a[j*l+i];
            int y = a[(j+1)*l+i];
            if (x<y) swap(x,y);
            int meow = x-y;
            if (ans == 0){
                ans = meow;
            }
            else ans = __gcd(ans,meow);
        }
//        cout << ans << " ";
        if (res == 0) res = ans;
        else res = __gcd(res,ans);
    }
//    cout << endl;
    if (res == 1) return 0;
    else return 1;
}

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        int ans = 1;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        if (n == 1){
            cout << 1 << endl;
            continue;
        }
        for (int i=2; i*i<=n; i++){
            if (n%i == 0){
                if (i*i == n){
                    ans += check(i);
                }
                else{
                    ans += check(i);
                    ans += check(n/i);
                }
            }
        }
        ans += check(n);
        cout << ans << endl;
    }
    return 0;
}
