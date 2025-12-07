#include <bits/stdc++.h>

using namespace std;

int t,n;
double x,y;

int main()
{
    freopen("DONGGIAY.INP","r",stdin);
    freopen("DONGGIAY.OUT","w",stdout);
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int k =0; k<t; k++){
        cin >> n;
        pair <double,int> a[n];
        for (int i=0; i<n; i++){
            cin >> x >> y;
            a[i].first = x/y;
            a[i].second = i+1;
        }
        sort(a,a+n);
        for (int i=0; i<n; i++){
            cout << a[i].second << " ";
        }
        cout << endl;
    }
    return 0;
}
