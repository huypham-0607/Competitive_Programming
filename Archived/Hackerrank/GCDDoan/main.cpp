#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxlog = 21;
const int maxn = 1e6+10;
const int INF = 2e9;

int n,t;
int a[maxn];
int st[maxlog][maxn];
int lg[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    int t;
    cin >> t;
    for (int i=2; i<=1000000; i++){
        lg[i] = lg[i/2]+1;
    }
    while (t--){
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> a[i];
            a[i] = abs(a[i]);
            st[0][i] = a[i];
        }
        int k = lg[n];
        for (int i=1; i<=k; i++){
            for (int j=1; j<=n ;j++){
                if (j + (1<<i)-1 > n) break;
                st[i][j] = __gcd(st[i-1][j],st[i-1][j + (1<<(i-1))]);
            }
        }
        int ans = 0;
        int i=1;
        int j=1;
        while (j<=n){
            int l = lg[j-i+1];
            int meow = __gcd(st[l][i],st[l][j-((1<<l)-1)]);
            if (meow == 1){
                if (i == j){
                    ++i;
                    ++j;
                }
                else ++i;
            }
            else{
                ans = max(ans,j-i+1);
                j++;
            }
        }
        cout << ans << endl;
    }
    return 0;
}
