#include <iostream>

using namespace std;

int t,n,m,limit[100001],low,a,b;
long long unsigned dp;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> t;
    for (int k=0; k<t; k++){
        cin >> n >> m;
        for (int i=1; i<=n; i++){
            limit[i] = n+1;
        }

        for (int i=0; i<m; i++){
            cin >> a >> b;
            int mn = min(a,b);
            int mx = max(a,b);
            limit[mn] = min(limit[mn],mx);
        }

        low = n+1;
        for (int i=n; i>0; i--){
            low = min(low,limit[i]);
            limit[i] = low;
        }

        dp =0;
        for (int i =1; i<=n; i++){
            dp += limit[i] - i;
        }

        cout << dp << endl;
    }
    return 0;
}
