#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

const int maxn = 2e5+10;
const int INF = 2e9+100;

int n,m,k;
int a[maxn];
int b[maxn];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> n >> m >> k;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a, a+n);
    for (int i=0; i<m; i++){
        cin >> b[i];
    }
    sort(b, b+m);
    int j = 0;
    int cnt = 0;
    b[m] = INF;
    for (int i=0; i<n; i++){
        while (b[j] <= a[i]+k){
            if (b[j] >= a[i]-k){
                cnt++;
                j++;
                break;
            }
            j++;
        }
    }
    cout << cnt;
    return 0;
}
