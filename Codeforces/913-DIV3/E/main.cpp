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
int val[20];

signed main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    for (int i=0; i<=9; i++){
        for (int j=0; j<=9; j++){
            for (int k=0; k<=9; k++){
                int meow = i+j+k;
                if (meow >= 0 && meow <=9){
                    val[meow]++;
                }
            }
        }
    }
//    for (int i=0; i<=9; i++){
//        cout << val[i] << endl;
//    }
    cin >> t;
    while (t--){
        cin >> n;
        ll ans = 1;
        while (n!=0){
            int idx = n%10;
            ans*=val[idx];
            n = n/10;
        }
        cout << ans << endl;
    }
    return 0;
}
