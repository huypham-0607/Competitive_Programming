#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9;

int test;
int n,k;
int ans[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n >> k;
//        int cnt = 0;
        int l = 1;
        int r = n;
        for (int i=1; i<=k; i++){
            if (i%2){
                int j = i;
                while (j<=n){
                    ans[j] = r;
                    j+=k;
                    r--;
                }
            }
            else{
                int j = i;
                while (j<=n){
                    ans[j] = l;
                    j+=k;
                    l++;
                }
            }
        }
        for (int i=1; i<=n; i++){
            cout << ans[i] << " ";
        }
        cout << endl;
    }
    return 0;
}
