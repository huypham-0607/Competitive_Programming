#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int t,n,a[10000];

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin >> t;
    while (t--){
        cin >> n;
        for(int i=0; i<n; i++){
            cin >> a[i];
        }
        sort(a,a+n);
        int t=0;
        for (int i=0; i<n/2; i++){
            t=t-a[i]+a[n-i-1];
        }
        cout << t << "\n";
    }
    return 0;
}
