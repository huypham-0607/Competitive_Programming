#include <bits/stdc++.h>
#define endl "\n"
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 1e9+7;

int test;
int n;
int a[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> test;
    while (test--){
        cin >> n;
        for (int i=1; i<=n; i++){
            cin >> a[i];
        }
        sort(a+1,a+n+1);
        a[n+1] = INF;
        int mid = (n+1)/2;
        int idx = mid;
        int c = 0;
        while (a[mid] == a[idx]){
            idx++;
            c++;
        }
        cout << c << endl;
    }
    return 0;
}
