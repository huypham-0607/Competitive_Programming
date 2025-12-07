#include <bits/stdc++.h>
#define ll long long
#define ii pair<int,int>
#define fi first
#define se second

using namespace std;

int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    freopen("data.inp","r",stdin);
    freopen("data.out","w",stdout);
    int n,x;
    int a[int(1e4+69)];
    cin >> n >> x;
    for (int i=0; i<n; i++){
        cin >> a[i];
    }
    sort(a,a+n);
    int i=0, j=n-1;
    int sech = 0;
    while (i<=j){
        while (j > i && a[i]+a[j] > x){
            sech++;
            j--;
        }
        i++;
        j--;
        sech++;
    }
    cout << sech;
    return 0;
}
